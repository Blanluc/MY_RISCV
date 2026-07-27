// https://chipverify.com/verilog/verilog-testbench

//  ./obj_dir/Vtb_core_tests

// Note that top level testbench module does not need any IO ports and
// hence can be empty and is usually called "tb" or "tb_top", but it can be
// named anything.

/* verilat --binary -j 0 --top tb_core -Irtl -Itb rtl/core.sv tb/tb_core.sv */

// (base) lucacaba@student-net-etx-3110 MY_RISCV % verilator --binary --trace -j 0 --top tb_core_tests -Irtl -Itb \
//   rtl/core.sv \
//   rtl/control_unit.sv \
//   rtl/decoder.sv \
//   rtl/alu.sv \
//   rtl/regfile.sv \
//   rtl/imem.sv \
//   rtl/dmem.sv \
//   rtl/pc.sv \
//   rtl/id_ex_reg.sv \
//   rtl/if_id_reg.sv \rtl/ex_mem_reg.sv \rtl/alu_controller.sv \mem_wb_reg.sv \hazard_unit.sv \mem_controller.sv \pc_controller.sv \branch_unit.sv \
//   tb/tb_core_tests.sv

module tb_core_tests;

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
    $dumpvars(0, tb_core_tests);  // 0 = dump all levels
	rst_n = 0;
    clk = 0;
    //$monitor("INSTR=%b", instr);
    reset_release();
    //#10 core.stall=1;
    //#10 core.stall=0;
  #500;
    for (int x = 0; x < 16; x++) begin
    $display("main_mem[%0d] = %h", x, core.main_mem.mem[x]);
end
    $finish;
end

int i=0;
always #5 clk = ~clk;

int y=0;

assign y=core.regfile.regs[10];

// PASS/FAIL detection
    always @(posedge clk) begin
      $display("CYCLE=%d",i);
  $display("---------------------------");
  $display("STAGE IF : PC=%0h INSTR=%0b IS_STALLING=%0d", core.pc_if, core.instr_if ,core.stall);
  $display("REG_FILE : a0=%0d a1=%0d a2=%0d ", core.regfile.regs[10], core.regfile.regs[11], core.regfile.regs[12]);
  $display("---------------------------");
  $display("STAGE ID : PC=%0h INSTR=%0h OPCODE=%0b", core.pc_id, core.instr_id, core.opcode_id);
  $display("---------------------------");
  $display("STAGE EX : PC=%0h ALU_IN_A=%0d ALU_IN_B=%0d, IMM=%0d, RS2_SEL=%0d", core.pc_ex,core.alu_operand_a_ex, core.alu_operand_b_ex, core.imm_ex,core.rs2_sel_ex);
  $display("---------------------------");
  $display("STAGE WB : PC=%0h", core.pc_wb);
  $display("---------------------------");
  $display("DMEM: we=%b addr=%0d wdata=%h", 
    core.main_mem.dram_write_en,
    core.main_mem.dram_addr,
    core.main_mem.dram_w_data);
  i=i+1;
  if (core.mem_w_mem) begin
        $display("STORE: addr=0x%08x data=0x%08x", core.alu_result_mem, core.w_data_mem);
    end
        if (core.mem_w_mem &&
            core.alu_result_mem == 32'h80001000) begin
            if (core.w_data_mem == 32'h1)
                $display("PASS");
            else
                $display("FAIL: tohost=0x%08x", core.w_data_mem);
            $finish;
        end
    end

endmodule