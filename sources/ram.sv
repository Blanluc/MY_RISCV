module ram#(
    parameter int unsigned DEPTH = 65536, // 256kb
    //parameter int unsigned DEPTH = 262144,
    //parameter int unsigned DEPTH = 1024 ,
    //parameter logic [31:0] BASE = 32'h00004000,
    //parameter logic [31:0] BASE = 32'h00000000,
    parameter MEM_INIT_FILE = "rom.hex"
)(
    // JUST READS/ WRITES MEMORY
    // KEEP AS SIMPLE AS POSSIBLE
    // MUST BE ASSIGNED TO BRAM IN VIVADO

    // ALSO TAKE CARE OF BASE AND EVERYTHING IN CONTROLLER

    // IF :
    // LOAD BITE : JUST LOAD WORD AND DO MASKING IN MEM CONTROLLER
    // STORE BYTE : ADDS CYCLES! FIRST WE READ, THEN DO THE MASKING IN CONTROLLER, THEN WRITE

    input logic clk,
    input logic [31:0] w_addr,
    input logic [31:0] w_data,
    input logic [31:0] r_addr,
    input logic write_en,
    input logic read_en,

    output logic [31:0] r_data
    );

    initial begin
        $readmemh(MEM_INIT_FILE, ram);
    end

    logic [31:0] ram [DEPTH-1:0];
    always @(posedge clk) begin
       if (write_en == 1'b1) begin
	      ram[w_addr] <= w_data;
       end
       if (read_en == 1'b1) begin
          r_data <= ram[r_addr];
       end
    end


endmodule