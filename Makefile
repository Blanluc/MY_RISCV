sim:
	rm -rf obj_dir
	verilator --binary --trace -j 0 --top tb_core -Irtl -Itb \
	  rtl/core.sv \
	  rtl/control_unit.sv \
	  rtl/decoder.sv \
	  rtl/alu.sv \
	  rtl/regfile.sv \
	  rtl/main_mem.sv \
	  rtl/pc.sv \
	  rtl/id_ex_reg.sv \
	  rtl/if_id_reg.sv \
	  rtl/ex_mem_reg.sv \
	  rtl/alu_controller.sv \
	  rtl/mem_wb_reg.sv \
	  rtl/hazard_unit.sv \
	  rtl/mem_controller.sv \
	  rtl/pc_controller.sv \
	  rtl/branch_unit.sv \
	  rtl/uart.sv \
	  tb/tb_core.sv

run:
	make -C sw TEST=$(TEST) clean && make -C sw TEST=$(TEST)
	cp sw/$(TEST).hex sw/rom.hex
	make sim
	./obj_dir/Vtb_core



RV32UI_DIR = sw/I
RISCV_ENV  = $(HOME)/riscv-tests/env/p
RISCV_MACROS = $(HOME)/riscv-tests/isa/macros/scalar
RV32UI_TESTS = add addi and andi auipc beq bge bgeu blt bltu bne jal jalr lb lbu lh lhu lui lw or ori sb sh sll slli slt slti sltiu sltu sra srai srl srli sub sw xor xori

test_all:
	@rm -f /tmp/riscv_test /tmp/riscv_test.bin; \
	passed=0; failed=0; \
	for test in $(RV32UI_TESTS); do \
		riscv64-unknown-elf-gcc \
		  -march=rv32i -mabi=ilp32 \
		  -static -mcmodel=medany \
		  -fvisibility=hidden \
		  -nostdlib -nostartfiles \
		  -I$(HOME)/riscv-tests/env/p \
		  -I$(HOME)/riscv-tests/isa/macros/scalar \
		  -T$(HOME)/riscv-tests/env/p/link.ld \
		  sw/I/$$test.S \
		  -o /tmp/riscv_test; \
		riscv64-unknown-elf-objcopy -O binary /tmp/riscv_test /tmp/riscv_test.bin; \
		python3 -c "import struct; data=open('/tmp/riscv_test.bin','rb').read(); [print('%08x' % struct.unpack_from('<I',data,i)[0]) for i in range(0,len(data),4)]" > sw/rom.hex; \
		result=$$(./obj_dir/Vtb_core 2>&1); \
		if echo "$$result" | grep -q "PASS"; then \
			echo "PASS: $$test"; \
			passed=$$((passed+1)); \
		else \
			echo "FAIL: $$test"; \
			failed=$$((failed+1)); \
		fi; \
		rm -f /tmp/riscv_test /tmp/riscv_test.bin; \
	done; \
	echo "----------------------------"; \
	echo "Results: $$passed passed, $$failed failed"