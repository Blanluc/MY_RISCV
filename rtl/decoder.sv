// decoder
module decoder (
    input  logic [31:0] instr,
    output logic [6:0]  opcode,
    output logic [4:0]  rd,
    output logic [2:0]  funct3,
    output logic [6:0]  funct7,
    output logic [4:0]  rs1,
    output logic [4:0]  rs2,
    output logic [31:0] imm
);

    // INSTRUCTION FORMATS : RISUJ

    // how to decode efficiently (least cycles)?

    // Idea : Decode for all instr format and chose at the end
    
    // MAPPING :
    // logic [6:0]  opcode;
    // logic [4:0]  rd;
    // logic [2:0]  funct3;
    // logic [6:0]  funct7;
    // logic [4:0]  rs1;
    // logic [4:0]  rs2;

    logic [31:0]  imm_I;
    logic [31:0]  imm_S;
    logic [31:0]  imm_B;
    logic [31:0]  imm_U;
    logic [31:0]  imm_J;

    // Fixed fields
    assign opcode=instr[6:0];
    assign rd=instr[11:7];
    assign funct3=instr[14:12];
    assign funct7=instr[31:25];
    assign rs1=instr[19:15];
    assign rs2=instr[24:20];

    // Types of Imm depending on format
    assign imm_I = {{21{instr[31]}}, instr[30:20]};
    assign imm_S = {{21{instr[31]}}, instr[30:25], instr[11:8], instr[7]};
    assign imm_B = {{20{instr[31]}}, instr[7],instr[30:25], instr[11:8], 1'b0};
    assign imm_U = {instr[31:12], 12'b0};
    assign imm_J = {{12{instr[31]}}, instr[19:12],instr[20], instr[30:21], 1'b0};

    always_comb begin

        case(opcode[6:2])

        // LOAD / OP-IMM / JALR
        5'b00000, 5'b00100, 5'b11001 : imm = imm_I;

        // STORE
        5'b01000                   : imm = imm_S;

        // LUI / AUIPC
        5'b01101 , 5'b00101        : imm = imm_U;

        // BRANCH
        5'b11000                   : imm = imm_B;

        // JAL
        5'b11011                   : imm = imm_J;

        // DEFAULT
        default                 : imm = imm_I;
        endcase  
    end


endmodule