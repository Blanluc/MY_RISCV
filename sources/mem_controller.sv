// MEM CONTROLLER
`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
module mem_controller #(
    //parameter int unsigned DEPTH = 8224, // 32kb
    //parameter int unsigned DEPTH = 1024 ,
    parameter logic [31:0] BASE = 32'h00004000
    //parameter logic [31:0] BASE = 32'h00000000
    //parameter MEM_INIT_FILE = "rom.mem"
)(
    input logic clk,
    input logic rst_n,

    input logic uart_busy,
    output logic uart_tx_en,
    output logic [7:0] uart_data,

    input logic read_en,

    input logic set_mask,
    //input logic flush_id,
    //input logic stall,
    input logic [6:0] opcode,
    input logic [31:0] addr_in,
    input logic [2:0] funct3,
    input logic write_en_in, // write enable pretty much
    input logic [1:0] addr_lsb,
    input logic [31:0] pc,
    input logic [31:0] mem_data, // raw data recieved from mem, to be modified
    input logic [31:0] store_data_in, // raw data to be stored
    output logic [31:0] store_data, // data given to mem, to be written
    output logic [31:0] read_data, // modified data originally from mem
    output logic [31:0] dram_addr, // aadapted addr to be read by mem
    output logic [31:0] rom_addr, // aadapted addr to be read by mem
    //output logic [31:0] rom_instr,
    //output logic [31:0] instr,
    output logic write_en_out,
    //output logic read_en_out,
    output logic mem_stall

    // output logic [31:0]  bit_mask,
    // output logic [4:0]  shift_amt,
    // output logic sign_extend
);
    // Let's try sampling the mask
    logic [31:0]  bit_mask;
    logic [31:0]  bit_mask_prev;
    logic [31:0]  shifted_mask;
    logic [31:0]  dram_r_data_raw;
    logic [31:0] dram_r_data_next;
    logic [4:0]  shift_amt;
    logic [4:0]  shift_amt_prev;
    logic sign_extend;
    logic sign_extend_prev;

    assign dram_addr = (addr_in-BASE)>>2;
    assign rom_addr = (pc-BASE)>>2;
    assign shifted_mask = bit_mask >> shift_amt;
    assign dram_r_data_raw = (mem_data & bit_mask_prev) >> shift_amt_prev;

    //logic [31:0] raw_data;

    // IF WRTITE BYTE OR HALF, WE HAVE TO STALL EVERYTHING FOR A CYCLE
    typedef enum logic {
        NORMAL  = 1'b0,
        MASKED_WRITE
    } state_t;

    logic current_state;
    logic next_state;

    // IF WE ARE DOING A MASKED WRITE,
    // FIRST WE NEED A CYCLE TO READ THE CURRENT WORD
    // THEN MODIFY THE WORD
    // FINALLY, NEED ANOTHER CYCLE TO WRITE

    // Combinational logic block
    always_comb begin
        // Default assignment prevents latches
        next_state = current_state;

        case (current_state)
            NORMAL: begin
                if (write_en_in && bit_mask != 32'hFFFFFFFF)begin 
                    next_state = MASKED_WRITE;
                    mem_stall = 1;
                    write_en_out=0;
                end
                else begin
                    mem_stall = 0;
                    write_en_out=write_en_in;
                    next_state = NORMAL;

                end
            end
            MASKED_WRITE: begin
                next_state = NORMAL;
                write_en_out=1;
                mem_stall = 0;
            end
            default: begin
                next_state = NORMAL;
                write_en_out=write_en_in;
                mem_stall = 0;
            end
        endcase
    end

    logic [31:0] read_data_prev;

    //assign read_data = dram_r_data_next;
    always_comb begin
        if (read_en) begin
            read_data = dram_r_data_next;
        end else begin 
            read_data = read_data_prev;
        end
    end
    assign store_data = ((store_data_in << shift_amt) & bit_mask) | (mem_data & ~bit_mask);

    // Sequential logic block for state storage
    always_ff @(posedge clk) begin
        read_data_prev <= read_data;
        bit_mask_prev<=bit_mask;
        sign_extend_prev<=sign_extend;
        shift_amt_prev<=shift_amt;

        if (!rst_n) current_state <= NORMAL;  // Asynchronous reset to known state
        else        current_state <= next_state;
    end

    always_comb begin
        sign_extend = funct3[2];
        shift_amt = {3'b0, addr_lsb} << 3; // addr_lsb * 8 //HERE

        if (set_mask) begin
            case(funct3)
                3'b000: begin 
                    bit_mask = 32'h000000FF << shift_amt; // byte
                    sign_extend=1;
                end
                3'b100: begin 
                    bit_mask = 32'h000000FF << shift_amt; // byte
                    sign_extend=0;
                end
                3'b001: begin 
                    bit_mask = 32'h0000FFFF << shift_amt; // half
                    sign_extend=1;
                end
                3'b101: begin 
                    bit_mask = 32'h0000FFFF << shift_amt; // half
                    sign_extend=0;
                end
                3'b010: begin 
                    bit_mask = 32'hFFFFFFFF;               // word
                    sign_extend=0;
                end
                default: begin
                    bit_mask = 32'b0;
                    sign_extend=0;
                end
            endcase
        end
        else begin
            bit_mask = bit_mask_prev;
            sign_extend=sign_extend_prev;
        end
    end

    // always_comb begin
    //     case (sign_extend_prev)
    //         1 : begin 
    //             if (shifted_mask[15]) begin
    //                 dram_r_data_next = 32'(signed' (dram_r_data_raw[15:0]));
    //             end
    //             else if (shifted_mask[7] ) begin
    //                 dram_r_data_next = 32'(signed' (dram_r_data_raw[7:0]));
    //             end else begin
    //             dram_r_data_next = dram_r_data_raw;
    //             end
    //         end
    //         default : dram_r_data_next = dram_r_data_raw;
    //     endcase
    // end

    always_comb begin
    if (sign_extend_prev) begin
        case (bit_mask_prev >> shift_amt_prev)
            32'h000000FF: begin // Byte (LB)
                dram_r_data_next = {{24{dram_r_data_raw[7]}}, dram_r_data_raw[7:0]};
            end
            32'h0000FFFF: begin // Half-word (LH)
                dram_r_data_next = {{16{dram_r_data_raw[15]}}, dram_r_data_raw[15:0]};
            end
            default: dram_r_data_next = dram_r_data_raw;
        endcase
    end else begin
        dram_r_data_next = dram_r_data_raw;
    end
end

  // UART LOGIC
    integer write_counter;
    integer read_counter;
    
    // 55 characters x 8 bits
    reg [55*8-1:0] send_string;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            write_counter <= 0;
            read_counter  <= 0;
            uart_tx_en    <= 1'b0;
            uart_data     <= 8'h00;
            send_string   <= '0;
        end else begin
            // Deassert enable pulse by default
            uart_tx_en <= 1'b0;

            // 1. Memory Write Handling (Store string bytes forward MSB->LSB)
            if (addr_in == 32'h10000000 && write_en_in) begin
                // Reverse insertion bit position so %s prints correctly
                send_string[(54 - write_counter)*8 +: 8] <= store_data[7:0];
                write_counter <= write_counter + 1;
            end

            // 2. UART Transmission Handshake
            // Ensure uart_tx_en isn't active and uart_busy is LOW before sending
            if (!uart_busy && !uart_tx_en && (read_counter < write_counter) && (read_counter < 55)) begin
                
                uart_data    <= send_string[(54 - read_counter)*8 +: 8];
                uart_tx_en   <= 1'b1; // Single-cycle pulse
                read_counter <= read_counter + 1;
            end  
            
            // Reset buffer counters when transmission reaches boundary
            if (read_counter >= 55) begin
                write_counter <= 0;
                read_counter  <= 0;
            end
        end
    end



endmodule