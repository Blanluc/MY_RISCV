// Top level module of the core
 `include "headers/wb_sel.svh"
module core
(
  // Clock and Reset
  input  logic                         clk,
  input  logic                         rst_n

);

// PIPELINE

// IF STAGE :

logic [31:0] pc_if;
//logic [31:0] pc_prev_if;
logic [31:0] instr_if;
logic        imem_en;
logic stall;

pc pc (
        .clk  (clk),
        .rst_n (rst_n),
        .pc_d(pc_if+(4*!stall)), // TODO : maybe do proper pc plus 4
        .pc_q(pc_if),
        //.pc_prev_q(pc_prev_if),
        .imem_en(imem_en),
        .stall(stall) 
    );

imem imem (
        .clk  (clk),
        .addr (pc_if),
        //.addr_prev (pc_prev_if),
        .en(imem_en),
        .stall(stall),
        .instr(instr_if) // instr is already wired through the imem, dont need to do anything here
    );

logic [31:0] pc_id;
logic [31:0] instr_id;




if_id_reg if_id_reg(
    .clk   (clk),
    .rst_n (rst_n),

    .stall (stall),

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
//logic        mem_r_id;
logic        mem_w_id;
logic        rs2_sel_id;
logic        rs1_sel_id;
logic        reg_write_id;
logic [2:0]  wb_sel_id;
logic [31:0] rs1_data_id;
logic [31:0] rs2_data_id;

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

// add 0 to to the sels here for like load or stuff

control_unit control_unit (	
            .instr  (instr_id),
            //.mem_r (mem_r_id),
            .mem_w (mem_w_id),
            .rs1_sel (rs1_sel_id),
            .rs2_sel (rs2_sel_id),
            .reg_write (reg_write_id),
            .wb_sel (wb_sel_id)
			);



hazard_unit hazard_unit (	
            .clk  (clk),
            .rst_n (rst_n),
            .rd  (rd_id), // reg that changes
            //.stall_d (stall),
            .src1 (rs1_id),
            .src2 (rs2_id),
            .stall (stall),
            .reg_write (reg_write_id)
			);

regfile regfile (	
            .clk  (clk),
            .w_addr (rd_wb), // from wb stage
            .w_data (return_val), // from wb stage // still have to mux the wb
            .w_en (reg_write_wb), // from wb stage
            .r_addr1 (rs1_id),
            .r_data1 (rs1_data_id),
            .r_addr2 (rs2_id),
            .r_data2 (rs2_data_id)
			);
    

logic [6:0] opcode_ex;
logic [4:0]  rd_ex;
logic [2:0]  funct3_ex;
logic [6:0]  funct7_ex;
logic [31:0] imm_ex;
logic [31:0] pc_ex;
//logic        mem_r_ex;
logic        mem_w_ex;
logic        rs2_sel_ex;
logic        rs1_sel_ex;
logic        reg_write_ex;
logic [2:0]  wb_sel_ex;
logic [3:0] alu_op_ex; // alu sel
logic [31:0] rs1_data_ex;
logic [31:0] rs2_data_ex;



id_ex_reg id_ex_reg(
    .clk   (clk),
    .rst_n (rst_n),

    .stall (stall),

    // id
    .pc_id (pc_id),
    .opcode_id (opcode_id),
    .rd_id (rd_id),
    .funct3_id (funct3_id),
    .funct7_id (funct7_id),
    .rs1_data_id (rs1_data_id),
    .rs2_data_id (rs2_data_id),
    .imm_id (imm_id),
    .wb_sel_id(wb_sel_id),
    .reg_write_id(reg_write_id),
    .rs1_sel_id(rs1_sel_id),
    .rs2_sel_id(rs2_sel_id),
    //.mem_r_id(mem_r_id),
    .mem_w_id(mem_w_id),

    // ex
    .pc_ex (pc_ex),
    .opcode_ex (opcode_ex),
    .rd_ex (rd_ex),
    .funct3_ex (funct3_ex),
    .funct7_ex (funct7_ex),
    .rs1_data_ex (rs1_data_ex),
    .rs2_data_ex (rs2_data_ex),
    .imm_ex (imm_ex),
    .wb_sel_ex(wb_sel_ex),
    .reg_write_ex(reg_write_ex),
    .rs1_sel_ex(rs1_sel_ex),
    .rs2_sel_ex(rs2_sel_ex),
    //.mem_r_ex(mem_r_ex),
    .mem_w_ex(mem_w_ex)
);

// EX STAGE

logic [31:0] alu_result_ex; // alu output

logic [31:0] alu_operand_a_ex;
logic [31:0] alu_operand_b_ex;


logic [31:0] pc_wb;
logic [4:0]  rd_wb;
//logic        mem_r_wb;
logic        mem_w_wb;
logic        reg_write_wb;
logic [2:0]  wb_sel_wb;
logic [31:0] alu_result_wb; // alu output


// lets start with mux for src b selecting btwn b or imm
always_comb begin
// ALU SOURCE B MUX
case (rs2_sel_ex)
    //1'b0 : alu_operand_b_ex = rs2_ex;
    1'b1 : alu_operand_b_ex = imm_ex;
    default : alu_operand_b_ex = rs2_data_ex;
endcase

//for now we leave this like this
alu_operand_a_ex = rs1_data_ex;
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


logic [31:0] pc_mem;
logic [31:0] rs2_data_mem;
logic [4:0] rd_mem;
logic mem_w_mem;
logic [2:0] wb_sel_mem;
logic reg_write_mem;
logic [31:0] alu_result_mem; // alu output
logic [6:0] opcode_mem; 
logic [2:0]  funct3_mem;



ex_mem_reg ex_mem_reg(
    .clk   (clk),
    .rst_n (rst_n),

    .stall(stall),

    .pc_mem (pc_mem),
    .rd_mem (rd_mem),
    .opcode_mem (opcode_mem),
    .funct3_mem (funct3_mem),
    //.mem_r_mem (mem_r_mem),
    .mem_w_mem (mem_w_mem),
    .wb_sel_mem (wb_sel_mem),
    .reg_write_mem (reg_write_mem),
    .alu_result_mem (alu_result_mem),
    .rs2_data_ex (rs2_data_ex),
    
    .pc_ex (pc_ex),
    .rd_ex (rd_ex),
    //.mem_r_ex (mem_r_ex),
    .opcode_ex (opcode_ex),
    .funct3_ex (funct3_ex),
    .mem_w_ex (mem_w_ex),
    .wb_sel_ex (wb_sel_ex),
    .reg_write_ex (reg_write_ex),
    .rs2_data_mem (rs2_data_mem),
    .alu_result_ex (alu_result_ex)

);

// MEM STAGE
logic [31:0] r_data_mem;
logic [31:0] w_data_mem;
logic [31:0] bit_mask_mem;
logic is_unsigned;
logic [31:0] r_data_wb;

// make this take

// result

mem_controller mem_controller (
        //.write_en(mem_w_mem),
        //.alu_result(alu_result_mem),
        .funct3(funct3_mem),
        .bit_mask(bit_mask_mem),
        .is_unsigned(is_unsigned),
        .opcode(opcode_mem)
        //.r_data(r_data_mem)
        //.instr(instr_if) // instr is already wired through the imem, dont need to do anything here
);

// need a mem mux
// always_comb begin
// case (opcode_mem)
//     `OPCODE_STORE : return_val = r_data_wb;
//     default : return_val = alu_result_wb;

