
/* verilat --binary -j 0 --top tb_regfile -Irtl -Itb rtl/regfile.sv tb/tb_regfile.sv */

module tb_decoder;

reg 	      clk;
logic [31:0]  instr;
logic [6:0]  opcode;
logic [4:0]  rd;
logic [2:0]  funct3;
logic [6:0]  funct7;
logic [4:0]  rs1;
logic [4:0]  rs2;
logic [31:0] imm;

decoder decoder (	
            .instr  (instr),
            .opcode (opcode),
            .rd (rd),
            .funct3 (funct3),
            .funct7 (funct7),
            .rs1 (rs1),
            .rs2 (rs2),
            .imm (imm)
			);

// TESTING
initial begin
    clk = 0;
    #10;
    #10 instr = 32'h00B50533;
    #10 $display("OPCODE=%b RD=%d funct3=%b funct7=%b RS1=%d RS2=%d IMM=%0d", decoder.opcode,decoder.rd, decoder.funct3,decoder.funct7,decoder.rs1,decoder.rs2,decoder.imm);

    #10 instr = 32'h00155513;
    #10 $display("OPCODE=%b RD=%d funct3=%b funct7=%b RS1=%d RS2=%d IMM=%0d", decoder.opcode,decoder.rd, decoder.funct3,decoder.funct7,decoder.rs1,decoder.rs2,decoder.imm);

    #10 instr = 32'h0C0000EF;
    #10 $display("OPCODE=%b RD=%d funct3=%b funct7=%b RS1=%d RS2=%d IMM=%0d", decoder.opcode,decoder.rd, decoder.funct3,decoder.funct7,decoder.rs1,decoder.rs2,decoder.imm);

    #10 instr = 32'h00010117;
    #10 $display("OPCODE=%b RD=%d funct3=%b funct7=%b RS1=%d RS2=%d IMM=%0d", decoder.opcode,decoder.rd, decoder.funct3,decoder.funct7,decoder.rs1,decoder.rs2,decoder.imm);

    $finish;
end


always #5 clk = ~clk;


endmodule