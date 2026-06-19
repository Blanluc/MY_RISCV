// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_regfile.h for the primary calling header

#include "Vtb_regfile__pch.h"

VlCoroutine Vtb_regfile___024root___eval_initial__TOP__Vtiming__0(Vtb_regfile___024root* vlSelf);
VlCoroutine Vtb_regfile___024root___eval_initial__TOP__Vtiming__1(Vtb_regfile___024root* vlSelf);

void Vtb_regfile___024root___eval_initial(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_initial\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_regfile___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_regfile___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtb_regfile___024root___eval_initial__TOP__Vtiming__0(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ tb_regfile__DOT__r_addr2;
    tb_regfile__DOT__r_addr2 = 0;
    // Body
    vlSelfRef.tb_regfile__DOT__clk = 0U;
    vlSelfRef.tb_regfile__DOT__w_en = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         36);
    vlSelfRef.tb_regfile__DOT__r_addr1 = 0U;
    tb_regfile__DOT__r_addr2 = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         38);
    VL_WRITEF_NX("R_ADDR=%d R_OUT=%0h\nR_ADDR=%d R_OUT=%0h\n",4
                 , '#',5,vlSelfRef.tb_regfile__DOT__r_addr1
                 , '#',32,vlSelfRef.tb_regfile__DOT__r_data1
                 , '#',5,(IData)(tb_regfile__DOT__r_addr2)
                 , '#',32,(vlSelfRef.tb_regfile__DOT__regfile__DOT__regs
                           [tb_regfile__DOT__r_addr2] 
                           & (- (IData)((0U != (IData)(tb_regfile__DOT__r_addr2))))));
    vlSelfRef.tb_regfile__DOT__w_data = 5U;
    vlSelfRef.tb_regfile__DOT__w_en = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         42);
    vlSelfRef.tb_regfile__DOT__w_addr = 2U;
    VL_WRITEF_NX("WRITING : REG=%d DATA=%0h\n",2, '#',5,vlSelfRef.tb_regfile__DOT__w_addr
                 , '#',32,vlSelfRef.tb_regfile__DOT__w_data);
    vlSelfRef.tb_regfile__DOT__r_addr1 = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_regfile.sv", 
                                         45);
    VL_WRITEF_NX("R_ADDR=%d R_OUT=%0h\n",2, '#',5,vlSelfRef.tb_regfile__DOT__r_addr1
                 , '#',32,vlSelfRef.tb_regfile__DOT__r_data1);
    VL_FINISH_MT("tb/tb_regfile.sv", 46, "");
    co_return;
}

VlCoroutine Vtb_regfile___024root___eval_initial__TOP__Vtiming__1(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb/tb_regfile.sv", 
                                             50);
        vlSelfRef.tb_regfile__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_regfile__DOT__clk)));
    }
    co_return;
}

void Vtb_regfile___024root___eval_triggers_vec__act(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_triggers_vec__act\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.tb_regfile__DOT__clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_regfile__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_regfile__DOT__clk__0 
        = vlSelfRef.tb_regfile__DOT__clk;
}

bool Vtb_regfile___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_regfile___024root___act_sequent__TOP__0(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___act_sequent__TOP__0\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_regfile__DOT__r_data1 = (vlSelfRef.tb_regfile__DOT__regfile__DOT__regs
                                          [vlSelfRef.tb_regfile__DOT__r_addr1] 
                                          & (- (IData)(
                                                       (0U 
                                                        != (IData)(vlSelfRef.tb_regfile__DOT__r_addr1)))));
}

void Vtb_regfile___024root___eval_act(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_act\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.tb_regfile__DOT__r_data1 = (vlSelfRef.tb_regfile__DOT__regfile__DOT__regs
                                              [vlSelfRef.tb_regfile__DOT__r_addr1] 
                                              & (- (IData)(
                                                           (0U 
                                                            != (IData)(vlSelfRef.tb_regfile__DOT__r_addr1)))));
    }
}

