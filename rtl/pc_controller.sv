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
    input  logic [6:0] opcode_id, // to see if jump/branch insr
    input  logic [6:0] opcode_ex, // to see if jump/branch insr
    input  logic [31:0] pc, // if stall
    input  logic [31:0] pc_plus_4, // if not stall
    input  logic [31:0] pc_jump, // (pc from id stage for jumps)
    input  logic [31:0] pc_branch,
    input  logic [31:0] alu_result, // if branch
    input  logic [31:0] imm_id, // if non relative jump  // it seems they re all relative except jalr but jalr comes from alu // wait mb not
    input  logic [31:0] imm_ex,
    input  logic [31:0] rs1_data, // ADDED
    input  logic [31:0] lui_ex,
    output logic [31:0] pc_next, // maybe not a sel, maybe do it directly here
    output logic flush_ex,
    output logic flush_id
 
);

logic debug_jump;

    always_comb begin
        // $display("PC CONTROLLER : ");
        // $display("pc_in : %0h",pc);
        // $display("imm_id : %0d",imm_id);
        // $display("imm_ex : %0d",imm_ex);
        debug_jump =0;
        if(stall) begin
            pc_next = pc; // stall, pc stays the same
            flush_ex =0;
            flush_id =0;
            debug_jump =0;
        end
        else if (opcode_ex == `OPCODE_BRANCH && alu_zero) begin //opcode_id ==`OPCODE_JALR begin // determined at ex stage
        //$display("JALR!!");
        
            pc_next = pc_branch + imm_ex;
            //$display("PC NEXT : %0d",pc_next);
            flush_ex =1;
            flush_id =1;
            debug_jump =1;
        end
        // else if (opcode_ex == `OPCODE_AUIPC) begin // determined at id stage
        //     pc_next = pc_branch + lui_ex;
        //     debug_jump =1;
        //     flush_ex =1;
        //     flush_id =1;
        // end
        else if (opcode_id == `OPCODE_JAL) begin // determined at id stage
            pc_next = pc_jump + imm_id;
            debug_jump =1;
            flush_ex =0;
            flush_id =1;
        end
        else if (opcode_id == `OPCODE_JALR) begin // determined at id stage
        $display("PC NEXT (PC CTRL) : %0h",pc_next);
            pc_next = imm_id + rs1_data;
            debug_jump =1;
            flush_ex =0;
            flush_id =1;
        end
        else begin 
            pc_next = pc_plus_4;
            flush_ex =0;
            flush_id =0;
        end
    end     


endmodule