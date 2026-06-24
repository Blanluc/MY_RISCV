// CONTROL UNIT
`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
module alu_controller (
    input logic [6:0] opcode,
    input logic [2:0] funct3,
    input logic [6:0] funct7,
    output logic [3:0]  alu_op // select op
);

    always_comb begin

        case(opcode)

        // IS there easy way to merge Imm ops and R ops

        // Only way to diff add and sub is with funct7

        // do case with IMM
        `OPCODE_RTYPE,`OPCODE_ITYPE: begin

            case(funct3)
            
            3'b000 : begin // ADD or SUB
                case(opcode)
                    `OPCODE_RTYPE : begin
                        case(funct7)
                            7'b0000000 : alu_op=`ALU_ADD; // ADD
                            7'b0100000 : alu_op=`ALU_SUB; // SUB
                            default : alu_op=`ALU_ADD;
                        endcase
                    end
                    default : alu_op=`ALU_ADD; // no sub if IMM
                endcase
            end

            3'b001 :  alu_op=`ALU_SLL; // SLL

            3'b010 :  alu_op=`ALU_SLT; // SLT

            3'b011 :  alu_op=`ALU_SLTU; // SLTU

            3'b100 :  alu_op=`ALU_XOR; // XOR

            3'b101 : begin // SRL or SRA
                case(funct7)
                    7'b0000000 : alu_op=`ALU_SRL; // SRL
                    7'b0100000 : alu_op=`ALU_SRA; // SRA
                    default    : alu_op = `ALU_SRL;
                endcase
            end

            3'b110 :  alu_op=`ALU_OR; // OR

            3'b111 :  alu_op=`ALU_AND; // AND

            endcase
        end

        `OPCODE_AUIPC: alu_op=`ALU_SLL;

        // todo : for LUI no operation is done as the shift is already done

        // The branch controller will check sign and decide
        `OPCODE_BRANCH : begin
            // TODO: branch stuff
            // depending on branch condition we will need one op or the other
            // i feel that for any comparsion we can work with (SUB), but then we also need other stuff
            // i think a part of the job will also be done by the branch control thingy

            // how can i do compasions without needing multiple ops?
            // I think I can just use slt and sltu
            
            case(funct3)
            3'b000, 3'b001 : alu_op=`ALU_AND; // branch == & branch !=
            3'b100, 3'b101 : alu_op=`ALU_SLT; // 
            3'b110, 3'b111 : alu_op=`ALU_SLTU; // 
            default : alu_op=`ALU_AND; // TODO : not sure

            endcase


        end

        
        
        default : alu_op=`ALU_ADD;
        

        
         
        endcase  
    end


endmodule