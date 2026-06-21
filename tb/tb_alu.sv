
/* verilat --binary -j 0 --top tb_regfile -Irtl -Itb rtl/regfile.sv tb/tb_regfile.sv */

module tb_alu;

reg 	      clk;
logic [3:0]  operator;
logic [31:0] operand_a;
logic [31:0] operand_b;
logic [31:0] result;

alu alu (	
            .operator  (operator),
            .operand_a (operand_a),
            .operand_b (operand_b),
            .result (result)
			);

// TESTING ALL THE OPS
initial begin
    clk = 0;
    #10;
    #10 operator = ALU_ADD;
    operand_a = 16;
    operand_b = 10;
    #10 $display("OP=%b (ADD) OP1=%0d OP2=%0d RES=%0d", operator,operand_a, operand_b,result);
    #10 operator = ALU_SUB;
    operand_a = 16;
    operand_b = 10;
    #10 $display("OP=%b (SUB) OP1=%0d OP2=%0d RES=%0d", operator,operand_a, operand_b,result);
    #10 operator = ALU_XOR;
    operand_a = 7;
    operand_b = 10;
    #10 $display("OP=%b (XOR) OP1=%0b OP2=%0b RES=%0b", operator,operand_a, operand_b,result);
    #10 operator = ALU_OR;
    operand_a = 7;
    operand_b = 10;
    #10 $display("OP=%b (OR) OP1=%0b OP2=%0b RES=%0b", operator,operand_a, operand_b,result);
    #10 operator = ALU_AND;
    operand_a = 7;
    operand_b = 10;
    #10 $display("OP=%b (AND) OP1=%0b OP2=%0b RES=%0b", operator,operand_a, operand_b,result);
    #10 operator = ALU_SRA;
    operand_a = 7;
    operand_b = 2;
    #10 $display("OP=%b (SRA) OP1=%0b OP2=%0d RES=%0b", operator,operand_a, operand_b,result);
    #10 operator = ALU_SLL;
    operand_a = 7;
    operand_b = 2;
    #10 $display("OP=%b (SLL) OP1=%0b OP2=%0d RES=%0b", operator,operand_a, operand_b,result);
    #10 operator = ALU_SRL;
    operand_a = 7;
    operand_b = 2;
    #10 $display("OP=%b (SLR) OP1=%0b OP2=%0d RES=%0b", operator,operand_a, operand_b,result);
    #10 operator = ALU_SLT;
    operand_a = 1;
    operand_b = -1;
    #10 $display("OP=%b (SLT) OP1=%0b OP2=%0d RES=%0b", operator,operand_a, operand_b,result);
    #10 operator = ALU_SLTU;
    operand_a = 1;
    operand_b = -1;
    #10 $display("OP=%b (SLTU) OP1=%0b OP2=%0d RES=%0b", operator,operand_a, operand_b,result);
    $finish;
end


always #5 clk = ~clk;


endmodule