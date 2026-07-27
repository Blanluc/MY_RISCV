// main memory : Byte adressable
// will be initialized with 0

// TODO : lb, lh, sb, sh will have to expand.
// for now just try get basics working

// How to interact with dmem?

// PASS A MASK TO IT!

module main_mem #(
    parameter int unsigned DEPTH = 262144 , // 1MB
    parameter logic [31:0] BASE = 32'h00004000
    //localparam logic [31:0] BASE = 32'h00000000
)(
    input  logic        clk,
    //input  logic        stall,
    //input  logic        rom_en,
    input  logic        dram_write_en,

    input  logic [31:0] rom_addr, // PC feeds straight in
    input  logic [31:0] dram_addr,

    input  logic [31:0] dram_w_data, // write
    input  logic [31:0] dram_bit_mask, // dram

    //input  logic  is_unsigned, // use both as indicator and mask
    output logic [31:0] instr, // instr
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

    // $readmemh("hex_memory_file.mem", memory_array, [start_address], [end_address])

    //initial $readmemh("sw/rom.hex", mem, 32'h00000000, 32'h0FFFFFFF);

    // initialize to 0
    initial begin
        for (int i=0;i<DEPTH;i++) begin
            mem[i]=32'b0;
        end
        //$readmemh("sw/rom.hex", mem, 32'h00000000, 32'h0FFFFFFF);
        $readmemh("sw/rom.hex", mem);
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
    always_ff @(posedge clk) begin  
        if (dram_write_en) begin
            mem[(dram_addr-BASE)>>2] <= (dram_w_data & dram_bit_mask) | (mem[(dram_addr-BASE)>>2] & ~dram_bit_mask);
        end
    end

    logic [31:0] debug_mem_addr;
    assign debug_mem_addr = (dram_addr-BASE)>>2;
    assign instr = mem[(rom_addr-BASE)>>2];

    assign dram_r_data = (mem[(dram_addr-BASE)>>2] & dram_bit_mask);



endmodule