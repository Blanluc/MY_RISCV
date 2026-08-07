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

// TODO :
// PC LOGIC
// mux between adder and 

logic [31:0] pc_if;
logic [31:0] pc_next;
logic [31:0] pc_plus_4_if;
//logic [31:0] pc_prev_if;
logic [31:0] instr_if;
logic        imem_en;
logic stall;

// pc can be :
// pc if stall
// pc + 4
// etc
pc_controller pc_controller (
        .pc(pc_if),
        .pc_plus_4(pc_plus_4_if),
        .opcode_id(opcode_id),
        .opcode_ex(opcode_ex),
        .alu_zero(alu_zero_out_ex),
        .pc_jump(pc_id),
        .pc_branch(pc_ex),
        .lui_ex(lui_ex),
        .imm_id(imm_id),
        .imm_ex(imm_ex),
        //.is_jalr(is_jalr_id),
        //.pc_prev_q(pc_prev_if),
        .alu_result(alu_result_ex),
        .stall(stall),
        .pc_next(pc_next),
        .flush_ex(flush_ex),
        .rs1_data (rs1_data_id),
        .flush_id(flush_id)
    );

pc pc (
        .clk  (clk),
        .rst_n (rst_n),
        .pc_d(pc_next), // TODO : maybe do proper pc plus 4 : yess
        .pc_q(pc_if),
        //.pc_prev_q(pc_prev_if),
        .imem_en(imem_en),
        .stall(stall) 
    );

pc_plus_4 pc_plus_4 (
        .pc  (pc_if),
        .pc_plus_4 (pc_plus_4_if)
    );

// imem imem (
//         .clk  (clk),
//         .addr (pc_if),
//         //.addr_prev (pc_prev_if),
//         .en(imem_en),
//         .stall(stall),
//         .instr(instr_if), // instr is already wired through the imem, dont need to do anything here
//         .dram_addr (alu_result_mem), //alu reslut mem =
//         .dram_bit_mask(bit_mask_mem),
//         .dram_write_en(mem_w_mem),
//         .dram_w_data(rs2_data_mem), // store is always with rs2
//         .dram_r_data(r_data_mem)
//     );

main_mem main_mem (
        .clk  (clk),
        .rom_addr (pc_if),
        //.addr_prev (pc_prev_if),
        //.en(imem_en),
        //.stall(stall),
        .instr(instr_if), // instr is already wired through the imem, dont need to do anything here

        .dram_addr (alu_result_mem), //alu reslut mem =
        .dram_bit_mask(bit_mask_mem),
        .shift_amt (shift_amt_mem),
        .sign_extend (sign_extend_mem), // will know how to extend depending on mask
        .dram_write_en(mem_w_mem),
        .dram_w_data(rs2_data_mem), // store is always with rs2
        .dram_r_data(r_data_mem)//
    );

logic [31:0] pc_id;
logic  flush_id;
//logic  is_jalr_id;
logic  flush_ex;
logic [31:0] instr_id;
logic [31:0] pc_plus_4_id;




if_id_reg if_id_reg(
    .clk   (clk),
    .rst_n (rst_n),
    .flush_id(flush_id),

    .stall (stall),

    .pc_if (pc_if),
    .pc_plus_4_if(pc_plus_4_if),
    .instr_if (instr_if),

    .pc_id (pc_id),
    .pc_plus_4_id(pc_plus_4_id),
    .instr_id (instr_id)

);

// ID STAGE :

logic [6:0] opcode_id;
logic [4:0]  rd_id;
logic [11:0]  csr_reg_id;
//logic [31:0]  csr_data_id;
logic [2:0]  funct3_id;
logic [6:0]  funct7_id;
logic [4:0]  rs1_id;
logic [4:0]  rs2_id;
logic [31:0] imm_id;
//logic        mem_r_id;
logic        mem_w_id;
logic        rs2_sel_id;
logic       [1:0] rs1_sel_id;
logic        rd_x0;
logic        rs1_x0;
logic        reg_write_id;
logic        csr_w_en_id;
logic        csr_r_en_id;
logic [2:0]  wb_sel_id;
logic [31:0] rs1_data_id;
logic [31:0] rs2_data_id;
logic [31:0] zimm_id;
logic [31:0] csr_content_id;

// Todo:
// 1) Add zimm in the regs up until the csr unit
// 2) Add zimm to the operand mux
// 3) Add hazards for csr stuff
// 4) add csr write for hazards

