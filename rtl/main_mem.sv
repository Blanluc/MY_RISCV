// main memory : Byte adressable
// will be initialized with 0

// TODO : lb, lh, sb, sh will have to expand.
// for now just try get basics working

// How to interact with dmem?

// PASS A MASK TO IT!

module main_mem #(
    parameter int unsigned DEPTH = 262144 , // 1MB
    //parameter int unsigned DEPTH = 1024 ,
    parameter logic [31:0] BASE = 32'h00004000,
    //parameter logic [31:0] BASE = 32'h00000000,
    parameter MEM_INIT_FILE = "rom.hex"
)(
    input  logic        clk,
    input  logic        dram_write_en,

    input  logic [31:0] rom_addr, // PC feeds straight in
    input  logic [31:0] dram_addr,

    input  logic [4:0] shift_amt,
    input  logic sign_extend,

    input  logic [31:0] dram_w_data, // write
    input  logic [31:0] dram_bit_mask, // dram

    input logic flush_id,
    input logic stall,

    //input  logic  is_unsigned, // use both as indicator and mask
    output logic [31:0] instr, // instr
    output logic uart_tx_o,
    output logic [31:0] dram_r_data // data

);

    // ROM, RAM, I/O (1GB)
    // 0x0000 0000 ROM
    // .
    // 0x1000 0000 BOOT ROM
    // .
    // 0x2000 0000 RAM
    // .
    // 0x3FFF FFFF

    // MAPPED I/O (1GB)
    // 0x4000 0000
    // .
    // .
    // 0x7FFF FFFF

    // DRAM (2GB)
    // 0x8000 0000
    // .
    // .
    // 0xFFFF FFFF

    logic [31:0] mem [0:DEPTH-1];

    // UART SIGNAL
    logic uart_busy;
    logic [7:0] uart_data; // data
    logic uart_tx_en; // data
    logic write_toggle;
    logic rst;


    initial begin
        $readmemh(MEM_INIT_FILE, mem);

        // uart toggle signal
        write_toggle = 0;
        rst =1;
        
    end

    //logic [31:0] temp_data;

    // 1 byte = 8 bits
    // 1 word = 32 bits

    // EX
    // 1st instr : 0x00000000
    // instr = 32 b = 4 bytes
    // therefore :
    // 2nd instr : 0x00000004

    // If I do : mem[1], I want 0x00000004, not 0x00000001
    // 0x00000004 = 0000 0000 0000 0000 0000 0000 0000 0100
    // 0x00000008 = 0000 0000 0000 0000 0000 0000 0000 1000
    // (...)
    // So if we dropt the 2 bottom bits :
    // 0x00000004 = 0000 0000 0000 0000 0000 0000 0000 01 so each slot is 1 byte
    // 0x00000008 = 0000 0000 0000 0000 0000 0000 0000 10


    // word aligned, drop bottom 2 bits
    // always_ff @(posedge clk) begin  
    //     if (dram_write_en) begin
    //         mem[(dram_addr-BASE)>>2] <= (dram_w_data & dram_bit_mask) | (mem[(dram_addr-BASE)>>2] & ~dram_bit_mask);
    //     end
    // end

    localparam logic [31:0] UART_ADDR = 32'h10000000;
    logic dram_write_en_prev;

    // ADDED
    logic  msb;
    logic [31:0] dram_r_data_raw;
    logic [31:0] shifted_mask;
    logic [31:0] dram_r_data_next;

    assign shifted_mask = dram_bit_mask >> shift_amt;
    assign dram_r_data_raw = (mem[(dram_addr-BASE)>>2] & dram_bit_mask) >> shift_amt;


    always_comb begin
        case (sign_extend)
            1 : begin 
                if (shifted_mask[15]) begin
                    dram_r_data_next = 32'(signed' (dram_r_data_raw[15:0]));
                end
                else if (shifted_mask[7] ) begin
                    dram_r_data_next = 32'(signed' (dram_r_data_raw[7:0]));
                end else begin
                dram_r_data_next = dram_r_data_raw;
                end
            end
            default : dram_r_data_next = dram_r_data_raw;
        endcase
    end

    always_ff @(posedge clk) begin
        dram_write_en_prev <= dram_write_en;
        if (dram_write_en) begin
            if (dram_write_en && !dram_write_en_prev && dram_addr == UART_ADDR) begin
            $write("%c", dram_w_data[7:0]);
            end else begin
            mem[(dram_addr-BASE)>>2] <= ((dram_w_data << shift_amt) & dram_bit_mask) | (mem[(dram_addr-BASE)>>2] & ~dram_bit_mask);
            end
        end     

        // ADDED BEGIN
        if (flush_id) begin
            instr <= '0;
        end else if (stall) begin
            instr <= instr;
        end
        else begin
            instr <= mem[(rom_addr-BASE)>>2];
        end
        

        dram_r_data <= dram_r_data_next;
        //shifted_mask <= dram_bit_mask >> shift_amt;
        //dram_r_data_raw <= (mem[(dram_addr-BASE)>>2] & dram_bit_mask) >> shift_amt;

        
        // ADDED END


    end