void Vtb_regfile___024root___nba_sequent__TOP__0(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___nba_sequent__TOP__0\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__tb_regfile__DOT__regfile__DOT__regs__v0;
    __VdlyVal__tb_regfile__DOT__regfile__DOT__regs__v0 = 0;
    CData/*4:0*/ __VdlyDim0__tb_regfile__DOT__regfile__DOT__regs__v0;
    __VdlyDim0__tb_regfile__DOT__regfile__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_regfile__DOT__regfile__DOT__regs__v0;
    __VdlySet__tb_regfile__DOT__regfile__DOT__regs__v0 = 0;
    // Body
    __VdlySet__tb_regfile__DOT__regfile__DOT__regs__v0 = 0U;
    if (((IData)(vlSelfRef.tb_regfile__DOT__w_en) & 
         (0U != (IData)(vlSelfRef.tb_regfile__DOT__w_addr)))) {
        __VdlyVal__tb_regfile__DOT__regfile__DOT__regs__v0 
            = vlSelfRef.tb_regfile__DOT__w_data;
        __VdlyDim0__tb_regfile__DOT__regfile__DOT__regs__v0 
            = vlSelfRef.tb_regfile__DOT__w_addr;
        __VdlySet__tb_regfile__DOT__regfile__DOT__regs__v0 = 1U;
    }
    if (__VdlySet__tb_regfile__DOT__regfile__DOT__regs__v0) {
        vlSelfRef.tb_regfile__DOT__regfile__DOT__regs[__VdlyDim0__tb_regfile__DOT__regfile__DOT__regs__v0] 
            = __VdlyVal__tb_regfile__DOT__regfile__DOT__regs__v0;
    }
}

void Vtb_regfile___024root___eval_nba(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_nba\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vinline__nba_sequent__TOP__0___VdlyVal__tb_regfile__DOT__regfile__DOT__regs__v0;
    __Vinline__nba_sequent__TOP__0___VdlyVal__tb_regfile__DOT__regfile__DOT__regs__v0 = 0;
    CData/*4:0*/ __Vinline__nba_sequent__TOP__0___VdlyDim0__tb_regfile__DOT__regfile__DOT__regs__v0;
    __Vinline__nba_sequent__TOP__0___VdlyDim0__tb_regfile__DOT__regfile__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__0___VdlySet__tb_regfile__DOT__regfile__DOT__regs__v0;
    __Vinline__nba_sequent__TOP__0___VdlySet__tb_regfile__DOT__regfile__DOT__regs__v0 = 0;
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__0___VdlySet__tb_regfile__DOT__regfile__DOT__regs__v0 = 0U;
        if (((IData)(vlSelfRef.tb_regfile__DOT__w_en) 
             & (0U != (IData)(vlSelfRef.tb_regfile__DOT__w_addr)))) {
            __Vinline__nba_sequent__TOP__0___VdlyVal__tb_regfile__DOT__regfile__DOT__regs__v0 
                = vlSelfRef.tb_regfile__DOT__w_data;
            __Vinline__nba_sequent__TOP__0___VdlyDim0__tb_regfile__DOT__regfile__DOT__regs__v0 
                = vlSelfRef.tb_regfile__DOT__w_addr;
            __Vinline__nba_sequent__TOP__0___VdlySet__tb_regfile__DOT__regfile__DOT__regs__v0 = 1U;
        }
        if (__Vinline__nba_sequent__TOP__0___VdlySet__tb_regfile__DOT__regfile__DOT__regs__v0) {
            vlSelfRef.tb_regfile__DOT__regfile__DOT__regs[__Vinline__nba_sequent__TOP__0___VdlyDim0__tb_regfile__DOT__regfile__DOT__regs__v0] 
                = __Vinline__nba_sequent__TOP__0___VdlyVal__tb_regfile__DOT__regfile__DOT__regs__v0;
        }
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.tb_regfile__DOT__r_data1 = (vlSelfRef.tb_regfile__DOT__regfile__DOT__regs
                                              [vlSelfRef.tb_regfile__DOT__r_addr1] 
                                              & (- (IData)(
                                                           (0U 
                                                            != (IData)(vlSelfRef.tb_regfile__DOT__r_addr1)))));
    }
}

void Vtb_regfile___024root___timing_resume(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___timing_resume\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_regfile___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_regfile___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_regfile___024root___eval_phase__act(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_phase__act\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_regfile___024root___eval_triggers_vec__act(vlSelf);
    Vtb_regfile___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_regfile___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_regfile___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_regfile___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_regfile___024root___timing_resume(vlSelf);
        Vtb_regfile___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_regfile___024root___eval_phase__inact(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_phase__inact\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb/tb_regfile.sv", 7, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_regfile___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_regfile___024root___eval_phase__nba(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_phase__nba\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_regfile___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_regfile___024root___eval_nba(vlSelf);
        Vtb_regfile___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_regfile___024root___eval(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_regfile___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/tb_regfile.sv", 7, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb/tb_regfile.sv", 7, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_regfile___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb/tb_regfile.sv", 7, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_regfile___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_regfile___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_regfile___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb_regfile___024root___eval_debug_assertions(Vtb_regfile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_regfile___024root___eval_debug_assertions\n"); );
    Vtb_regfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
