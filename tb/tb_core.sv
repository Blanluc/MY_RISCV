// https://chipverify.com/verilog/verilog-testbench

// Note that top level testbench module does not need any IO ports and
// hence can be empty and is usually called "tb" or "tb_top", but it can be
// named anything.

/* verilat --binary -j 0 --top tb_core -Irtl -Itb rtl/core.sv tb/tb_core.sv */

module tb_core;

	// All testbench code goes inside this module

reg 	    clk;
reg         rst_n; 		// To drive input "rstn" of the DUT

core core (	.clk  (clk),
			.rst_n (rst_n)	    
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
  #40;
    $finish;
end


always #5 clk = ~clk;

always @(posedge clk) begin
  $display("STAGE IF : PC=%0h INSTR=%0h", core.pc_if, core.instr_if);
  $display("---------------------------");
  $display("STAGE ID : PC=%0h INSTR=%0h OPCODE=%0b", core.pc_id, core.instr_id, core.opcode_id);
  $display("---------------------------");
  $display("STAGE EX : PC=%0h INSTR=%0h OPCODE=%0b", core.pc_ex, core.instr_id, core.opcode_ex);
  $display("---------------------------");
end

endmodule