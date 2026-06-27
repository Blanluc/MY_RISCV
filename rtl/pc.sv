// program counter

module pc (
    input  logic        clk,
    input  logic        rst_n,

    output logic        imem_en,

    input  logic        stall,
    //output  logic  [31:0]    pc_prev_q,
    //input  logic        pc_prev_d,

    input  logic [31:0] pc_d, // next pc
    output logic [31:0] pc_q   // input
);

    initial begin
        pc_q='0;
        //pc_prev_q='0;
        imem_en='0;
    end
    
    // pc logic
    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin// rst_n is active low
        pc_q <= '0;
        //pc_prev_q <= '0;
        imem_en<='0;
    end
    else if (stall)
        pc_q <= pc_q;
    else
        pc_q <= pc_d;
        //pc_prev_q <= pc_q -4;
        imem_en<='1;
    end

endmodule