// https://chipverify.com/verilog/verilog-testbench

// Note that top level testbench module does not need any IO ports and
// hence can be empty and is usually called "tb" or "tb_top", but it can be
// named anything.

module tb_fetch;

	// All testbench code goes inside this module

reg 	    clk;
reg         rst_n; 		// To drive input "rstn" of the DUT
wire [31:0] instr;

if_stage if_stage (	.clk  (clk),
				    .rst_n (rst_n),
				    .instr (instr)
			);

task reset_release();
      // Release reset
      #10 rst_n = 1;
endtask

initial begin
	rst_n = 0;
    clk = 0;
    //$monitor("INSTR=%b", instr);
    reset_release();
  #100;
    $finish;
end


always #5 clk = ~clk;

always @(posedge clk) begin
  $display("PC=%0h INSTR=%0h", if_stage.pc, instr);
end

endmodule