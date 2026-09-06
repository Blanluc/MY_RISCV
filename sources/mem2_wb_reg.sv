// instruction fetch stage

// return the control signals, correct outputs (...)

module mem2_wb_reg (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        mem_stall,

    input logic [4:0]  rd_mem2,
    input logic [11:0]  csr_reg_mem2,
    input logic [31:0]  csr_data_mem2,
    input logic [31:0]  csr_content_mem2,
    input logic [31:0] pc_mem2,
    input logic [31:0] imm_mem2,
    input logic [31:0] pc_plus_4_mem2,
    input logic        mem_w_mem2, 
    input logic        reg_write_mem2, 
    input logic        csr_write_mem2, 
    input logic [2:0]  wb_sel_mem2,
    input logic [31:0] alu_result_mem2,
    input logic alu_zero_mem2,
    input logic [31:0] r_data_mem2,

    //output logic [6:0] opcode_wb,
    output logic [4:0]  rd_wb,
    output logic [11:0]  csr_reg_wb,
    output logic [31:0]  csr_data_wb,
    output logic [31:0]  csr_content_wb,
    output logic [31:0] pc_wb,
    output logic [31:0] pc_plus_4_wb,
    output logic [31:0] imm_wb, 
    output logic        mem_w_wb, 
    output logic        reg_write_wb, 
    output logic        csr_write_wb, 
    output logic [2:0]  wb_sel_wb,
    output logic [31:0] r_data_wb,
    output logic [31:0] alu_result_wb,
    output logic alu_zero_wb
);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin// rst_n is active low
            pc_wb <= '0;
            pc_plus_4_wb <= '0;
            rd_wb <= '0;
            csr_reg_wb <= '0;
            csr_data_wb <= '0;
            csr_content_wb <= '0;
            imm_wb <= '0;
            mem_w_wb <= '0;
            reg_write_wb <= '0;
            csr_write_wb <= '0;
            wb_sel_wb <= '0;
            r_data_wb <= '0;
            alu_result_wb <= '0;
            alu_zero_wb <= '0;
        end 
        else begin
            pc_wb <= pc_mem2;
            pc_plus_4_wb <= pc_plus_4_mem2;
            rd_wb <= rd_mem2;
            csr_reg_wb <= csr_reg_mem2;
            csr_data_wb <= csr_data_mem2;
            csr_content_wb <= csr_content_mem2;
            imm_wb <= imm_mem2;
            mem_w_wb <= mem_w_mem2;
            reg_write_wb <= reg_write_mem2;
            csr_write_wb <= csr_write_mem2;
            wb_sel_wb <= wb_sel_mem2;
            r_data_wb <= r_data_mem2;
            alu_result_wb <= alu_result_mem2;
            alu_zero_wb <= alu_zero_mem2;
        end

    end

endmodule