/*
    //logic [31:0] debug_mem_addr;
    //assign debug_mem_addr = (dram_addr-BASE)>>2;
    assign instr = mem[(rom_addr-BASE)>>2];
    logic  msb;
    logic [31:0] dram_r_data_raw;
    logic [31:0] shifted_mask;
    assign shifted_mask = dram_bit_mask >> shift_amt;
    assign dram_r_data_raw = (mem[(dram_addr-BASE)>>2] & dram_bit_mask) >> shift_amt;

    
    always_comb begin
        case (sign_extend)
            1 : begin 
                if (shifted_mask[15]) begin
                    dram_r_data = 32'(signed' (dram_r_data_raw[15:0]));
                end
                else if (shifted_mask[7] ) begin
                    dram_r_data = 32'(signed' (dram_r_data_raw[7:0]));
                end else begin
                dram_r_data = dram_r_data_raw;
                end
            end
            default : dram_r_data = dram_r_data_raw;
        endcase
    end
    */
    // if signed => take msb




    // UART LOGIC

    // IF WRITE TO 0x1000 0000 : beginf transmission of 55 chars

    
    integer write_counter;
    integer read_counter;
    logic [31:0] uart_addr;
    logic [31:0] uart_addr_next;
    logic [1:0] uart_addr_lsb;
    logic [4:0] uart_shift_amt;
    logic [31:0] dram_r_data_raw_uart;
    
    assign uart_addr_lsb=uart_addr[1:0];
    assign uart_shift_amt={3'b0, uart_addr_lsb} << 3;
    assign dram_r_data_raw_uart = (mem[(uart_addr-BASE)>>2] & 32'h000000FF) >> uart_shift_amt;
    reg  [55*8-1:0] 	send_string;


    
    always_ff @(posedge clk) begin
        if (dram_addr == 32'h10000000 & dram_write_en) begin
            write_toggle <= 1; // INIT TRANSFER OF 55 CHARS
            send_string[write_counter*8 +: 8] <= dram_w_data[7:0];
            write_counter <= write_counter + 1;
        end 
        if (write_toggle==1 & uart_busy==0 & read_counter <= 55) begin
            read_counter <= read_counter + 1;
            uart_data <= send_string[read_counter*8 +: 8];
            uart_tx_en <= 1;
        end  
        else if (read_counter >= 55) begin
            //$display("STRING IN BUFF : %s",send_string);
            write_counter <= 0;
            read_counter <= 0;
            uart_addr <= 32'h10000000;
            uart_tx_en <= 0;
            write_toggle<=0;
        end
        else begin
            uart_tx_en <= 0;

        end
    end


uart_transmitter uart_transmitter(
        .clk  (clk),
        .rst (rst),
        .tx_data(uart_data),
        .tx_en(uart_tx_en),
        .tx_busy(uart_busy),
        .tx_o(uart_tx_o) 
    );


    



endmodule