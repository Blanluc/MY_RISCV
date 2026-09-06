// https://chipverify.com/verilog/verilog-testbench

// Note that top level testbench module does not need any IO ports and
// hence can be empty and is usually called "tb" or "tb_top", but it can be
// named anything.

/* verilat --binary -j 0 --top tb_core -Irtl -Itb rtl/core.sv tb/tb_core.sv */

module tb_core;

	// All testbench code goes inside this module

reg 	    clk;
reg         rst_n; 		// To drive input "rstn" of the DUT
reg         uart_tx_o;


core core (	.clk  (clk),
			.rst_n (rst_n),	  
            .uart_tx_o (uart_tx_o)  
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
    //$monitor("INSTR=%b", core.instr_id);
    reset_release();
    //#10 core.stall=1;
    //#10 core.stall=0;
  //#1000000;
    // for (int x = 0; x < 16; x++) begin
    // $display("dmem[%0d] = %h", x, core.main_mem.mem[x]);
    //$finish;
end
    
    



int i=0;
always #5 clk = ~clk;

//int y=0;

//assign y=core.regfile.regs[10];

// always @(posedge clk) begin
//   $display("CYCLE=%d",i);
//   $display("---------------------------");
//   $display("STAGE IF : PC=%0h INSTR=%0b IS_STALLING=%0d", core.pc_if, core.instr_if ,core.stall);
//   $display("REG_FILE : a0=%0d a1=%0d a2=%0d ", core.regfile.regs[10], core.regfile.regs[11], core.regfile.regs[12]);
//   $display("---------------------------");
//   $display("STAGE ID : PC=%0h INSTR=%0h OPCODE=%0b", core.pc_id, core.instr_id, core.opcode_id);
//   $display("---------------------------");
//   $display("STAGE EX : PC=%0h ALU_IN_A=%0d ALU_IN_B=%0d, IMM=%0d, RS2_SEL=%0d", core.pc_ex,core.alu_operand_a_ex, core.alu_operand_b_ex, core.imm_ex,core.rs2_sel_ex);
//   $display("---------------------------");
//   $display("STAGE WB : PC=%0h", core.pc_wb);
//   $display("---------------------------");
//   $display("DMEM: we=%b addr=%0d wdata=%h", 
//     core.main_mem.dram_write_en,
//     core.main_mem.dram_addr,
//     core.main_mem.dram_w_data);
//   i=i+1;
  
// end

// always @(posedge clk) begin
//     if (core.pc_id == 32'h00004100) begin
//         $display("AT 4100 (pc id): gp=%0h sp=%0h", 
//             core.regfile.regs[3],   // gp = x3
//             core.regfile.regs[2]);  // sp = x2
//     end
// end

// always @(posedge clk) begin
//     if (core.pc_ex == 32'h00004110) begin
//         $display("ADD: a=%0h b=%0h result=%0h expected=%0h",
//             core.alu_operand_a_ex,
//             core.alu_operand_b_ex,
//             core.alu_result_ex,
//             core.regfile.regs[4]);  // tp = expected
//     end
// end

// always @(posedge clk) begin
//     if (core.pc_ex > 32'h00004100 || core.pc_ex < 32'h0000410c) begin
//         $display("AT PC = %h : gp=%0h sp=%0h", 
//             core.ram.ram
//             core.regfile.regs[3],   // gp = x3
//             core.regfile.regs[2]);  // sp = x2
//     end
// end

int cycle_count = 0;
always @(posedge clk) begin
  //$display("T=%0t A0_REGFILE=%h", $time, core.regfile.regs[10]);
    cycle_count <= cycle_count + 1;
    if (cycle_count >= 1000000) begin
    //if (cycle_count >= 40) begin
        $display("a0=%0h a1=%0h a2=%0h a3=%0h", core.regfile.regs[10], core.regfile.regs[11], core.regfile.regs[12], core.regfile.regs[13]);
        $display("a4=0x%0h a5=0x%0h a6=0x%0h a7=0x%0h", core.regfile.regs[14], core.regfile.regs[15], core.regfile.regs[16], core.regfile.regs[17]);
        $display("s2=0x%0h s3=%0h s4=%0h s5=%0h", core.regfile.regs[18], core.regfile.regs[19], core.regfile.regs[20], core.regfile.regs[21]);
        $display("s6=%0h s7=%0h s8=%0h s9=%0h s10=%0h", core.regfile.regs[22], core.regfile.regs[23], core.regfile.regs[24], core.regfile.regs[25], core.regfile.regs[26]);
         $display("TIMEOUT");
        $finish;
    end
end

//Halt detection
// Halt detection
// always @(posedge clk) begin
//     if (core.mem_w_mem1 && core.alu_result_mem1 == 32'h20000000) begin
//         $display("RVCP-SUMMARY: TEST PASSED");
//         $finish;
//     end
// end

// always_comb begin
//         if (core.ram.w_addr==32'h20ca) begin
//             $display("PC MEM : = %h",core.pc_mem1);
//             $display("Data in mem = %h",core.ram.ram[32'h20ca]);
//         end
//     end

// logic [31:0] prev;

always @(posedge clk) begin
    if (core.mem_controller.addr_in == 32'h20000000 && core.mem_controller.write_en_in) begin
        if (core.mem_controller.store_data == 32'h075BCD15) begin
            $display("RVCP-SUMMARY: TEST PASSED");
        end else begin
            $display("RVCP-SUMMARY: TEST FAILED (Exit Code: 0x%h)", core.mem_controller.store_data);
        end
        //$finish;
    end
end




endmodule