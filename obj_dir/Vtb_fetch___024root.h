// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_fetch.h for the primary calling header

#ifndef VERILATED_VTB_FETCH___024ROOT_H_
#define VERILATED_VTB_FETCH___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_fetch__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_fetch___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_fetch__DOT__clk;
    CData/*0:0*/ tb_fetch__DOT__rst_n;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_fetch__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_fetch__DOT__rst_n__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ tb_fetch__DOT__instr;
    IData/*31:0*/ tb_fetch__DOT__if_stage__DOT__pc;
    IData/*31:0*/ __Vdly__tb_fetch__DOT__if_stage__DOT__pc;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<IData/*31:0*/, 1024> tb_fetch__DOT__if_stage__DOT__u_imem__DOT__mem;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtb_fetch__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_fetch___024root(Vtb_fetch__Syms* symsp, const char* namep);
    ~Vtb_fetch___024root();
    VL_UNCOPYABLE(Vtb_fetch___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
