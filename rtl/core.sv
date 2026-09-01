// TOP LELEV MODULE
 `include "headers/wb_sel.svh"
module core
(
  // Clock and Reset
  input  logic                         clk,
  input  logic                         rst_n,
  output logic uart_tx_o

);

// REGISTER DECLARATIONS

// IF STAGE :
logic [31:0] pc_if;             // (IF) PC
logic [31:0] pc_next;           // NEXT PC
logic [31:0] pc_plus_4_if;      // (IF) PC + 4
logic [31:0] instr_if;          // (IF) FETCHED INSTRUCTION
logic        imem_en;           // INSTRUCTION FETCH ENABLE
logic        stall;             // STALL SIGNAL

// ID STAGE :
logic [31:0] pc_id;             // (ID) PC
logic        flush_id;          // (ID) FLUSH SIGNAL
logic [31:0] instr_id;          // (ID) FETCHED INSTRUCTION
logic [31:0] pc_plus_4_id;      // (ID) PC + 4
logic [6:0]  opcode_id;         // (ID) OPCODE
logic [4:0]  rd_id;             // (ID) DESTINATION REGISTER
logic [11:0] csr_reg_id;        // (ID) INDEX OF CSR REGISTER
logic [2:0]  funct3_id;         // (ID) FUNCT 3
logic [6:0]  funct7_id;         // (ID) FUNCT 7
logic [4:0]  rs1_id;            // (ID) INDEX OF SOURCE 1
logic [4:0]  rs2_id;            // (ID) INDEX OF SOURCE 2
logic [31:0] rs1_data_id;       // (ID) CONTENT OF SOURCE 1
logic [31:0] rs2_data_id;       // (ID) CONTENT OF SOURCE 2
logic [31:0] imm_id;            // (ID) IMMEDIATE VALUE
logic        mem_w_id;          // (ID) ENABLE WRITE TO MEM
logic [1:0]  rs1_sel_id;        // (ID) MUX SELECT FOR SOURCE 1
logic        rs2_sel_id;        // (ID) MUX SELECT FOR SOURCE 2
logic        reg_write_id;      // (ID) ENABLE WRITE TO REG FILE
logic        csr_w_en_id;       // (ID) ENABLE WRITE TO CSR REGISTER
logic        csr_r_en_id;       // (ID) ENABLE READ TO CSR REGISTER
logic [2:0]  wb_sel_id;         // (ID) MUX SELECT VALUE TO WRITE BACK
logic [31:0] zimm_id;           // (ID) ZIMM VALUE (FOR CSR)
logic [31:0] csr_content_id;    // (ID) CONTENT OF CSR REG
logic        rd_x0;             // (ID) DESTINATION IS X0 BOOL (FOR CSR)
logic        rs1_x0;            // (ID) SOURCE 1 IS X0 BOOL (FOR CSR)

// EX STAGE :
logic        csr_r_en_ex;       // (EX) ENABLE WRITE TO CSR REGISTER
logic [11:0] csr_reg_ex;        // (EX) INDEX OF CSR REGISTER
logic [31:0] csr_data_ex;       // (EX) CONTENT OF CSR REG
logic [6:0]  opcode_ex;         // (EX) OPCODE
logic [4:0]  rd_ex;             // (EX) DESTINATION REGISTER
logic [2:0]  funct3_ex;         // (EX) FUNCT 3
logic [6:0]  funct7_ex;         // (EX) FUNCT 7
logic [31:0] imm_ex;            // (EX) IMMEDIATE VALUE
logic [31:0] zimm_ex;           // (EX) ZIMM VALUE (FOR CSR)
logic        flush_ex;          // (EX) FLUSH SIGNAL
logic [31:0] pc_ex;             // (EX) STAGE PC
logic [31:0] pc_plus_4_ex;      // (EX) PC + 4
logic        mem_w_ex;          // (EX) ENABLE WRITE TO MEM
logic        rs2_sel_ex;        // (EX) MUX SELECT FOR SOURCE 2
logic [1:0]  rs1_sel_ex;        // (EX) MUX SELECT FOR SOURCE 1
logic        reg_write_ex;      // (EX) ENABLE WRITE TO REG FILE
logic        csr_write_ex;      // (EX) ENABLE WRITE TO CSR REG
logic [2:0]  wb_sel_ex;         // (EX) MUX SELECT VALUE TO WRITE BACK
logic [3:0]  alu_op_ex;         // (EX) ALU OPERATION SELECT
logic [31:0] rs1_data_ex;       // (EX) CONTENT OF SOURCE 1
logic [31:0] rs2_data_ex;       // (EX) CONTENT OF SOURCE 2
logic [31:0] csr_content_ex;    // (EX) CONTENT OF CSR REG
logic [31:0] alu_result_ex;     // (EX) ALU RESULT
logic        alu_zero_in_ex;    // (EX) ALU ZERO IN
logic        alu_zero_out_ex;   // (EX) ALU ZERO OUT (ALU 0 DEPENDS ON CODITION)
logic [31:0] alu_operand_a_ex;  // (EX) VALUE FED INTO ALU INPUT 1
logic [31:0] alu_operand_b_ex;  // (EX) VALUE FED INTO ALU INPUT 2


// MEM STAGE (1):
logic [31:0] pc_mem1;            // (MEM) STAGE PC
logic [31:0] imm_mem1;           // (MEM) IMMEDIATE VALUE
logic [31:0] rs2_data_mem1;      // (MEM) CONTENT OF SOURCE 2
logic [4:0]  rd_mem1;            // (MEM) DESTINATION REGISTER
logic [11:0] csr_reg_mem1;       // (MEM) INDEX OF CSR REGISTER
logic        mem_w_mem1;         // (MEM) ENABLE WRITE TO MEM
logic        alu_zero_mem1;      // (MEM) ALU ZERO
logic [2:0]  wb_sel_mem1;        // (MEM) MUX SELECT VALUE TO WRITE BACK
logic        reg_write_mem1;     // (MEM) ENABLE WRITE TO REG FILE
logic        csr_write_mem1;     // (MEM) ENABLE WRITE TO CST REG
logic [31:0] alu_result_mem1;    // (MEM) ALU RESULT
logic [6:0]  opcode_mem1;        // (MEM) OPCODE
logic [2:0]  funct3_mem1;        // (MEM) FUNCT 3
logic [31:0] pc_plus_4_mem1;     // (MEM) PC + 4
logic [31:0] csr_content_mem1;   // (MEM) CONTENT OF CSR REG
logic [31:0] csr_data_mem1;      // (MEM) DATA TO BE WRITTEN CSR REG
logic [31:0] r_data_mem1;        // (MEM) DATA READ FROM MEM
logic [31:0] w_data_mem1;        // (MEM) DATA WRITTEN TO MEM
logic [31:0] bit_mask_mem1;      // (MEM) MASK FOR MEM ACCES (word, half, byte)
logic [4:0]  shift_amt_mem1;     // (MEM) SHIFT TO ALIGN ACCESSED DATA AND REG
logic        sign_extend_mem1;   // (MEM) DETECT IF SIGN EXTEND IS NECESSARY

// MEM STAGE (2):
logic [31:0] pc_mem2;            // (MEM) STAGE PC
logic [31:0] imm_mem2;           // (MEM) IMMEDIATE VALUE
logic [31:0] rs2_data_mem2;      // (MEM) CONTENT OF SOURCE 2
logic [4:0]  rd_mem2;            // (MEM) DESTINATION REGISTER
logic [11:0] csr_reg_mem2;       // (MEM) INDEX OF CSR REGISTER
logic        mem_w_mem2;         // (MEM) ENABLE WRITE TO MEM
logic        alu_zero_mem2;      // (MEM) ALU ZERO
logic [2:0]  wb_sel_mem2;        // (MEM) MUX SELECT VALUE TO WRITE BACK
logic        reg_write_mem2;     // (MEM) ENABLE WRITE TO REG FILE
logic        csr_write_mem2;     // (MEM) ENABLE WRITE TO CST REG
logic [31:0] alu_result_mem2;    // (MEM) ALU RESULT
logic [6:0]  opcode_mem2;        // (MEM) OPCODE
logic [2:0]  funct3_mem2;        // (MEM) FUNCT 3
logic [31:0] pc_plus_4_mem2;     // (MEM) PC + 4
logic [31:0] csr_content_mem2;   // (MEM) CONTENT OF CSR REG
logic [31:0] csr_data_mem2;      // (MEM) DATA TO BE WRITTEN CSR REG
logic [31:0] r_data_mem2;        // (MEM) DATA READ FROM MEM
logic [31:0] w_data_mem2;        // (MEM) DATA WRITTEN TO MEM
logic [31:0] bit_mask_mem2;      // (MEM) MASK FOR MEM ACCES (word, half, byte)
logic [4:0]  shift_amt_mem2;     // (MEM) SHIFT TO ALIGN ACCESSED DATA AND REG
logic        sign_extend_mem2;   // (MEM) DETECT IF SIGN EXTEND IS NECESSARY

// WB STAGE :
logic [31:0] r_data_wb;         // (MEM) DATA READ FROM WB
logic [31:0] pc_wb;             // (WB) STAGE PC
logic [4:0]  rd_wb;             // (WB) DESTINATION REGISTER
logic [11:0] csr_reg_wb;        // (WB) INDEX OF CSR REGISTER
logic [31:0] csr_data_wb;       // (WB) DATA TO BE WRITTEN CSR REG
logic [31:0] imm_wb;            // (WB) IMMEDIATE VALUE
logic        mem_w_wb;          // (WB) ENABLE WRITE TO MEM
logic        reg_write_wb;      // (WB) ENABLE WRITE TO REG FILE
logic        csr_write_wb;      // (WB) ENABLE WRITE TO CST REG
logic [2:0]  wb_sel_wb;         // (WB) MUX SELECT VALUE TO WRITE BACK
logic [31:0] alu_result_wb;     // (WB) ALU RESULT
logic        alu_zero_wb;       // (WB) ALU ZERO
logic [31:0] pc_plus_4_wb;      // (WB) PC + 4
logic [31:0] csr_content_wb;    // (WB) CONTENT OF CSR REG
logic [31:0] return_val_wb;     // (WB) VALUE TO BE WRITTEN BACK

// PIPELINE MODULES AND REGISTERS

// IF STAGE:

// PC CONTROLLER
/*
* CONTROLS AND COMPUTES NEX PC VALUE
*/
pc_controller pc_controller (
    .pc(pc_if),
    .pc_plus_4(pc_plus_4_if),
    .opcode_id(opcode_id),
    .opcode_ex(opcode_ex),
    .alu_zero(alu_zero_out_ex),
    .pc_jump(pc_id),
    .pc_branch(pc_ex),
    .imm_id(imm_id),
    .imm_ex(imm_ex),
    .alu_result(alu_result_ex),
    .stall(stall),
    .pc_next(pc_next),
    .flush_ex(flush_ex),
    .rs1_data (rs1_data_id),
    .flush_id(flush_id)
);

// PROGRAM COUNTER
/*
* NEXT VALUE GIVEN BY PC CONTROLLER
* CONTROLS IMEM READ ENABLE
* DOESNT UPDATE ON STALLS (STALL IN EARLIER STACK BACKPROPAGATES FOR NOW)
*/
pc pc (
    .clk  (clk),
    .rst_n (rst_n),
    .pc_d(pc_next),
    .pc_q(pc_if),
    .imem_en(imem_en),
    .stall(stall) 
);

// PC + 4
/*
* COMPUTES PC+4 VALUE
*/
pc_plus_4 pc_plus_4 (
    .pc  (pc_if),
    .pc_plus_4 (pc_plus_4_if)
);

// MAIN MEMORY
/*
* DATA AND INSTR MEM ON SAME ADDRESS SPACE
* WE 
*/
main_mem main_mem (
    .clk  (clk),
    .rom_addr (pc_if),
    //.instr(instr_if), // instr is already wired through the imem, dont need to do anything here
    .flush_id(flush_id),
    .instr(instr_id),
    .stall(stall),

    .dram_addr (alu_result_mem1), // alu reslut mem =
    .dram_bit_mask(bit_mask_mem1),
    .shift_amt (shift_amt_mem1),
    .sign_extend (sign_extend_mem1), // will know how to extend depending on mask
    .dram_write_en(mem_w_mem1),
    .dram_w_data(rs2_data_mem1), // store is always with rs2
    .dram_r_data(r_data_mem1),
    .uart_tx_o(uart_tx_o) // uart output 
);

// IF-ID STAGE REG
if_id_reg if_id_reg(
    // GLOBAL SIGNALS
    .clk   (clk),
    .rst_n (rst_n),
    .stall (stall),

    // IF STAGE
    .pc_if (pc_if),
    .pc_plus_4_if(pc_plus_4_if),
    //.instr_if (instr_if),

    // ID STAGE
    .flush_id(flush_id),
    .pc_id (pc_id),
    .pc_plus_4_id(pc_plus_4_id)
    //.instr_id (instr_id)

);


// DECODER
/*
* TODO : MAYBE SOME OF THE SIGNALS CAN BE DIRECTLY WIRED?
*/
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


// CONTROL UNIT
control_unit control_unit (	
    .instr  (instr_id),
    .mem_w (mem_w_id),
    .rs1_sel (rs1_sel_id),
    .rs2_sel (rs2_sel_id),
    .reg_write (reg_write_id),
    .csr_write (csr_w_en_id),
    .csr_read (csr_r_en_id),
    .rd_x0 (rd_x0), // added for csr
    .rs1_x0 (rs1_x0), // added for csr
    .zimm (zimm_id),
    .wb_sel (wb_sel_id)
);

// HAZARD UNIT
hazard_unit hazard_unit (	
    .clk  (clk),
    .rst_n (rst_n),
    .rd  (rd_id), // reg that changes // could be also csr?
    .csr (csr_reg_id),
    .csr_write(csr_w_en_id),
    .src1 (rs1_id),
    .src2 (rs2_id),
    .stall (stall),
    .reg_write (reg_write_id)
);

// REGFILE
regfile regfile (	
    .clk  (clk),
    .w_addr (rd_wb), // from wb stage
    .w_data (return_val_wb), // from wb stage // still have to mux the wb
    .w_en (reg_write_wb), // from wb stage // write enable
    .r_addr1 (rs1_id),
    .r_data1 (rs1_data_id),
    .r_addr2 (rs2_id),
    .r_data2 (rs2_data_id)
);

// CSR FILE
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
    

id_ex_reg id_ex_reg(
    .clk   (clk),
    .rst_n (rst_n),
    .stall (stall),

    // ID STAGE
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
    .mem_w_id(mem_w_id),

    // EX STAGE
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
    .mem_w_ex(mem_w_ex)
);


// MUX FOR ALU OPERANDS
always_comb begin
    // ALU SOURCE B MUX
    case (rs2_sel_ex)
        1'b1 : alu_operand_b_ex = imm_ex;
        default : alu_operand_b_ex = rs2_data_ex;
    endcase

    // mux for src a selecting btwn a or pc // ad zimm?
    case (rs1_sel_ex)
        2'b01 : alu_operand_a_ex = pc_ex; // pc
        2'b10 : alu_operand_a_ex = zimm_ex; // zimm
        default : alu_operand_a_ex = rs1_data_ex;
    endcase
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
);


ex_mem1_reg ex_mem1_reg(
    .clk   (clk),
    .rst_n (rst_n),

    .stall(stall),
    
    // EX STAGE
    .pc_ex (pc_ex),
    .imm_ex (imm_ex),
    .pc_plus_4_ex(pc_plus_4_ex),
    .rd_ex (rd_ex),
    .csr_reg_ex (csr_reg_ex),
    .opcode_ex (opcode_ex),
    .funct3_ex (funct3_ex),
    .alu_zero_ex (alu_zero_out_ex),
    .mem_w_ex (mem_w_ex),
    .wb_sel_ex (wb_sel_ex),
    .reg_write_ex (reg_write_ex),
    .csr_data_ex (csr_data_ex),
    .csr_content_ex (csr_content_ex),
    .csr_write_ex (csr_write_ex),
    .rs2_data_ex (rs2_data_ex),
    .alu_result_ex (alu_result_ex), 

    // MEM STAGE
    .pc_mem1 (pc_mem1),
    .imm_mem1 (imm_mem1),
    .pc_plus_4_mem1(pc_plus_4_mem1),
    .rd_mem1 (rd_mem1),
    .csr_reg_mem1 (csr_reg_mem1),
    .opcode_mem1 (opcode_mem1),
    .funct3_mem1 (funct3_mem1),
    .mem_w_mem1 (mem_w_mem1),
    .wb_sel_mem1 (wb_sel_mem1),
    .reg_write_mem1 (reg_write_mem1),
    .csr_write_mem1 (csr_write_mem1),
    .csr_data_mem1 (csr_data_mem1),
    .csr_content_mem1 (csr_content_mem1),
    .alu_result_mem1 (alu_result_mem1),
    .alu_zero_mem1 (alu_zero_mem1),
    .rs2_data_mem1 (rs2_data_mem1)

);

mem_controller mem_controller (
        .funct3(funct3_mem1),
        .bit_mask(bit_mask_mem1),
        .sign_extend(sign_extend_mem1),
        .addr_lsb  (alu_result_mem1[1:0]),
        .shift_amt (shift_amt_mem1),
        .opcode(opcode_mem1)
);

mem1_mem2_reg mem1_mem2_reg(
    .clk   (clk),
    .rst_n (rst_n),

    .stall(stall),
    
    // MEM STAGE 1
    .pc_mem1 (pc_mem1),
    .imm_mem1 (imm_mem1),
    .pc_plus_4_mem1(pc_plus_4_mem1),
    .rd_mem1 (rd_mem1),
    .csr_reg_mem1 (csr_reg_mem1),
    .opcode_mem1 (opcode_mem1),
    .funct3_mem1 (funct3_mem1),
    .mem_w_mem1 (mem_w_mem1),
    .wb_sel_mem1 (wb_sel_mem1),
    .reg_write_mem1 (reg_write_mem1),
    .csr_write_mem1 (csr_write_mem1),
    .csr_data_mem1 (csr_data_mem1),
    .csr_content_mem1 (csr_content_mem1),
    .alu_result_mem1 (alu_result_mem1),
    .alu_zero_mem1 (alu_zero_mem1),
    .rs2_data_mem1 (rs2_data_mem1),

    // MEM STAGE 2
    .imm_mem2 (imm_mem2),
    .pc_mem2 (pc_mem2),
    .pc_plus_4_mem2 (pc_plus_4_mem2),
    .rd_mem2 (rd_mem2),
    .csr_reg_mem2 (csr_reg_mem2),
    .csr_data_mem2 (csr_data_mem2),
    .csr_content_mem2 (csr_content_mem2),
    .opcode_mem2 (opcode_mem2),
    .mem_w_mem2 (mem_w_mem2),
    .funct3_mem2 (funct3_mem2),
    .wb_sel_mem2 (wb_sel_mem2),
    .reg_write_mem2 (reg_write_mem2),
    .csr_write_mem2 (csr_write_mem2),
    .alu_zero_mem2 (alu_zero_mem2),
    //.r_data_mem2(r_data_mem1), // takes 1 cycle
    .alu_result_mem2 (alu_result_mem2),
    .rs2_data_mem2 (rs2_data_mem2)

);

mem2_wb_reg mem2_wb_reg(
    .clk   (clk),
    .rst_n (rst_n),
    .stall (stall),
    
    // MEM STAGE
    .imm_mem2 (imm_mem2),
    .pc_mem2 (pc_mem2),
    .pc_plus_4_mem2 (pc_plus_4_mem2),
    .rd_mem2 (rd_mem2),
    .csr_reg_mem2 (csr_reg_mem2),
    .csr_data_mem2 (csr_data_mem2),
    .csr_content_mem2 (csr_content_mem2),
    .mem_w_mem2 (mem_w_mem2),
    .wb_sel_mem2 (wb_sel_mem2),
    .reg_write_mem2 (reg_write_mem2),
    .csr_write_mem2 (csr_write_mem2),
    .alu_zero_mem2 (alu_zero_mem2),
    .r_data_mem2(r_data_mem1), // takes 1 cycle
    .alu_result_mem2 (alu_result_mem2),

    // WB STAGE
    .pc_wb (pc_wb),
    .imm_wb (imm_wb),
    .pc_plus_4_wb (pc_plus_4_wb),
    .rd_wb (rd_wb),
    .csr_reg_wb (csr_reg_wb),
    .csr_data_wb (csr_data_wb),
    .csr_content_wb (csr_content_wb),
    .mem_w_wb (mem_w_wb),
    .wb_sel_wb (wb_sel_wb),
    .reg_write_wb (reg_write_wb),
    .csr_write_wb (csr_write_wb),
    .alu_result_wb (alu_result_wb),
    .alu_zero_wb (alu_zero_wb),
    .r_data_wb(r_data_wb)

);


// MUX FOR RETURN VAL
always_comb begin
    case (wb_sel_wb)
        `WB_DMEM : return_val_wb = r_data_wb;
        `WB_PC_PLUS_4 : return_val_wb = pc_plus_4_wb; // JAL/JALR
        `WB_IMM : return_val_wb = imm_wb;//lui_wb; // JAL/JALR
        `WB_CSR_RD : return_val_wb = csr_content_wb; // csr
        default : return_val_wb = alu_result_wb;
    endcase
end

endmodule