// register file

module regfile (
    input  logic        clk,
    input  logic [4:0]  w_addr,
    input  logic [31:0] w_data,
    input  logic        w_en,
    input  logic [4:0]  r_addr1,
    output logic [31:0] r_data1,
    input  logic [4:0]  r_addr2,
    output logic [31:0] r_data2
);
    logic [31:0] regs [31:0];

    always_ff @(posedge clk) begin
        if (w_en && w_addr !=0) begin
            regs[w_addr] <= w_data;
        end
    end

    // so we don't lose cycles on read
    assign r_data1 = (r_addr1 == '0) ? '0 : regs[r_addr1];
    assign r_data2 = (r_addr2 == '0) ? '0 : regs[r_addr2];

endmodule