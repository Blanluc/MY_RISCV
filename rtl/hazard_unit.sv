// Handles Hazards

// can send nop
// checks for hazards
// stall, foreward etc...

// lets start with just regfile

// shift register with used regs
// if new instruction uses reg that is in shift reg : hazard
// must recognize when an op doesnt use or write to reg or mem

// how will it expand later?

// similar concept with memory ig, maybe use same shift reg

// if needed var was computed, forward else stall
// how do we stall? feed 0 to next stage and feed same stuff to curr stage
// freeze stage regs

// hazard unit goes in decode stage
// 

// what happens when stall

// pc stays the same

// conds : load

// See where we write to, and if we have to read it next

// 1) PUT REGISTER WE WRITE TO IN SHIFT REG
// 2) NEXT ITER, COMPARE WITH BOTH SOURCES WE READ FROM

// CONTROL UNIT
`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
module hazard_unit (
    input  logic        clk,
    input  logic        rst_n,

    input logic        reg_write, // detect if we modify reg

    input  logic [4:0] reg_addr, // each cycle gets a new one, shouuld be written to
    input  logic [4:0] src1,
    input  logic [4:0] src2,
    //output  logic [4:0] src1_q,
    //output  logic [4:0] src2_q,
    //output logic [3:0]  alu_op, // select op
    //input  logic        stall_d,
    output  logic       stall_q
    //output  logic        stall_mem_wb_q
);

    // shift reg, each reg represents a stage
    //logic [4:0] reg_addr_if_id;
    logic [4:0] reg_addr_ex;
    logic [4:0] reg_addr_mem;
    logic [4:0] reg_addr_wb;

    logic detect;

    logic toggle; // detect prev

    always_comb begin

        // RAW
    assign detect = (reg_addr != 0) &&
                    (src1 == reg_addr_ex || 
                    src1 == reg_addr_mem
                    || src2 == reg_addr_ex || 
                    src2 == reg_addr_mem );
                    //reg_addr == reg_addr_wb);

    assign stall_q = detect || toggle;

    end


    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            //reg_addr_if_id <= '0;
            reg_addr_ex <= '0;
            reg_addr_mem <= '0;
            reg_addr_wb <= '0;
            toggle  <= '0;

        end
        
        // TODO : also avoid if we are writing to x0 and other stuff like that

        else begin
            //reg_addr_if_id <= reg_addr;
            toggle  <= detect;
            reg_addr_ex  <= reg_addr; //stall_q ? '0 : reg_addr; 
            //reg_addr_ex <= reg_addr;
            reg_addr_mem <= reg_addr_ex;
            reg_addr_wb <= reg_addr_mem;
        end


    end


endmodule