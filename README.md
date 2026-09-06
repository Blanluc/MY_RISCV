# FPGA IMPLEMENTATION OF RISC-V CORE

This branch contains the adapted core.
Adaptation was needed for Vidado to infer BRAM instead of LUTs for the memory (rom + ram), which exceed the resource limit.

## What are the changes?

I still haven't completely figured out what makes Vivado infer a type of memory over another.
However, [Daniel Mangum](https://danielmangum.com/posts/when-vivado-infer-bram/)'s site lead me to understand that
I could ensure BRAM utilization by keeping the memory rtl as simple and as close to the rtl that Vivado generates
for its block memory IP.

I therefore had to remove all logic such as masking, shifting, sign extensions and alignment outside of the memory modules, moving it to the memory controller.
This lead to a significant complication of the system, especially in the case of sub-word writes, which now have to first
issue a read to obtain the data previously present in a word, to then write it back with the new written data.

This also significantly increased the critical path, leading me to divide the clock period by two until I can figure out possible
optimizations.

## How to use it?

1. Clone the repo
```bash
git clone https://github.com/Blanluc/MY_RISCV.git
```
2. Switch to FPGA_IMPLEMENTATION branch
```bash
git checkout FPGA_IMPLEMENTATION
```
3. Create a new project in Vivado
4. Add sources
   All the needed sources are in the sources directory. Make sure that the headers folder is also correctly added. The sources currently include the file rom.mem,
   which serves to initialize both rom & ram for the add test from the [RISC-V Architectural Certification Tests](https://github.com/riscv/riscv-arch-test) repo.

5. Add test bench (tb_core.sv in tb directory)
6. Add constraints
  This will depend on the board you are using. In my case, I'm using the PYNQ-Z1, and I configured the constraint file (in the constrain folder) accordingly.
  I decided to use the SPI interface for my UART, since I only had female-to-female cables. Since I only have a transmitter, I only had to wire the MOSI pin to my uart output and will be
  using the existing ground pin.

  One can also omit the uart, and simply modify the rtl so that a led will turn on or off depending on if the test passes or fail. (To see pass/fail condition, look at tb/tb_core.sv).

## My Setup

- FPGA : PYNQ-Z1 from Diligent
- Vivado 2024.1
- UART to USB adapter + cables

## WIP

As previously mention, adapting the core for FPGA synthesis lead to important changes in the architecture, notably the switch from asynchronous to synchronous memory, 
which brought new challenges that I wasn't expecting to encounter. As a result, some of the rtl is rather confusing and the minimum clock period increased considerably.

The current memory size is also larger that needed (RAM at 256kb). This is due to the fact that I haven't really looked into the test configuration files
yet, and the generated test code depends on memory size/ linker script. I also haven't implemented proper memory mapped I/O in the memory controller.
For these reasons, the memory is currently larger than what it needs to be, and might exceed the available resources fore some FPGAs.

## Contact

email : lucacaballerocusin@gmail.com
