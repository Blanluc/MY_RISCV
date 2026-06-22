// program counter

module pc (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] pc_d, // next pc
    output logic [31:0] pc_q   // input
);
    
    // pc logic
    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) // rst_n is active low
        pc_q <= '0;
    else
        pc_q <= pc_d;
    end

endmodule