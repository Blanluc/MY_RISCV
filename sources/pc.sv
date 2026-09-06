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
    
    // pc logic
    always_ff @(posedge clk or negedge rst_n) begin
        //$display("PC IN : %h",pc_d);
    if (!rst_n) begin// rst_n is active low
        pc_q <= 32'h00004000;
        //pc_q <= 32'h00000000;
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