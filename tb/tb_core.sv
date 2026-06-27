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
  $dumpfile("waves.vcd");
    $dumpvars(0, tb_core);  // 0 = dump all levels
	rst_n = 0;
    clk = 0;
    //$monitor("INSTR=%b", instr);
    reset_release();
    //#10 core.stall=1;
    //#10 core.stall=0;
  #220;
    $finish;
end

int i=0;
always #5 clk = ~clk;

int y=0;

assign y=core.regfile.regs[10];

always @(posedge clk) begin
  $display("CYCLE=%d",i);
  $display("---------------------------");
  $display("STAGE IF : PC=%0h INSTR=%0h IS_STALLING=%0d", core.pc_if, core.instr_if,core.stall);
  $display("REG_FILE : x10=%0d x12=%0d x14=%0d x16=%0d", core.regfile.regs[5'b01010], core.regfile.regs[5'b01100], core.regfile.regs[5'b01110], core.regfile.regs[5'b10000]);
  $display("---------------------------");
  $display("STAGE ID : PC=%0h INSTR=%0h OPCODE=%0b", core.pc_id, core.instr_id, core.opcode_id);
  $display("---------------------------");
  $display("STAGE EX : PC=%0h ALU_IN_A=%0d ALU_IN_B=%0d, IMM=%0d, RS2_SEL=%0d", core.pc_ex,core.alu_operand_a_ex, core.alu_operand_b_ex, core.imm_ex,core.rs2_sel_ex);
  $display("---------------------------");
  $display("STAGE WB : PC=%0h", core.pc_wb);
  $display("---------------------------");
  i=i+1;
  
end

endmodule