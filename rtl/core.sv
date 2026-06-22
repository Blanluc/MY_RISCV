// Top level module of the core
 
module core
(
  // Clock and Reset
  input  logic                         clk,
  input  logic                         rst_n

);

// PIPELINE




// IF STAGE :

logic [31:0] pc_if;
logic [31:0] instr_if;

pc pc (
        .clk  (clk),
        .rst_n (rst_n),
        .pc_d(pc_if+4),
        .pc_q(pc_if)
    );

imem u_imem (
        .clk  (clk),
        .addr (pc_if),
        .instr(instr_if) // instr is already wired through the imem, dont need to do anything here
    );

logic [31:0] pc_id;
logic [31:0] instr_id;

if_id_reg if_id_reg(
    .clk   (clk),
    .rst_n (rst_n),
    .pc_if (pc_if),
    .instr_if (instr_if),
    .pc_id (pc_id),
    .instr_id (instr_id)

);

// ID STAGE :

logic [6:0] opcode_id;
logic [4:0]  rd_id;
logic [2:0]  funct3_id;
logic [6:0]  funct7_id;
logic [4:0]  rs1_id;
logic [4:0]  rs2_id;
logic [31:0] imm_id;
logic        mem_r_id;
logic        mem_w_id;
logic        rs2_sel_id;
logic        rs1_sel_id;
logic        reg_write_id;
logic [2:0]  wb_sel_id;

decoder decoder (	
            .instr  (instr_id),
            .opcode (opcode_id),
            .rd (rd_id),
            .funct3 (funct3_id),
            .funct7 (funct7_id),
            .rs1 (rs1_id),
            .rs2 (rs2_id),
            .imm (imm_id)
			);

control_unit control_unit (	
            .instr  (instr_id),
            .mem_r (mem_r_id),
            .mem_w (mem_w_id),
            .rs1_sel (rs1_sel_id),
            .rs2_sel (rs2_sel_id),
            .reg_write (reg_write_id),
            .wb_sel (wb_sel_id)
			);

logic [6:0] opcode_ex;
logic [4:0]  rd_ex;
logic [2:0]  funct3_ex;
logic [6:0]  funct7_ex;
logic [4:0]  rs1_ex;
logic [4:0]  rs2_ex;
logic [31:0] imm_ex;
logic [31:0] pc_ex;
logic        mem_r_ex;
logic        mem_w_ex;
logic        rs2_sel_ex;
logic        rs1_sel_ex;
logic        reg_write_ex;
logic [2:0]  wb_sel_ex;

id_ex_reg id_ex_reg(
    .clk   (clk),
    .rst_n (rst_n),

    // id
    .pc_id (pc_id),
    .opcode_id (opcode_id),
    .rd_id (rd_id),
    .funct3_id (funct3_id),
    .funct7_id (funct7_id),
    .rs1_id (rs1_id),
    .rs2_id (rs2_id),
    .imm_id (imm_id),
    .wb_sel_id(wb_sel_id),
    .reg_write_id(reg_write_id),
    .rs1_sel_id(rs1_sel_id),
    .rs2_sel_id(rs2_sel_id),
    .mem_r_id(mem_r_id),
    .mem_w_id(mem_w_id),

    // ex
    .pc_ex (pc_ex),
    .opcode_ex (opcode_ex),
    .rd_ex (rd_ex),
    .funct3_ex (funct3_ex),
    .funct7_ex (funct7_ex),
    .rs1_ex (rs1_ex),
    .rs2_ex (rs2_ex),
    .imm_ex (imm_ex),
    .wb_sel_ex(wb_sel_ex),
    .reg_write_ex(reg_write_ex),
    .rs1_sel_ex(rs1_sel_ex),
    .rs2_sel_ex(rs2_sel_ex),
    .mem_r_ex(mem_r_ex),
    .mem_w_ex(mem_w_ex)
);




endmodule