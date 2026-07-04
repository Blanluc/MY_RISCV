// instruction fetch stage

// this is a register

module if_id_reg (
    input  logic        clk,
    input  logic        rst_n,

    input  logic        stall,

    input  logic        flush_id, //particular, is an imput

    input  logic [31:0] pc_if,
    input  logic [31:0] pc_plus_4_if,
    input  logic [31:0] instr_if,

    output  logic [31:0] pc_id,
    output  logic [31:0] pc_plus_4_id,
    output  logic [31:0] instr_id
);

    // instantiate our memory // TODO : Will do in top lvl
    // imem u_imem (
    //     .clk  (clk),
    //     .addr (pc),
    //     .instr(instr) // instr is already wired through the imem, dont need to do anything here
    // );

    // TODO : I think this will be moved somewhere else
    // pc logic
    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin// rst_n is active low
        pc_id <= '0;
        pc_plus_4_id <= '0;
        instr_id <= '0;
    end
    else if (flush_id) begin
        pc_id <= '0;
        pc_plus_4_id <= '0;
        instr_id <= '0;
    end
    else if (stall) begin
        pc_id <= pc_id;
        pc_plus_4_id <= pc_plus_4_id;
        instr_id <= instr_id;
    end
    else begin
        pc_id <= pc_if;
        pc_plus_4_id <= pc_plus_4_if;
        instr_id <= instr_if;
    end
    end

endmodule