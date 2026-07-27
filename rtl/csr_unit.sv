// CONTROL UNIT
`include "headers/opcodes.svh"
`include "headers/wb_sel.svh"
module csr_unit (
    input  logic [2:0] funct3,
    input  logic [6:0] opcode,
    input  logic [31:0] src1_in, // can be reg val or zimm // take both? And decide later // I dont think I need it
    input  logic [31:0] csr_in,

    //output  logic [31:0] src1_out, I dont think I need this
    output  logic [31:0] csr_out
);

    // internal signals
    //logic [6:0]  opcode;
    //assign opcode=instr[6:0];
    //logic [2:0]  funct3;
    //assign funct3=instr[14:12];

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

       
        case (funct3)

        `CSRRW,`CSRRS,`CSRRC: begin
            
        end

        `CSRRWI,`CSRRSI,`CSRRCI: begin
            
        end

        default : begin
            
        end

        endcase

    end
    
        


endmodule