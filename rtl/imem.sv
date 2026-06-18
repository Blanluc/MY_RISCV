// instruction memory: IROM
// will be initialized with hex file

module imem #(
    parameter int unsigned DEPTH = 1024  // 4 kb
)(
    input  logic        clk,
    input  logic [31:0] addr, // PC feeds straight in
    output logic [31:0] instr // we return the instr
);
    logic [31:0] mem [0:DEPTH-1];

    initial $readmemh("program.hex", mem); // read hex data from txt file and load it into mem arr

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
    // 0x00000004 = 0000 0000 0000 0000 0000 0000 0000 01
    // 0x00000008 = 0000 0000 0000 0000 0000 0000 0000 10


    // word aligned read, drop bottom 2 bits
    always_ff @(posedge clk)
        instr <= mem[addr[11:2]];

endmodule