// register file
`include "headers/alu_ops.svh"
module alu (
    input  logic [3:0]  operator,
    input  logic [31:0] operand_a, // can be PC!
    input  logic [31:0] operand_b,
    output logic [31:0] result, 
    output logic [31:0] csr_data, 
    output logic alu_zero // branch
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
    logic [31:0]  andn_output;

    logic alu_zero_slt;
    logic alu_zero_sltu;
    logic alu_zero_and;

    // TODO : How to handle NOP?
    

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

    assign andn_output = operand_a & (~operand_b);

    //Shifts : RISC V isa only uses 5 lower bits of src2

    // SRA
    assign sra_output = $signed(operand_a) >>> (operand_b[4:0]);
    // SLL
    assign sll_output = operand_a << (operand_b & 32'b11111);
    // SRL
    assign srl_output = operand_a >> (operand_b & 32'b11111);

    // Comparsions
    // SLT (Set if Less Than)
    assign slt_output = {31'b0, $signed(operand_a) < $signed(operand_b)}; // concatenation
    // SLTU
    // TODO (but I think its already ok) : If comparing x0 and rs2, if rs2 is != 0, then res is 1
    assign sltu_output = {31'b0, operand_a < operand_b}; // concatenation


    assign csr_data = operand_a; // csr



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

        `ALU_ADD    : begin
            result = add_output;
            alu_zero = '0;
        end
        `ALU_SUB    : begin
            result = sub_output;
            alu_zero = sub_output == '0; // 1 if 0, 0 if not
        end


        `ALU_XOR        : begin
            result = xor_output;
            alu_zero = '0;
        end
        `ALU_OR         : begin
            result = or_output;
            alu_zero = '0;
        end
        `ALU_AND        : begin
            result = and_output;
            alu_zero = '0;
        end


        `ALU_SRA        : begin
            result = sra_output;
            alu_zero = '0;
        end
        `ALU_SLL        : begin
            result = sll_output;
            alu_zero = '0;
        end
        `ALU_SRL        : begin
            result = srl_output;
            alu_zero = '0;
        end

        `ALU_SLT        : begin
            result = slt_output;
            alu_zero = slt_output[0]; // BLT, BGE
        end
        `ALU_SLTU       : begin
            result = sltu_output;
            alu_zero = sltu_output[0]; // BLTU, BGEU
        end

        `ALU_ANDN        : begin
            result = andn_output;
            alu_zero = '0;
        end

        default    : begin
            result = add_output;
            alu_zero = '0;
        end
        endcase
    
        
    end

  

endmodule