decoder decoder (	
            .instr  (instr_id),
            .opcode (opcode_id),
            .rd (rd_id),
            .funct3 (funct3_id),
            .funct7 (funct7_id),
            .rs1 (rs1_id),
            .rs2 (rs2_id),
            .imm (imm_id),
            .csr_reg (csr_reg_id),
            .rd_x0 (rd_x0), // added for csr
            .rs1_x0 (rs1_x0), // added for csr
            .zimm (zimm_id)
			);

// add 0 to to the sels here for like load or stuff

control_unit control_unit (	
            .instr  (instr_id),
            //.mem_r (mem_r_id),
            .mem_w (mem_w_id),
            .rs1_sel (rs1_sel_id),
            .rs2_sel (rs2_sel_id),
            .reg_write (reg_write_id),
            .csr_write (csr_w_en_id),
            .csr_read (csr_r_en_id),
            //.flush_id(flush_id),
            .rd_x0 (rd_x0), // added for csr
            .rs1_x0 (rs1_x0), // added for csr
            .zimm (zimm_id),
            .wb_sel (wb_sel_id)
			);



hazard_unit hazard_unit (	
            .clk  (clk),
            .rst_n (rst_n),
            .rd  (rd_id), // reg that changes // could be also csr?
            //.stall_d (stall),
            .csr (csr_reg_id),
            .csr_write(csr_w_en_id),
            .src1 (rs1_id),
            .src2 (rs2_id),
            .stall (stall),
            .reg_write (reg_write_id)
			);

regfile regfile (	
            .clk  (clk),
            .w_addr (rd_wb), // from wb stage
            .w_data (return_val), // from wb stage // still have to mux the wb
            .w_en (reg_write_wb), // from wb stage // write enable
            .r_addr1 (rs1_id),
            .r_data1 (rs1_data_id),
            .r_addr2 (rs2_id),
            .r_data2 (rs2_data_id)
			);

// Todo : csr ops
// when its csr, read csr Is a swap a good idea?
// maybe stall stuff, first store one and then the other?
// have something to store simult
// instead of csr being in the wb mux, make exclusing wb reg
logic  csr_r_en_ex;

csr_file csr_file (	
            .clk  (clk),
            .rst_n (rst_n),
            .csr_w_addr (csr_reg_wb), // from wb stage
            .csr_w_data (csr_data_wb), // from wb stage // still have to mux the wb
            .csr_r_en (csr_r_en_id), // complete ; get it from ex stage // why
            .csr_w_en (csr_write_wb), // from wb stage // enable
            .csr_r_addr (csr_reg_id),
            .csr_r_data (csr_content_id)
			);
    

logic [11:0] csr_reg_ex;
logic [31:0] csr_data_ex;
logic [6:0] opcode_ex;
logic [4:0]  rd_ex;
logic [2:0]  funct3_ex;
logic [6:0]  funct7_ex;
logic [31:0] imm_ex;
logic [31:0] zimm_ex;
logic [31:0] lui_ex;
logic [31:0] pc_ex;
logic [31:0] pc_plus_4_ex;
//logic        mem_r_ex;
logic        mem_w_ex;
logic        rs2_sel_ex;
logic       [1:0] rs1_sel_ex;
logic        reg_write_ex;
logic        csr_write_ex;
logic [2:0]  wb_sel_ex;
logic [3:0] alu_op_ex; // alu sel
logic [31:0] rs1_data_ex;
logic [31:0] rs2_data_ex;
logic [31:0] csr_content_ex;




id_ex_reg id_ex_reg(
    .clk   (clk),
    .rst_n (rst_n),

    .stall (stall),

    // id
    .pc_id (pc_id),
    .pc_plus_4_id(pc_plus_4_id),
    .opcode_id (opcode_id),
    .rd_id (rd_id),
    .funct3_id (funct3_id),
    .funct7_id (funct7_id),
    .rs1_data_id (rs1_data_id),
    .rs2_data_id (rs2_data_id),
    .csr_content_id (csr_content_id),
    .csr_reg_id (csr_reg_id),
    .imm_id (imm_id),
    .zimm_id (zimm_id),
    .wb_sel_id(wb_sel_id),
    .reg_write_id(reg_write_id),
    .csr_write_id(csr_w_en_id),
    .rs1_sel_id(rs1_sel_id),
    .rs2_sel_id(rs2_sel_id),
    //.mem_r_id(mem_r_id),
    .mem_w_id(mem_w_id),

    // ex
    .flush_ex(flush_ex),
    .pc_ex (pc_ex),
    .pc_plus_4_ex(pc_plus_4_ex),
    .opcode_ex (opcode_ex),
    .rd_ex (rd_ex),
    .funct3_ex (funct3_ex),
    .funct7_ex (funct7_ex),
    .rs1_data_ex (rs1_data_ex),
    .rs2_data_ex (rs2_data_ex),
    .csr_content_ex (csr_content_ex),
    .csr_reg_ex (csr_reg_ex),
    .imm_ex (imm_ex),
    .zimm_ex (zimm_ex),
    .wb_sel_ex(wb_sel_ex),
    .reg_write_ex(reg_write_ex),
    .csr_write_ex(csr_write_ex),
    .rs1_sel_ex(rs1_sel_ex),
    .rs2_sel_ex(rs2_sel_ex),
    //.mem_r_ex(mem_r_ex),
    .mem_w_ex(mem_w_ex)
);

