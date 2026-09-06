// BRANCH UNIT

// PC can take pc + 4 or imm

// this should control the mux

// JAL : rd= pc +4 ; pc+=imm

// I guess the pc + 4 will be computed by the alu while the imm will be sent to a mux where the pc incr is handled

// Wait no

// The pc + 4 will be passed between stage registers, so we use the allu to increment pc

// JAL / JALR must be able to store current pc
`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
module branch_unit (
    input  logic  alu_zero_in, // if takes branch or not
    input  logic [6:0] opcode,
    //input  logic [31:0] pc,
    //input  logic [19:0] imm, // fir now keave like like this. I think it will output like a mux signal
    input logic [2:0] funct3,
    output  logic  alu_zero_out
 
);

logic  alu_zero_bne;
logic  alu_zero_beq;
logic  alu_zero_blt;
logic  alu_zero_bltu;
logic  alu_zero_bge;
logic  alu_zero_bgeu;

assign alu_zero_bne=alu_zero_in;
assign alu_zero_beq=alu_zero_in;
assign alu_zero_blt=alu_zero_in;
assign alu_zero_bge=~alu_zero_in;
assign alu_zero_bltu=alu_zero_in;
assign alu_zero_bgeu=~alu_zero_in;

    always_comb begin

        case(opcode)

        // Load <=> read from d mem
        `OPCODE_BRANCH : begin
            case(funct3)
            3'b000, 3'b100, 3'b110 : alu_zero_out = alu_zero_in;
            default : alu_zero_out = ~alu_zero_in;

            endcase

        end
        default : alu_zero_out = 0;
            
        endcase  
    end


endmodule