// endcase
// end

dmem dmem (
        .clk  (clk),
        .addr (alu_result_mem), //alu reslut mem =
        .bit_mask(bit_mask_mem),
        .write_en(mem_w_mem),
        .w_data(rs2_data_mem), // store is always with rs2
        .r_data(r_data_mem)
        //.instr(instr_if) // instr is already wired through the imem, dont need to do anything here
);


mem_wb_reg mem_wb_reg(
    .clk   (clk),
    .rst_n (rst_n),

    .stall (stall),

    .pc_wb (pc_wb),
    .rd_wb (rd_wb),
    //.mem_r_wb (mem_r_wb),
    .mem_w_wb (mem_w_wb),
    .wb_sel_wb (wb_sel_wb),
    .reg_write_wb (reg_write_wb),
    .alu_result_wb (alu_result_wb),
    .r_data_wb(r_data_wb),
    
    .pc_mem (pc_mem),
    .rd_mem (rd_mem),
    //.r_data(r_data_mem)
    //.mem_r_mem (mem_r_mem),
    .mem_w_mem (mem_w_mem),
    .wb_sel_mem (wb_sel_mem),
    .reg_write_mem (reg_write_mem),
    .r_data_mem(r_data_mem),
    .alu_result_mem (alu_result_mem)

);

logic [31:0] return_val;
always_comb begin
case (wb_sel_wb)
    `WB_DMEM : return_val = r_data_wb;
    default : return_val = alu_result_wb;

endcase
end

// `define WB_ND     3'b000
// `define WB_DMEM   3'b001
// `define WB_ALU    3'b010
// `define WB_IMM	  3'b011
// `define WB_PC_ADD 3'b100
// `define WB_CSR_RD 3'b101 // not used for now
// WB MUX

// WB STAGE

// write back stage
// for now we work only with regs. Then we will implement memory







endmodule