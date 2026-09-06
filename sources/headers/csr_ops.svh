`ifndef CSR_OPS_SVH
`define CSR_OPS_SVH

// Atomic memory instructions are indivisible operations performed with memory like swap or add. 
// They are usually done outside of the CPU itself perhaps at the memory controller to guarantee 
// the operation will be atomic. The memory controller needs to be able to process commands given 
// to it by the CPU beyond LOAD or STORE. Normally for a CPU that only performs loads and stores 
// the two are distinguished by a write enable signal. To support atomics more signals are needed. 
// For my own CPU, I have it output a five-bit command code which includes all the atomic operations 
// in addition to load and store, also output is the data associated with the command. The memory 
// controller then takes care of the atomic part and sends back results if needed.

`define ECALL_EBREAK  3'b000
`define CSRRW   3'b001
`define CSRRS    3'b010
`define CSRRC	  3'b011
`define CSRRWI 3'b101
`define CSRRSI 3'b110 
`define CSRRCI 3'b111

`endif // CSR_OPS_SVH