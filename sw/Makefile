AS      = riscv64-unknown-elf-as
LD      = riscv64-unknown-elf-ld
OBJCOPY = riscv64-unknown-elf-objcopy
OBJDUMP = riscv64-unknown-elf-objdump

ARCH    = -march=rv32i -mabi=ilp32
TEST   ?= test_1

all: $(TEST).hex

$(TEST).o: $(TEST).s
	$(AS) $(ARCH) -o $@ $<

$(TEST).elf: $(TEST).o link.ld
	$(LD) -T link.ld -m elf32lriscv -o $@ $<

$(TEST).bin: $(TEST).elf
	$(OBJCOPY) -O binary $< $@

$(TEST).hex: $(TEST).bin
	python3 -c "import struct; data=open('$<','rb').read(); [print('%08x' % struct.unpack_from('<I',data,i)[0]) for i in range(0,len(data),4)]" > $@

dump: $(TEST).elf
	$(OBJDUMP) -d -M no-aliases $<

clean:
	rm -f *.o *.elf *.bin *.hex
