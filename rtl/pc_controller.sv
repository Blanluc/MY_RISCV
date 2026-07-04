// PC CONTROLLER

// PC can take pc + 4 or imm

// this should control the mux

// JAL : rd= pc +4 ; pc+=imm

// I guess the pc + 4 will be computed by the alu while the imm will be sent to a mux where the pc incr is handled

// Wait no

// The pc + 4 will be passed between stage registers, so we use the allu to increment pc

// JAL / JALR must be able to store current pc

// i think this goes at the wb stage
`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
module pc_controller (
    // input  logic  stall, // this will be done in the pc module directly
    input  logic stall,
    input  logic alu_zero,
    input  logic [6:0] opcode, // to see if jump/branch insr
    input  logic [31:0] pc, // if stall
    input  logic [31:0] pc_plus_4, // if not stall
    input  logic [31:0] pc_jump, // when jump
    input  logic [31:0] alu_result, // if relative jump
    input  logic [31:0] imm, // if non relative jump  // it seems they re all relative except jalr but jalr comes from alu // wait mb not
    output logic [31:0] pc_next // maybe not a sel, maybe do it directly here
 
);

logic debug_jump;

    always_comb begin
        debug_jump =0;
        if(stall) begin
            pc_next = pc; // stall, pc stays the same
            debug_jump =0;
        end
        else if ((opcode == `OPCODE_BRANCH) & alu_zero) begin
            pc_next = alu_result;
            debug_jump =0;
        end
        else if (opcode == `OPCODE_JAL | opcode ==`OPCODE_JALR) begin
            pc_next = pc_jump + imm;
            $display("JUMPING TO: %d ",pc_next);
            $display("JUMPING TO: %h ",pc_next);
            $display("OPCODE: %b ",opcode);
            $display("PC: %h ",pc);
            $display("IMM: %h ",imm);
            debug_jump =1;
        end
        else pc_next = pc_plus_4;
    end     


endmodule