// instruction fetch stage

// return the control signals, correct outputs (...)

module id_ex_reg (
    input  logic        clk,
    input  logic        rst_n,
    input logic [31:0] pc_id,
    //input logic [31:0] instr_id, // i guess we only need it until here
    input logic [6:0] opcode_id,
    input logic [4:0]  rd_id,
    input logic [2:0]  funct3_id,
    input logic [6:0]  funct7_id,
    input logic [4:0]  rs1_id,
    input logic [4:0]  rs2_id,
    input logic [31:0] imm_id,
    input logic        mem_r_id, 
    input logic        mem_w_id, 
    input logic        rs2_sel_id,
    input logic        rs1_sel_id,
    input logic        reg_write_id, 
    input logic [2:0]  wb_sel_id,

    output logic [6:0] opcode_ex,
    output logic [4:0]  rd_ex,
    output logic [2:0]  funct3_ex,
    output logic [6:0]  funct7_ex,
    output logic [4:0]  rs1_ex,
    output logic [4:0]  rs2_ex,
    output logic [31:0] imm_ex,
    output logic [31:0] pc_ex,
    output logic        mem_r_ex, 
    output logic        mem_w_ex, 
    output logic        rs2_sel_ex,
    output logic        rs1_sel_ex,
    output logic        reg_write_ex, 
    output logic [2:0]  wb_sel_ex
);

    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin// rst_n is active low
        pc_ex <= '0;
        opcode_ex <= '0;
        rd_ex <= '0;
        funct3_ex <= '0;
        funct7_ex <= '0;
        rs1_ex <= '0;
        rs2_ex <= '0;
        imm_ex <= '0;
        mem_r_ex <= '0;
        mem_w_ex <= '0;
        rs2_sel_ex <= '0;
        rs1_sel_ex <= '0;
        reg_write_ex <= '0;
        wb_sel_ex <= '0;
    end
    else begin
        pc_ex <= pc_id;
        opcode_ex <= opcode_id;
        rd_ex <= rd_id;
        funct3_ex <= funct3_id;
        funct7_ex <= funct7_id;
        rs1_ex <= rs1_id;
        rs2_ex <= rs2_id;
        imm_ex <= imm_id;
        mem_r_ex <= mem_r_id;
        mem_w_ex <= mem_w_id;
        rs2_sel_ex <= rs2_sel_id;
        rs1_sel_ex <= rs1_sel_id;
        reg_write_ex <= reg_write_id;
        wb_sel_ex <= wb_sel_id;
    end

    end

endmodule