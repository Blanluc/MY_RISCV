// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_alu.h for the primary calling header

#ifndef VERILATED_VTB_ALU___024ROOT_H_
#define VERILATED_VTB_ALU___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_alu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_alu___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_alu__DOT__clk;
    CData/*3:0*/ tb_alu__DOT__operator;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ tb_alu__DOT__operand_a;
    IData/*31:0*/ tb_alu__DOT__operand_b;
    IData/*31:0*/ tb_alu__DOT__result;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtb_alu__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_alu___024root(Vtb_alu__Syms* symsp, const char* namep);
    ~Vtb_alu___024root();
    VL_UNCOPYABLE(Vtb_alu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
