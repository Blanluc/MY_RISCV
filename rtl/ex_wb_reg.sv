// instruction fetch stage

// return the control signals, correct outputs (...)

module ex_wb_reg (
    input  logic        clk,
    input  logic        rst_n,
    //input logic [6:0] opcode_ex,
    input logic [4:0]  rd_ex,
    //input logic [2:0]  funct3_ex,
    //input logic [6:0]  funct7_ex,
    //input logic [4:0]  rs1_ex,
    //input logic [4:0]  rs2_ex,
    //input logic [31:0] imm_ex,
    input logic [31:0] pc_ex,
    input logic        mem_r_ex, 
    input logic        mem_w_ex, 
    //input logic        rs2_sel_ex,
    //input logic        rs1_sel_ex,
    input logic        reg_write_ex, 
    input logic [2:0]  wb_sel_ex,
    input logic [31:0] alu_result_ex,

    //output logic [6:0] opcode_wb,
    output logic [4:0]  rd_wb,
    //output logic [2:0]  funct3_wb,
    //output logic [6:0]  funct7_wb,
    //output logic [4:0]  rs1_wb,
    //output logic [4:0]  rs2_wb,
    //output logic [31:0] imm_wb,
    output logic [31:0] pc_wb,
    output logic        mem_r_wb, 
    output logic        mem_w_wb, 
    //output logic        rs2_sel_wb,
    //output logic        rs1_sel_wb,
    output logic        reg_write_wb, 
    output logic [2:0]  wb_sel_wb,
    output logic [31:0] alu_result_wb
);

    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin// rst_n is active low
        pc_wb <= '0;
        //opcode_wb <= '0;
        rd_wb <= '0;
        //funct3_wb <= '0;
        //funct7_wb <= '0;
        //rs1_wb <= '0;
        //rs2_wb <= '0;
        //imm_wb <= '0;
        mem_r_wb <= '0;
        mem_w_wb <= '0;
        //rs2_sel_wb <= '0;
        //rs1_sel_wb <= '0;
        reg_write_wb <= '0;
        wb_sel_wb <= '0;
        alu_result_wb <= '0;
    end
    else begin
        pc_wb <= pc_ex;
        //opcode_wb <= opcode_ex;
        rd_wb <= rd_ex;
        //funct3_wb <= funct3_ex;
        //funct7_wb <= funct7_ex;
        //rs1_wb <= rs1_ex;
        //rs2_wb <= rs2_ex;
        //imm_wb <= imm_ex;
        mem_r_wb <= mem_r_ex;
        mem_w_wb <= mem_w_ex;
        //rs2_sel_wb <= rs2_sel_ex;
        //rs1_sel_wb <= rs1_sel_ex;
        reg_write_wb <= reg_write_ex;
        wb_sel_wb <= wb_sel_ex;
        alu_result_wb <= alu_result_ex;
    end

    end

endmodule