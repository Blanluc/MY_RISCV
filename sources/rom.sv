module rom#(
    parameter int unsigned DEPTH = 65536, // 32kb
    //parameter int unsigned DEPTH = 1024 ,
    //parameter logic [31:0] BASE = 32'h00004000,
    //parameter logic [31:0] BASE = 32'h00000000,
    parameter MEM_INIT_FILE = "rom.hex"
)(
    input logic clk,
    input logic [31:0] rom_addr,
    output logic [31:0] instr,
    input logic read_en
    );

    initial begin
        $readmemh(MEM_INIT_FILE, rom);
    end

    logic [31:0] rom [DEPTH-1:0];
    always_ff @(posedge clk ) begin
       if (read_en == 1'b1) begin
          instr <= rom[rom_addr];
       end
    end


endmodule