// EX STAGE

assign lui_ex=imm_ex;

logic [31:0] alu_result_ex; // alu output

logic  alu_zero_in_ex;
logic  alu_zero_out_ex;

logic [31:0] alu_operand_a_ex;
logic [31:0] alu_operand_b_ex;

//logic [32:0] csr_out_ex;

logic [31:0] pc_wb;
logic [4:0]  rd_wb;
logic [11:0]  csr_reg_wb;
logic [31:0] csr_data_wb;
logic [31:0]  lui_wb;
//logic        mem_r_wb;
logic        mem_w_wb;
logic        reg_write_wb;
logic        csr_write_wb;
logic [2:0]  wb_sel_wb;
logic [31:0] alu_result_wb; // alu output
logic  alu_zero_wb;
logic [31:0] pc_plus_4_wb;
logic [31:0] csr_content_wb;



// mux for src b selecting btwn b or imm
always_comb begin
// ALU SOURCE B MUX
case (rs2_sel_ex)
    //1'b0 : alu_operand_b_ex = rs2_ex;
    1'b1 : alu_operand_b_ex = imm_ex;
    default : alu_operand_b_ex = rs2_data_ex;
endcase

// mux for src a selecting btwn a or pc // ad zimm?
case (rs1_sel_ex)
    //1'b0 : alu_operand_b_ex = rs2_ex;
    2'b01 : alu_operand_a_ex = pc_ex; // pc
    2'b10 : alu_operand_a_ex = zimm_ex; // zimm
    default : alu_operand_a_ex = rs1_data_ex;
endcase
//alu_operand_a_ex = rs1_data_ex;
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
    .result (alu_result_ex),
    .alu_zero (alu_zero_in_ex),
    .csr_data (csr_data_ex) // to be written to csr
);

branch_unit branch_unit(
    .alu_zero_in (alu_zero_in_ex),
    .alu_zero_out (alu_zero_out_ex),
    .opcode (opcode_ex),
    .funct3 (funct3_ex)
    //.imm(imm_id)

    //.operand_b (alu_operand_b_ex),
    //.result (alu_result_ex)
);

// Todo: csr unit works on data :
// for now we need a select between alu out and csr out to decide writeback

// csr_unit csr_unit(
//     .funct3 (funct3_ex),
//     //.funct7 (funct7_ex),
//     .opcode (opcode_ex),
//     .csr_in(alu_operand_b_ex),
//     .src1_in(alu_operand_a_ex),
//     .csr_out(csr_data_ex)
// );


logic [31:0] pc_mem;
logic [31:0] lui_mem;
logic [31:0] rs2_data_mem;
logic [4:0] rd_mem;
logic [11:0] csr_reg_mem;
logic mem_w_mem;
logic alu_zero_mem;
logic [2:0] wb_sel_mem;
logic reg_write_mem;
logic csr_write_mem;
logic [31:0] alu_result_mem; // alu output
logic [6:0] opcode_mem; 
logic [2:0]  funct3_mem;
logic [31:0] pc_plus_4_mem;
logic [31:0] csr_content_mem;

logic [31:0] csr_data_mem; // csr



