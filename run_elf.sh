#!/bin/bash
# Usage: run_elf.sh <elf_path>

ELF=$1
SIMDIR=~/MY_RISCV

# Convert ELF to hex
riscv64-unknown-elf-objcopy -O binary "$ELF" /tmp/riscv_test.bin
python3 -c "
import struct
data = open('/tmp/riscv_test.bin','rb').read()
[print('%08x' % struct.unpack_from('<I',data,i)[0]) for i in range(0,len(data),4)]
" > $SIMDIR/sw/rom.hex

# Run sim and capture output
OUTPUT=$($SIMDIR/obj_dir/Vtb_core 2>&1)

# Check result
if echo "$OUTPUT" | grep -q "PASS"; then
    echo "RVCP-SUMMARY: TEST PASSED - Test File \"$(basename $ELF)\""
    exit 0
else
    echo "RVCP-SUMMARY: TEST FAILED - Test File \"$(basename $ELF)\""
    echo "$OUTPUT" | tail -5
    exit 1
fi