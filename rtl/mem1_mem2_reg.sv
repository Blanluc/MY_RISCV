// instruction fetch stage

// return the control signals, correct outputs (...)

module mem1_mem2_reg (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        stall,

    // MEM 1 STAGE
    input logic [31:0] rs2_data_mem1,
    input logic [4:0]  rd_mem1,
    input logic [11:0]  csr_reg_mem1,
    input logic [31:0]  csr_data_mem1,
    input logic [31:0]  csr_content_mem1,
    input logic [31:0] pc_mem1,
    input logic [31:0] pc_plus_4_mem1,
    //input logic [31:0] lui_mem,
    input logic [31:0] imm_mem1,
    input logic [6:0]  opcode_mem1,
    input logic [2:0]  funct3_mem1,
    //input logic        mem_r_mem, 
    input logic        mem_w_mem1, 
    input logic        csr_write_mem1, 
    input logic        reg_write_mem1, 
    input logic [2:0]  wb_sel_mem1,
    input logic [31:0] alu_result_mem1,
    input  logic        alu_zero_mem1,
    

    // MEM 2 STAGE
    output logic [31:0] rs2_data_mem2,
    output logic [4:0]  rd_mem2,
    output logic [11:0]  csr_reg_mem2,
    output logic [31:0]  csr_data_mem2,
    output logic [31:0]  csr_content_mem2,
    output logic [31:0] pc_mem2,
    output logic [31:0] pc_plus_4_mem2,
    //output logic [31:0] lui_mem,
    output logic [31:0] imm_mem2,
    output logic [6:0]  opcode_mem2,
    output logic [2:0]  funct3_mem2,
    //output logic        mem_r_mem, 
    output logic        mem_w_mem2, 
    output logic        csr_write_mem2, 
    output logic        reg_write_mem2, 
    output logic [2:0]  wb_sel_mem2,
    output logic [31:0] alu_result_mem2,
    output  logic        alu_zero_mem2
);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin// rst_n is active low // if stall, we flush
            pc_mem2 <= '0;
            imm_mem2 <= '0;
            pc_plus_4_mem2 <= '0;
            rd_mem2 <= '0;
            csr_reg_mem2 <= '0;
            csr_data_mem2 <= '0;
            csr_content_mem2 <= '0;
            mem_w_mem2 <= '0;
            reg_write_mem2 <= '0;
            csr_write_mem2 <= '0;
            wb_sel_mem2 <= '0;
            opcode_mem2 <= '0;
            funct3_mem2 <= '0;
            alu_result_mem2 <= '0;
            alu_zero_mem2 <= '0;
            rs2_data_mem2 <= '0;
        end 
        else begin
            pc_mem2 <= pc_mem1;
            pc_plus_4_mem2 <= pc_plus_4_mem1;
            rd_mem2 <= rd_mem1;
            csr_reg_mem2 <= csr_reg_mem1;
            csr_data_mem2 <= csr_data_mem1;
            csr_content_mem2 <= csr_content_mem1;
            imm_mem2 <= imm_mem1;
            funct3_mem2 <= funct3_mem1;
            mem_w_mem2 <= mem_w_mem1;
            opcode_mem2 <= opcode_mem1;
            reg_write_mem2 <= reg_write_mem1;
            csr_write_mem2 <= csr_write_mem1;
            wb_sel_mem2 <= wb_sel_mem1;
            alu_result_mem2 <= alu_result_mem1;
            alu_zero_mem2 <= alu_zero_mem1;
            rs2_data_mem2 <= rs2_data_mem1;
        end

    end

endmodule