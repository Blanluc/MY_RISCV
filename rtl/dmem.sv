// data memory
// will be initialized with 0

// TODO : lb, lh, sb, sh will have to expand.
// for now just try get basics working

module dmem #(
    parameter int unsigned DEPTH = 1024  // 4 kb
)(
    input  logic        clk,
    input  logic        write_en,
    input  logic [31:0] addr, // PC feeds straight in
    input  logic [31:0] w_data, // write
    output logic [31:0] r_data // read
);
    logic [31:0] mem [0:DEPTH-1];

    // initialize to 0
    initial begin
        for (int i=0;i<DEPTH;i++) begin
            mem[i]=32'b0;
        end
    end

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
    always_ff @(posedge clk) begin
        if (write_en) 
            mem[addr[11:2]]<=w_data;
    end

    assign r_data = mem[addr[11:2]];

endmodule