ex_mem_reg ex_mem_reg(
    .clk   (clk),
    .rst_n (rst_n),

    .stall(stall),
    

    .pc_mem (pc_mem),
    .lui_mem (lui_mem),
    .pc_plus_4_mem(pc_plus_4_mem),
    .rd_mem (rd_mem),
    .csr_reg_mem (csr_reg_mem),
    .opcode_mem (opcode_mem),
    .funct3_mem (funct3_mem),
    //.mem_r_mem (mem_r_mem),
    .mem_w_mem (mem_w_mem),
    .wb_sel_mem (wb_sel_mem),
    .reg_write_mem (reg_write_mem),
    .csr_write_mem (csr_write_mem),
    .csr_data_mem (csr_data_mem),
    .csr_content_mem (csr_content_mem),
    .alu_result_mem (alu_result_mem),
    .alu_zero_mem (alu_zero_mem),
    .rs2_data_ex (rs2_data_ex),
    
    .pc_ex (pc_ex),
    .lui_ex (lui_ex),
    .pc_plus_4_ex(pc_plus_4_ex),
    .rd_ex (rd_ex),
    .csr_reg_ex (csr_reg_ex),
    //.mem_r_ex (mem_r_ex),
    .opcode_ex (opcode_ex),
    .funct3_ex (funct3_ex),
    .alu_zero_ex (alu_zero_out_ex),
    .mem_w_ex (mem_w_ex),
    .wb_sel_ex (wb_sel_ex),
    .reg_write_ex (reg_write_ex),
    .csr_data_ex (csr_data_ex),
    .csr_content_ex (csr_content_ex),
    .csr_write_ex (csr_write_ex),
    .rs2_data_mem (rs2_data_mem),
    .alu_result_ex (alu_result_ex)

);

// MEM STAGE
logic [31:0] r_data_mem;
logic [31:0] w_data_mem;
logic [31:0] bit_mask_mem;
logic [4:0] shift_amt_mem;
logic sign_extend_mem;
logic [31:0] r_data_wb;

// make this take

// result

mem_controller mem_controller (
        //.write_en(mem_w_mem),
        //.alu_result(alu_result_mem),
        .funct3(funct3_mem),
        .bit_mask(bit_mask_mem),
        .sign_extend(sign_extend_mem),
        .addr_lsb  (alu_result_mem[1:0]),
        .shift_amt (shift_amt_mem),
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

// dmem dmem (
//         .clk  (clk),
//         .addr (alu_result_mem), //alu reslut mem =
//         .bit_mask(bit_mask_mem),
//         .write_en(mem_w_mem),
//         .w_data(rs2_data_mem), // store is always with rs2
//         .r_data(r_data_mem)
//         //.instr(instr_if) // instr is already wired through the imem, dont need to do anything here
// );


mem_wb_reg mem_wb_reg(
    .clk   (clk),
    .rst_n (rst_n),

    .stall (stall),

    .pc_wb (pc_wb),
    .lui_wb (lui_wb),
    .pc_plus_4_wb (pc_plus_4_wb),
    .rd_wb (rd_wb),
    .csr_reg_wb (csr_reg_wb),
    .csr_data_wb (csr_data_wb),
    .csr_content_wb (csr_content_wb),
    //.mem_r_wb (mem_r_wb),
    .mem_w_wb (mem_w_wb),
    .wb_sel_wb (wb_sel_wb),
    .reg_write_wb (reg_write_wb),
    .csr_write_wb (csr_write_wb),
    .alu_result_wb (alu_result_wb),
    .alu_zero_wb (alu_zero_wb),
    .r_data_wb(r_data_wb),
    
    .lui_mem (lui_mem),
    .pc_mem (pc_mem),
    .pc_plus_4_mem (pc_plus_4_mem),
    .rd_mem (rd_mem),
    .csr_reg_mem (csr_reg_mem),
    .csr_data_mem (csr_data_mem),
    .csr_content_mem (csr_content_mem),
    //.r_data(r_data_mem)
    //.mem_r_mem (mem_r_mem),
    .mem_w_mem (mem_w_mem),
    .wb_sel_mem (wb_sel_mem),
    .reg_write_mem (reg_write_mem),
    .csr_write_mem (csr_write_mem),
    .alu_zero_mem (alu_zero_mem),
    .r_data_mem(r_data_mem),
    .alu_result_mem (alu_result_mem)

);
// add jal/ JALR
logic [31:0] return_val;
always_comb begin
case (wb_sel_wb)
    `WB_DMEM : return_val = r_data_wb;
    `WB_PC_PLUS_4 : return_val = pc_plus_4_wb; // JAL/JALR
    //`WB_PC_ADD : return_val = alu_result_wb;
    `WB_IMM : return_val = lui_wb; // JAL/JALR
    `WB_CSR_RD : return_val = csr_content_wb; // csr
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