// instruction fetch stage

module if_stage (
    input  logic        clk,
    input  logic        rst_n,
    output logic [31:0] instr // we return the instr
);
    // program counter
    logic [31:0] pc;

    // instantiate our memory
    imem u_imem (
        .clk  (clk),
        .addr (pc),
        .instr(instr) // instr is already wired through the imem, dont need to do anything here
    );

    // pc logic
    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) // rst_n is active low
        pc <= '0;
    else
        pc <= pc+4;
    end

endmodule