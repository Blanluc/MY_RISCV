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
logic [3:0] alu_op_ex; // alu sel

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

// EX STAGE

logic [31:0] alu_result_ex; // alu output
logic [31:0] src1_data_ex;
logic [31:0] src2_data_ex;
logic [31:0] alu_operand_a_ex;
logic [31:0] alu_operand_b_ex;


logic [31:0] pc_wb;
logic [4:0]  rd_wb;
logic        mem_r_wb;
logic        mem_w_wb;
logic        reg_write_wb;
logic [2:0]  wb_sel_wb;
logic [31:0] alu_result_wb; // alu output




// Todo : operand selecion
// there will be more options once wb is implemented

regfile regfile (	
            .clk  (clk),
            .w_addr (0),
            .w_data (0),
            .w_en (0),
            .r_addr1 (rs1_ex),
            .r_data1 (src1_data_ex),
            .r_addr2 (rs2_ex),
            .r_data2 (src2_data_ex)
			);

// lets start with mux for src b selecting btwn b or imm
always_comb begin
// ALU SOURCE B MUX
case (rs2_sel_ex)
    //1'b0 : alu_operand_b_ex = rs2_ex;
    1'b1 : alu_operand_b_ex = imm_ex;
    default : alu_operand_b_ex = src2_data_ex;
endcase

//for now we leave this like this
alu_operand_a_ex = src1_data_ex;
end

alu_controller alu_controller(
    .funct3 (funct3_ex),
    .funct7 (funct7_ex),
    .opcode (opcode_ex),
    .alu_op (alu_op_ex)
);

alu alu(
    .operator (alu_op_ex),
    .operand_a (alu_operand_a_ex),
    .operand_b (alu_operand_b_ex),
    .result (alu_result_ex)
);

ex_wb_reg ex_wb_reg(
    .clk   (clk),
    .rst_n (rst_n),

    .pc_wb (pc_wb),
    .rd_wb (rd_wb),
    .mem_r_wb (mem_r_wb),
    .mem_w_wb (mem_w_wb),
    .wb_sel_wb (wb_sel_wb),
    .reg_write_wb (reg_write_wb),
    .alu_result_wb (alu_result_wb),
    
    .pc_ex (pc_ex),
    .rd_ex (rd_ex),
    .mem_r_ex (mem_r_ex),
    .mem_w_ex (mem_w_ex),
    .wb_sel_ex (wb_sel_ex),
    .reg_write_ex (reg_write_ex),
    .alu_result_ex (alu_result_ex)

);







endmodule