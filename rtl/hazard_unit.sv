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

    input  logic [4:0] rd, // each cycle gets a new one, shouuld be written to
    input  logic [4:0] src1,
    input  logic [4:0] src2,
    //output  logic [4:0] src1_q,
    //output  logic [4:0] src2_q,
    //output logic [3:0]  alu_op, // select op
    //input  logic        stall_d,
    output  logic       stall
    //output  logic        stall_mem_wb_q
);

// shift reg, each reg represents a stage
//logic [4:0] reg_addr_if_id;
// Track destinations of instructions
logic [4:0] rd_ex;
logic [4:0] rd_mem;
logic        rw_ex;
logic        rw_mem;
logic [4:0] rd_wb;
logic       rw_wb;

always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        rd_ex  <= '0; rd_mem <= '0; rd_wb  <= '0;
        rw_ex  <= '0; rw_mem <= '0; rw_wb  <= '0;
    end else begin
        rd_ex  <= stall ? 5'b0 : rd;
        rw_ex  <= stall ? 1'b0 : reg_write;
        rd_mem <= rd_ex;
        rw_mem <= rw_ex;
        rd_wb  <= rd_mem;
        rw_wb  <= rw_mem;
    end
end

always_comb begin
    stall = 1'b0;
    if (rw_ex  && (rd_ex  != 5'b0) && (src1 == rd_ex  || src2 == rd_ex))  stall = 1'b1;
    if (rw_mem && (rd_mem != 5'b0) && (src1 == rd_mem || src2 == rd_mem)) stall = 1'b1;
    if (rw_wb  && (rd_wb  != 5'b0) && (src1 == rd_wb  || src2 == rd_wb))  stall = 1'b1;
end


endmodule