// instruction fetch stage

// return the control signals, correct outputs (...)

module ex_mem_reg (
    input  logic        clk,
    input  logic        rst_n,

    input  logic        stall,

    input logic [4:0]  rd_ex,
    input logic [31:0] pc_ex,
    //input logic        mem_r_ex, 
    input logic        mem_w_ex, 
    input logic        reg_write_ex, 
    input logic [2:0]  wb_sel_ex,
    input logic [31:0] alu_result_ex,

    //output logic [6:0] opcode_mem,
    output logic [4:0]  rd_mem,
    output logic [31:0] pc_mem,
    //output logic        mem_r_mem, 
    output logic        mem_w_mem, 
    output logic        reg_write_mem, 
    output logic [2:0]  wb_sel_mem,
    output logic [31:0] alu_result_mem
);

    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin// rst_n is active low // if stall, we flush
        pc_mem <= '0;
        rd_mem <= '0;
        //mem_r_mem <= '0;
        mem_w_mem <= '0;
        reg_write_mem <= '0;
        wb_sel_mem <= '0;
        alu_result_mem <= '0;
    end 
    // else if (stall) begin //
    //     pc_mem <= pc_ex;
    //     rd_mem <= rd_ex;
    //     //mem_r_mem <= mem_r_mem;
    //     mem_w_mem <= '0;
    //     reg_write_mem <= '0;
    //     wb_sel_mem <= wb_sel_mem;
    //     alu_result_mem <= '0;
    // end
    else begin
        pc_mem <= pc_ex;
        rd_mem <= rd_ex;
        //mem_r_mem <= mem_r_ex;
        mem_w_mem <= mem_w_ex;
        reg_write_mem <= reg_write_ex;
        wb_sel_mem <= wb_sel_ex;
        alu_result_mem <= alu_result_ex;
    end

    end

endmodule