// instruction fetch stage

// return the control signals, correct outputs (...)

module ex_wb_reg (
    input  logic        clk,
    input  logic        rst_n,
    input logic [4:0]  rd_ex,
    input logic [31:0] pc_ex,
    input logic        mem_r_ex, 
    input logic        mem_w_ex, 
    input logic        reg_write_ex, 
    input logic [2:0]  wb_sel_ex,
    input logic [31:0] alu_result_ex,

    //output logic [6:0] opcode_wb,
    output logic [4:0]  rd_wb,
    output logic [31:0] pc_wb,
    output logic        mem_r_wb, 
    output logic        mem_w_wb, 
    output logic        reg_write_wb, 
    output logic [2:0]  wb_sel_wb,
    output logic [31:0] alu_result_wb
);

    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin// rst_n is active low
        pc_wb <= '0;
        rd_wb <= '0;
        mem_r_wb <= '0;
        mem_w_wb <= '0;
        reg_write_wb <= '0;
        wb_sel_wb <= '0;
        alu_result_wb <= '0;
    end
    else begin
        pc_wb <= pc_ex;
        rd_wb <= rd_ex;
        mem_r_wb <= mem_r_ex;
        mem_w_wb <= mem_w_ex;
        reg_write_wb <= reg_write_ex;
        wb_sel_wb <= wb_sel_ex;
        alu_result_wb <= alu_result_ex;
    end

    end

endmodule