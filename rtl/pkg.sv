package pkg;

typedef enum logic [3:0] {

    // Arithmetics
    ALU_ADD,
    ALU_SUB,

    // Logics
    ALU_XOR,
    ALU_OR,
    ALU_AND,

    // Shifts
    ALU_SRA,
    ALU_SRL,
    ALU_SLL,

    // Set lower than
    ALU_SLT,
    ALU_SLTU

  } alu_op;

  endpackage