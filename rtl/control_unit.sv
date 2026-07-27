// CONTROL UNIT
`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
`include "headers/csr_ops.svh"
module control_unit (
    input  logic [31:0] instr,
    //output logic [3:0]  alu_op, // select op
    //output logic        mem_r,  // read from dmem // I dont think I need this
    output logic        mem_w,  // write to dmem
    //output logic        //flush_id, 
    output logic        rs2_sel, // imm or reg for alu
    output logic       [1:0] rs1_sel, // zimm, pc or reg for alu
    output logic        reg_write, // reg write
    output logic        csr_write, // csr write
    output logic [2:0]  wb_sel // what gets written back : ALU, D.Mem, imm(LUI), PC+4 , (CSR but not yet implemented ...)
);

    // internal signals
    logic [6:0]  opcode;
    assign opcode=instr[6:0];
    logic [2:0]  funct3;
    assign funct3=instr[14:12];

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
            //flush_id=0;

            reg_write = 1; // load to a register
            csr_write = 0;

            wb_sel = `WB_DMEM; // value from mem

            rs1_sel = 1; // choose rs a
            rs2_sel = 1; // choose imm (lw = addi register,0,z so yeah) // can be 0
        end
            

        
        `OPCODE_STORE : begin

            //mem_r = 0;
            mem_w = 1;

            reg_write = 0; // load to a registe
            csr_write = 0;
            //flush_id=0;

            wb_sel = `WB_ND; // not needed

            rs1_sel = 0; // choose rs a
            rs2_sel = 1; // choose imm

        end
        `OPCODE_RTYPE : begin
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register
            csr_write = 0;

            wb_sel = `WB_ALU; // alu
            ////flush_id=0;

            rs1_sel = 0; // choose rs a
            rs2_sel = 0; // choose rs b

        end

        `OPCODE_ITYPE : begin
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register
            csr_write = 0;
            //flush_id=0;

            wb_sel = `WB_ALU; // alu

            rs1_sel = 0; // choose rs a
            rs2_sel = 1; // choose IMM

        end
        // JUMPS
        `OPCODE_JAL : begin
            $display("JAL!");
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register
            csr_write = 0;
            //flush_id=1;

            wb_sel = `WB_PC_PLUS_4;

            rs1_sel = 1; // choose PC
            rs2_sel = 1; // choose rs IMM

        end
        `OPCODE_JALR : begin
            $display("JALR");
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register
            csr_write = 0;
            //flush_id=1;

            wb_sel = `WB_PC_PLUS_4; 

            rs1_sel = 0; // choose base
            rs2_sel = 1; // choose IMM // ahah // we need to bring the reg data!
    
        end
        `OPCODE_BRANCH : begin
            //$display("BRANCH");
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register
            csr_write = 0;

            wb_sel = `WB_ND;
            //flush_id=0;

            rs1_sel = 0; // choose reg
            rs2_sel = 0; // choose reg
    
        end

        // For now I only have 1 in order core so I just implement this as any other op
        `OPCODE_SYSTEM : begin
            //$display("BRANCH");
            //mem_r = 0;
            mem_w = 0;

             // store in register

            wb_sel = `WB_CSR_RD;
            //flush_id=0;
            
            

            // dpepnds on funct 3
            case (funct3)

            // Todo: CSR: Right now I'm always writing when csr op. This is not what the final behaviour should be

            // `CSRRW,`CSRRS,`CSRRC: begin
            //     rs1_sel = 0; // choose reg
            //     rs2_sel = 1; // csr
            //     reg_write = 1;
            //     csr_write = 1;
            // end

            `CSRRWI,`CSRRSI,`CSRRCI: begin
                rs1_sel = 2; // choose imm (zimm)
                rs2_sel = 1; // csr
                reg_write = 0;
                csr_write = 1;
            end
            default : begin
                rs1_sel = 0; // choose reg
                rs2_sel = 1; // csr
                reg_write = 1;
                csr_write = 1;
            end

            

            

            endcase
    
        end

        `OPCODE_LUI : begin
            //$display("BRANCH");
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register

            wb_sel = `WB_IMM;
            //flush_id=0;

            rs1_sel = 0; // choose reg
            rs2_sel = 0; // choose reg
    
        end
        `OPCODE_AUIPC : begin
            //$display("BRANCH");
            //mem_r = 0;
            mem_w = 0;

            reg_write = 1; // store in register

            wb_sel = `WB_ALU;
            //flush_id=0;

            rs1_sel = 1; // choose PC
            rs2_sel = 1; // choose rs IMM
    
        end

        
        default                 : begin
            //mem_r = 0;
            mem_w = 0;

            reg_write = 0;
            //flush_id=0;

            wb_sel = `WB_ND; // not needed

            rs1_sel = 0; 
            rs2_sel = 0; 
        end
        endcase  
    end


endmodule