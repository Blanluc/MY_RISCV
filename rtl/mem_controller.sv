// MEM CONTROLLER
`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
module mem_controller (
    input logic [6:0] opcode,
    input logic [2:0] funct3,
    //output logic [31:0]  alu_result, // alu result telling us where to store
    output logic [31:0]  bit_mask,
    output logic is_unsigned
);

    //logic [31:0] raw_data;
  

    always_comb begin

        is_unsigned=funct3[2];

        case(funct3)
        
        3'b000,3'b100 : bit_mask = 32'hFF; // byte

        3'b001,3'b101: bit_mask = 32'hFFFF; // half

        3'b010 : bit_mask = 32'hFFFFFFFF; // word

        default : bit_mask = 32'b0;
        
        endcase
        
    end


endmodule