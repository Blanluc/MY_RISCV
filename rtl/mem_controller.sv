// MEM CONTROLLER
`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
module mem_controller (
    input logic [6:0] opcode,
    input logic [2:0] funct3,
    input logic [1:0] addr_lsb, 
    //output logic [31:0]  alu_result, // alu result telling us where to store
    output logic [31:0]  bit_mask,
    output logic [4:0]  shift_amt,
    output logic sign_extend
);

    //logic [31:0] raw_data;
  

    always_comb begin
        sign_extend = funct3[2];
        shift_amt = {3'b0, addr_lsb} << 3; // addr_lsb * 8

        case(funct3)
            3'b000: begin 
                bit_mask = 32'h000000FF << shift_amt; // byte
                sign_extend=1;
            end
            3'b100: begin 
                bit_mask = 32'h000000FF << shift_amt; // byte
                sign_extend=0;
            end
            3'b001: begin 
                bit_mask = 32'h0000FFFF << shift_amt; // half
                sign_extend=1;
            end
            3'b101: begin 
                bit_mask = 32'h0000FFFF << shift_amt; // half
                sign_extend=0;
            end
            3'b010: begin 
                bit_mask = 32'hFFFFFFFF;               // word
                sign_extend=0;
            end
            default: begin
                bit_mask = 32'b0;
                sign_extend=0;
            end
        endcase
    end


endmodule