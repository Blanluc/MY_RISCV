// register file
import pkg::*;
module alu (
    input  logic [3:0]  operator,
    input  logic [31:0] operand_a,
    input  logic [31:0] operand_b,
    output logic [31:0] result
);

    //Just do all the ops and mux at end depending on op
    // 32 bit signed
    
    logic [31:0]  add_output;
    logic [31:0]  sub_output;
    logic [31:0]  xor_output;
    logic [31:0]  or_output;
    logic [31:0]  and_output;
    logic [31:0]  sra_output;
    logic [31:0]  sll_output;
    logic [31:0]  srl_output;
    logic [31:0]  slt_output;
    logic [31:0]  sltu_output;
    

    //logic [31:0]  operand_b_negate;

    //assign operand_b_negate = !operand_b + 1'b1;

    // NOTE : default is unsigned, but for things like add and sub it doesnt matter

    // ADD
    assign add_output = operand_a + operand_b;
    // SUB
    assign sub_output = operand_a - operand_b;

    // XOR
    assign xor_output = operand_a ^ operand_b;
    // OR
    assign or_output = operand_a | operand_b;
    // AND
    assign and_output = operand_a & operand_b;

    //Shifts : RISC V isa only uses 5 lower bits of src2

    // SRA
    assign sra_output = $signed(operand_a) >>> (operand_b[4:0]);
    // SLL
    assign sll_output = operand_a << (operand_b & 32'b11111);
    // SRL
    assign srl_output = operand_a >> (operand_b & 32'b11111);

    // Comparsions
    // SLT
    assign slt_output = {31'b0, $signed(operand_a) < $signed(operand_b)}; // concatenation
    // SLTU
    // TODO (but I think its already ok) : If comparing x0 and rs2, if rs2 is != 0, then res is 1
    assign sltu_output = {31'b0, operand_a < operand_b}; // concatenation


    // Im not sure about if its signed or unsigned so for now im doing signed

    // Representation :
    // Lets use 4 bit example
    // 0111 + 0001 = 1000 => 7+1 = 1000 = -8
    // 1111 => -(0001) = -1 (overflow)
    // 1001 => -(0111) = -7
    // we cover from -8 to 7

    // How to implement?

    // Adding a negative to a positive and vice versa
    // 0001 + 1011 (1 + (-5)) = 1100 = !(1011)= 0100 = 4 
    // Nothing to do, works ok

    // Adding two negatives
    // 1111 + 1011 (-1 + (-5)) = (1)1010 => (-)!(1001)=0110= -6
    // Nothing to do, works ok


    // TODO: MAYBE FIND TRICKS TO MAKE THINGS FASTER


    always_comb begin

        case(operator)

        ALU_ADD    : result = add_output;
        ALU_SUB    : result = sub_output;

        ALU_XOR        : result = xor_output;
        ALU_OR         : result = or_output;
        ALU_AND        : result = and_output;

        ALU_SRA        : result = sra_output;
        ALU_SLL        : result = sll_output;
        ALU_SRL        : result = srl_output;

        ALU_SLT        : result = slt_output;
        ALU_SLTU       : result = sltu_output;

        default    : result = add_output;
        endcase
    
        
    end

  

endmodule