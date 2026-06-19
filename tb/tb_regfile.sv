
// verilator --binary -j 0 --top tb_regfile -Irtl -Itb rtl/regfile.sv tb/tb_regfile.sv

module tb_regfile;

reg 	      clk;
logic [4:0]  w_addr;
logic [31:0] w_data;
logic        w_en;
logic [4:0]  r_addr1;
logic [31:0] r_data1;
logic [4:0]  r_addr2;
logic [31:0] r_data2;

regfile regfile (	
            .clk  (clk),
            .w_addr (w_addr),
            .w_data (w_data),
            .w_en (w_en),
            .r_addr1 (r_addr1),
            .r_data1 (r_data1),
            .r_addr2 (r_addr2),
            .r_data2 (r_data2)
			);


initial begin
    clk = 0;
    w_en =0;
    #10 r_addr1 = 0;
    r_addr2 = 1;
    #10 $display("R_ADDR=%d R_OUT=%0h", r_addr1, r_data1);
    $display("R_ADDR2 (uninit)=%d R_OUT2=%0h", r_addr2, r_data2);
    w_data = 5;
    w_en =1;
    #10 w_addr = 2;
    $display("WRITING : REG=%d DATA=%0h", w_addr, w_data);
    r_addr1 = 2;
    #10 $display("R_ADDR=%d R_OUT=%0h", r_addr1, r_data1);
    $finish;
end


always #5 clk = ~clk;


endmodule