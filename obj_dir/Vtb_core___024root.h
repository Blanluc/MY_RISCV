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
    CData/*0:0*/ tb_core__DOT__clk;
    CData/*0:0*/ tb_core__DOT__rst_n;
    CData/*0:0*/ tb_core__DOT__core__DOT__rs2_sel_id;
    CData/*4:0*/ tb_core__DOT__core__DOT__rs1_ex;
    CData/*4:0*/ tb_core__DOT__core__DOT__rs2_ex;
    CData/*0:0*/ tb_core__DOT__core__DOT__rs2_sel_ex;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_core__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_core__DOT__rst_n__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ tb_core__DOT__i;
    IData/*31:0*/ tb_core__DOT__core__DOT__pc_if;
    IData/*31:0*/ tb_core__DOT__core__DOT__instr_if;
    IData/*31:0*/ tb_core__DOT__core__DOT__pc_id;
    IData/*31:0*/ tb_core__DOT__core__DOT__instr_id;
    IData/*31:0*/ tb_core__DOT__core__DOT__imm_ex;
    IData/*31:0*/ tb_core__DOT__core__DOT__pc_ex;
    IData/*31:0*/ tb_core__DOT__core__DOT__src1_data_ex;
    IData/*31:0*/ tb_core__DOT__core__DOT__alu_operand_b_ex;
    IData/*31:0*/ tb_core__DOT__core__DOT__pc_wb;
    IData/*31:0*/ tb_core__DOT__core__DOT__decoder__DOT__imm_I;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_1;
    IData/*31:0*/ __Vdly__tb_core__DOT__core__DOT__pc_if;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<IData/*31:0*/, 1024> tb_core__DOT__core__DOT__u_imem__DOT__mem;
    VlUnpacked<IData/*31:0*/, 32> tb_core__DOT__core__DOT__regfile__DOT__regs;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
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
