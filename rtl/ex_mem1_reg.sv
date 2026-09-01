// instruction fetch stage

// return the control signals, correct outputs (...)

module ex_mem1_reg (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        stall,
    
    // EX STAGE
    input logic [6:0]  opcode_ex,
    input logic [2:0]  funct3_ex,
    input logic [4:0]  rd_ex,
    input logic [11:0]  csr_reg_ex,
    input logic [31:0]  csr_data_ex,
    input logic [31:0]  csr_content_ex,
    input logic [31:0] pc_ex,
    input logic [31:0] pc_plus_4_ex,
    input logic        mem_w_ex, 
    input logic        reg_write_ex, 
    input logic        csr_write_ex, 
    input logic [2:0]  wb_sel_ex,
    input logic [31:0] alu_result_ex,
    input logic [31:0] imm_ex,
    input  logic        alu_zero_ex,
    input logic [31:0] rs2_data_ex,

    // MEM STAGE
    output logic [31:0] rs2_data_mem1,
    output logic [4:0]  rd_mem1,
    output logic [11:0]  csr_reg_mem1,
    output logic [31:0]  csr_data_mem1,
    output logic [31:0]  csr_content_mem1,
    output logic [31:0] pc_mem1,
    output logic [31:0] pc_plus_4_mem1,
    //output logic [31:0] lui_mem,
    output logic [31:0] imm_mem1,
    output logic [6:0]  opcode_mem1,
    output logic [2:0]  funct3_mem1,
    //output logic        mem_r_mem, 
    output logic        mem_w_mem1, 
    output logic        csr_write_mem1, 
    output logic        reg_write_mem1, 
    output logic [2:0]  wb_sel_mem1,
    output logic [31:0] alu_result_mem1,
    output  logic        alu_zero_mem1
);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin// rst_n is active low // if stall, we flush
            pc_mem1 <= '0;
            imm_mem1 <= '0;
            pc_plus_4_mem1 <= '0;
            rd_mem1 <= '0;
            csr_reg_mem1 <= '0;
            csr_data_mem1 <= '0;
            csr_content_mem1 <= '0;
            mem_w_mem1 <= '0;
            reg_write_mem1 <= '0;
            csr_write_mem1 <= '0;
            wb_sel_mem1 <= '0;
            opcode_mem1 <= '0;
            funct3_mem1 <= '0;
            alu_result_mem1 <= '0;
            alu_zero_mem1 <= '0;
            rs2_data_mem1 <= '0;
        end 
        else begin
            pc_mem1 <= pc_ex;
            pc_plus_4_mem1 <= pc_plus_4_ex;
            rd_mem1 <= rd_ex;
            csr_reg_mem1 <= csr_reg_ex;
            csr_data_mem1 <= csr_data_ex;
            csr_content_mem1 <= csr_content_ex;
            imm_mem1 <= imm_ex;
            funct3_mem1 <= funct3_ex;
            mem_w_mem1 <= mem_w_ex;
            opcode_mem1 <= opcode_ex;
            reg_write_mem1 <= reg_write_ex;
            csr_write_mem1 <= csr_write_ex;
            wb_sel_mem1 <= wb_sel_ex;
            alu_result_mem1 <= alu_result_ex;
            alu_zero_mem1 <= alu_zero_ex;
            rs2_data_mem1 <= rs2_data_ex;
        end

    end

endmodule