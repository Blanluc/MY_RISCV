// CONTROL UNIT
`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
module control_unit (
    input  logic [31:0] instr,
    //output logic [3:0]  alu_op, // select op
    //output logic        mem_r,  // read from dmem // I dont think I need this
    output logic        mem_w,  // write to dmem
    output logic        rs2_sel, // imm or reg for alu
    output logic        rs1_sel, // imm or reg for alu
    output logic        reg_write, // reg write
    output logic [2:0]  wb_sel // what gets written back : ALU, D.Mem, imm(LUI), PC+4 , (CSR but not yet implemented ...)
);

    // internal signals
    logic [6:0]  opcode;
    assign opcode=instr[6:0];

    // instantiate decoder
    // decoder decoder (	
    //         .instr  (instr),
    //         .opcode (opcode),
    //         .rd (rd),
    //         .funct3 (funct3),
    //         .funct7 (funct7),
    //         .rs1 (rs1),
    //         .rs2 (rs2),
    //         .imm (imm)
	//         );

    // Logic gate stuff

    // TODO : CSR to be implemented
    // Jump stuff ...

    // TODO : Complete & test
    

    always_comb begin

        case(opcode)

        // Load <=> read from d mem
        `OPCODE_LOAD : begin
            //mem_r = 1;
            mem_w = 0;

            reg_write = 1; // load to a register

            wb_sel = `WB_DMEM; // value from mem

            rs1_sel = 1; // choose rs a
            rs2_sel = 1; // choose imm (lw = addi register,0,z so yeah) // can be 0
            

        end
        `OPCODE_STORE : begin

            //mem_r = 0;
            mem_w = 1;

            reg_write = 0; // load to a register

            wb_sel = `WB_ND; // not needed

            rs1_sel = 0; // choose rs a
            rs2_sel = 1; // choose imm

        end
        `OPCODE_RTYPE : begin
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register

            wb_sel = `WB_ALU; // alu

            rs1_sel = 0; // choose rs a
            rs2_sel = 0; // choose rs b

        end

        `OPCODE_ITYPE : begin
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register

            wb_sel = `WB_ALU; // alu

            rs1_sel = 0; // choose rs a
            rs2_sel = 1; // choose IMM

        end

        `OPCODE_JAL : begin
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register

            wb_sel = `WB_PC_ADD;

            rs1_sel = 1; // choose PC
            rs2_sel = 1; // choose rs IMM

        end
        `OPCODE_JALR : begin
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register

            wb_sel = `WB_PC_ADD; 

            rs1_sel = 0; // choose base
            rs2_sel = 1; // choose IMM
    
        end
        `OPCODE_BRANCH : begin
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register

            wb_sel = `WB_PC_ADD;

            rs1_sel = 0; // choose reg
            rs2_sel = 0; // choose reg
    
        end
        
        default                 : begin
            //mem_r = 0;
            mem_w = 0;

            reg_write = 0;

            wb_sel = `WB_ND; // not needed

            rs1_sel = 0; 
            rs2_sel = 0; 
        end
        endcase  
    end


endmodule