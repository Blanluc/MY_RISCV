// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_core.h for the primary calling header

#ifndef VERILATED_VTB_CORE___024ROOT_H_
#define VERILATED_VTB_CORE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_core__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_core___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_core__DOT__clk;
        CData/*0:0*/ tb_core__DOT__rst_n;
        CData/*0:0*/ tb_core__DOT__core__DOT__imem_en;
        CData/*0:0*/ tb_core__DOT__core__DOT__stall;
        CData/*0:0*/ tb_core__DOT__core__DOT__flush_id;
        CData/*0:0*/ tb_core__DOT__core__DOT__flush_ex;
        CData/*0:0*/ tb_core__DOT__core__DOT__mem_w_id;
        CData/*0:0*/ tb_core__DOT__core__DOT__rs2_sel_id;
        CData/*1:0*/ tb_core__DOT__core__DOT__rs1_sel_id;
        CData/*0:0*/ tb_core__DOT__core__DOT__reg_write_id;
        CData/*0:0*/ tb_core__DOT__core__DOT__csr_w_en_id;
        CData/*0:0*/ tb_core__DOT__core__DOT__csr_r_en_id;
        CData/*2:0*/ tb_core__DOT__core__DOT__wb_sel_id;
        CData/*0:0*/ tb_core__DOT__core__DOT__csr_r_en_ex;
        CData/*6:0*/ tb_core__DOT__core__DOT__opcode_ex;
        CData/*4:0*/ tb_core__DOT__core__DOT__rd_ex;
        CData/*2:0*/ tb_core__DOT__core__DOT__funct3_ex;
        CData/*6:0*/ tb_core__DOT__core__DOT__funct7_ex;
        CData/*0:0*/ tb_core__DOT__core__DOT__mem_w_ex;
        CData/*0:0*/ tb_core__DOT__core__DOT__rs2_sel_ex;
        CData/*1:0*/ tb_core__DOT__core__DOT__rs1_sel_ex;
        CData/*0:0*/ tb_core__DOT__core__DOT__reg_write_ex;
        CData/*0:0*/ tb_core__DOT__core__DOT__csr_write_ex;
        CData/*2:0*/ tb_core__DOT__core__DOT__wb_sel_ex;
        CData/*3:0*/ tb_core__DOT__core__DOT__alu_op_ex;
        CData/*0:0*/ tb_core__DOT__core__DOT__alu_zero_in_ex;
        CData/*0:0*/ tb_core__DOT__core__DOT__alu_zero_out_ex;
        CData/*4:0*/ tb_core__DOT__core__DOT__rd_wb;
        CData/*0:0*/ tb_core__DOT__core__DOT__mem_w_wb;
        CData/*0:0*/ tb_core__DOT__core__DOT__reg_write_wb;
        CData/*0:0*/ tb_core__DOT__core__DOT__csr_write_wb;
        CData/*2:0*/ tb_core__DOT__core__DOT__wb_sel_wb;
        CData/*0:0*/ tb_core__DOT__core__DOT__alu_zero_wb;
        CData/*4:0*/ tb_core__DOT__core__DOT__rd_mem;
        CData/*0:0*/ tb_core__DOT__core__DOT__mem_w_mem;
        CData/*0:0*/ tb_core__DOT__core__DOT__alu_zero_mem;
        CData/*2:0*/ tb_core__DOT__core__DOT__wb_sel_mem;
        CData/*0:0*/ tb_core__DOT__core__DOT__reg_write_mem;
        CData/*0:0*/ tb_core__DOT__core__DOT__csr_write_mem;
        CData/*6:0*/ tb_core__DOT__core__DOT__opcode_mem;
        CData/*2:0*/ tb_core__DOT__core__DOT__funct3_mem;
        CData/*4:0*/ tb_core__DOT__core__DOT__shift_amt_mem;
        CData/*0:0*/ tb_core__DOT__core__DOT__sign_extend_mem;
        CData/*0:0*/ tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump;
        CData/*0:0*/ tb_core__DOT__core__DOT__main_mem__DOT__dram_write_en_prev;
        CData/*0:0*/ tb_core__DOT__core__DOT__main_mem__DOT__msb;
        CData/*4:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex;
        CData/*4:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__rd_mem;
        CData/*0:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__rw_ex;
        CData/*0:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__rw_mem;
        CData/*4:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__rd_wb;
        CData/*0:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__rw_wb;
        CData/*0:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_ex;
        CData/*0:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_mem;
        CData/*0:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_wb;
        CData/*0:0*/ tb_core__DOT__core__DOT__alu__DOT__alu_zero_slt;
        CData/*0:0*/ tb_core__DOT__core__DOT__alu__DOT__alu_zero_sltu;
        CData/*0:0*/ tb_core__DOT__core__DOT__alu__DOT__alu_zero_and;
        CData/*0:0*/ __VdlySet__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0;
        CData/*4:0*/ __VdlyDim0__tb_core__DOT__core__DOT__regfile__DOT__regs__v0;
        CData/*0:0*/ __VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_core__DOT__clk__0;
    };
    struct {
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_core__DOT__rst_n__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VinactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*11:0*/ tb_core__DOT__core__DOT__csr_reg_ex;
        SData/*11:0*/ tb_core__DOT__core__DOT__csr_reg_wb;
        SData/*11:0*/ tb_core__DOT__core__DOT__csr_reg_mem;
        SData/*11:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__csr_ex;
        SData/*11:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__csr_mem;
        SData/*11:0*/ tb_core__DOT__core__DOT__hazard_unit__DOT__csr_wb;
        IData/*31:0*/ tb_core__DOT__y;
        IData/*31:0*/ tb_core__DOT__cycle_count;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_if;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_next;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_id;
        IData/*31:0*/ tb_core__DOT__core__DOT__instr_id;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_plus_4_id;
        IData/*31:0*/ tb_core__DOT__core__DOT__imm_id;
        IData/*31:0*/ tb_core__DOT__core__DOT__rs1_data_id;
        IData/*31:0*/ tb_core__DOT__core__DOT__zimm_id;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_content_id;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_data_ex;
        IData/*31:0*/ tb_core__DOT__core__DOT__imm_ex;
        IData/*31:0*/ tb_core__DOT__core__DOT__zimm_ex;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_ex;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_plus_4_ex;
        IData/*31:0*/ tb_core__DOT__core__DOT__rs1_data_ex;
        IData/*31:0*/ tb_core__DOT__core__DOT__rs2_data_ex;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_content_ex;
        IData/*31:0*/ tb_core__DOT__core__DOT__alu_result_ex;
        IData/*31:0*/ tb_core__DOT__core__DOT__alu_operand_b_ex;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_wb;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_data_wb;
        IData/*31:0*/ tb_core__DOT__core__DOT__lui_wb;
        IData/*31:0*/ tb_core__DOT__core__DOT__alu_result_wb;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_plus_4_wb;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_content_wb;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_mem;
        IData/*31:0*/ tb_core__DOT__core__DOT__lui_mem;
        IData/*31:0*/ tb_core__DOT__core__DOT__rs2_data_mem;
        IData/*31:0*/ tb_core__DOT__core__DOT__alu_result_mem;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_plus_4_mem;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_content_mem;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_data_mem;
        IData/*31:0*/ tb_core__DOT__core__DOT__w_data_mem;
        IData/*31:0*/ tb_core__DOT__core__DOT__bit_mask_mem;
        IData/*31:0*/ tb_core__DOT__core__DOT__r_data_wb;
        IData/*31:0*/ tb_core__DOT__core__DOT__pc_controller__DOT__jalr_target_raw;
        IData/*31:0*/ tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw;
        IData/*31:0*/ tb_core__DOT__core__DOT__main_mem__DOT__shifted_mask;
        IData/*31:0*/ tb_core__DOT__core__DOT__decoder__DOT__imm_I;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__misa;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mvendorid;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mimpid;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__marchid;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mhartid;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mie;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mip;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mstatus;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mtvec;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mepc;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mcause;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mscratch;
        IData/*31:0*/ tb_core__DOT__core__DOT__csr_file__DOT__mtval;
    };
    struct {
        IData/*31:0*/ tb_core__DOT__core__DOT__alu__DOT__add_output;
        IData/*31:0*/ tb_core__DOT__core__DOT__alu__DOT__sub_output;
        IData/*31:0*/ tb_core__DOT__core__DOT__alu__DOT__slt_output;
        IData/*31:0*/ tb_core__DOT__core__DOT__alu__DOT__sltu_output;
        IData/*31:0*/ __VdlyVal__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0;
        IData/*17:0*/ __VdlyDim0__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0;
        IData/*31:0*/ __VdlyVal__tb_core__DOT__core__DOT__regfile__DOT__regs__v0;
        IData/*31:0*/ __VactIterCount;
        IData/*31:0*/ __VinactIterCount;
        IData/*31:0*/ __Vi;
        VlUnpacked<IData/*31:0*/, 262144> tb_core__DOT__core__DOT__main_mem__DOT__mem;
        VlUnpacked<IData/*31:0*/, 32> tb_core__DOT__core__DOT__regfile__DOT__regs;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtb_core__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_core___024root(Vtb_core__Syms* symsp, const char* namep);
    ~Vtb_core___024root();
    VL_UNCOPYABLE(Vtb_core___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
