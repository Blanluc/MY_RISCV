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

// what happens when stall

// pc stays the same

// conds : load

// See where we write to, and if we have to read it next

// 1) PUT REGISTER WE WRITE TO IN SHIFT REG
// 2) NEXT ITER, COMPARE WITH BOTH SOURCES WE READ FROM

`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
module hazard_unit (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        mem_stall,

    input logic        reg_write, // detect if we modify reg
    input logic        csr_write, // detect if we modify csr

    input  logic [4:0] rd, // each cycle gets a new one, shouuld be written to
    input  logic [11:0] csr,
    input  logic [4:0] src1,
    input  logic [4:0] src2,

    output  logic       stall
);

// shift reg, each reg represents a stage
// Track destinations of instructions
logic [4:0] rd_ex;
logic [4:0] rd_mem1;
logic [4:0] rd_mem2;
logic        rw_ex;
logic        rw_mem1;
logic        rw_mem2;
logic [4:0] rd_wb;
logic       rw_wb;

logic [11:0] csr_ex;
logic [11:0] csr_mem1;
logic [11:0] csr_mem2;
logic        csr_write_ex;
logic        csr_write_mem1;
logic        csr_write_mem2;
logic [11:0] csr_wb;
logic       csr_write_wb;

// SHIFT REGISTER
// A REG CAN BE READ OR WRITTEN IF NOT IN THE SHIFT REG
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        rd_ex  <= '0; rd_mem1 <= '0; rd_mem2 <= '0; rd_wb  <= '0;
        rw_ex  <= '0; rw_mem1 <= '0; rw_mem2 <= '0; rw_wb  <= '0;
        csr_ex  <= '0; csr_mem1 <= '0; csr_mem2 <= '0; csr_wb  <= '0;
        csr_write_ex  <= '0; csr_write_mem1 <= '0; csr_write_mem2 <= '0; csr_write_wb  <= '0;
    end else begin
        rd_ex  <= stall ? 5'b0 : rd;
        rw_ex  <= stall ? 1'b0 : reg_write;
        rd_mem1 <= rd_ex;
        rw_mem1 <= rw_ex;
        rd_mem2 <= rd_mem1;
        rw_mem2 <= rw_mem1;
        rd_wb  <= rd_mem2;
        rw_wb  <= rw_mem2;

        csr_ex  <= stall ? 12'b0 : csr;
        csr_write_ex  <= stall ? 1'b0 : csr_write;
        csr_mem1 <= csr_ex;
        csr_mem2 <= csr_mem1;
        csr_write_mem1 <= csr_write_ex;
        csr_write_mem2 <= csr_write_mem1;
        csr_wb  <= csr_mem2;
        csr_write_wb  <= csr_write_mem2;
    end
end

// SET STALL TO AVOID DEPENDENCY VIOLATION
always_comb begin
    stall = 1'b0;
    if (rw_ex  && (rd_ex  != 5'b0) && (src1 == rd_ex  || src2 == rd_ex))  stall = 1'b1;
    if (rw_mem1 && (rd_mem1 != 5'b0) && (src1 == rd_mem1 || src2 == rd_mem1)) stall = 1'b1;
    if (rw_mem2 && (rd_mem2 != 5'b0) && (src1 == rd_mem2 || src2 == rd_mem2)) stall = 1'b1;
    if (rw_wb  && (rd_wb  != 5'b0) && (src1 == rd_wb  || src2 == rd_wb))  stall = 1'b1;

    if (csr_write_ex  && (csr == csr_ex))  stall = 1'b1;
    if (csr_write_mem1 && (csr == csr_mem1)) stall = 1'b1;
    if (csr_write_mem2 && (csr == csr_mem2)) stall = 1'b1;
    if (csr_write_wb  && (csr == csr_wb))  stall = 1'b1;

    if (mem_stall) stall = 1'b1;
end


endmodule