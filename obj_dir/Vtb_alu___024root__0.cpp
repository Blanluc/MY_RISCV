// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_alu.h for the primary calling header

#include "Vtb_alu__pch.h"

VlCoroutine Vtb_alu___024root___eval_initial__TOP__Vtiming__0(Vtb_alu___024root* vlSelf);
VlCoroutine Vtb_alu___024root___eval_initial__TOP__Vtiming__1(Vtb_alu___024root* vlSelf);

void Vtb_alu___024root___eval_initial(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval_initial\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_alu___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_alu___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtb_alu___024root___eval_initial__TOP__Vtiming__0(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_alu__DOT__clk = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         22);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         23);
    vlSelfRef.tb_alu__DOT__operator = 0U;
    vlSelfRef.tb_alu__DOT__operand_a = 0x00000010U;
    vlSelfRef.tb_alu__DOT__operand_b = 0x0000000aU;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         26);
    VL_WRITEF_NX("OP=%b (ADD) OP1=%0d OP2=%0d RES=%0d\n",4
                 , '#',4,vlSelfRef.tb_alu__DOT__operator
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_a
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_b
                 , '#',32,vlSelfRef.tb_alu__DOT__result);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         27);
    vlSelfRef.tb_alu__DOT__operator = 1U;
    vlSelfRef.tb_alu__DOT__operand_a = 0x00000010U;
    vlSelfRef.tb_alu__DOT__operand_b = 0x0000000aU;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         30);
    VL_WRITEF_NX("OP=%b (SUB) OP1=%0d OP2=%0d RES=%0d\n",4
                 , '#',4,vlSelfRef.tb_alu__DOT__operator
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_a
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_b
                 , '#',32,vlSelfRef.tb_alu__DOT__result);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         31);
    vlSelfRef.tb_alu__DOT__operator = 2U;
    vlSelfRef.tb_alu__DOT__operand_a = 7U;
    vlSelfRef.tb_alu__DOT__operand_b = 0x0000000aU;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         34);
    VL_WRITEF_NX("OP=%b (XOR) OP1=%0b OP2=%0b RES=%0b\n",4
                 , '#',4,vlSelfRef.tb_alu__DOT__operator
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_a
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_b
                 , '#',32,vlSelfRef.tb_alu__DOT__result);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         35);
    vlSelfRef.tb_alu__DOT__operator = 3U;
    vlSelfRef.tb_alu__DOT__operand_a = 7U;
    vlSelfRef.tb_alu__DOT__operand_b = 0x0000000aU;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         38);
    VL_WRITEF_NX("OP=%b (OR) OP1=%0b OP2=%0b RES=%0b\n",4
                 , '#',4,vlSelfRef.tb_alu__DOT__operator
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_a
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_b
                 , '#',32,vlSelfRef.tb_alu__DOT__result);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         39);
    vlSelfRef.tb_alu__DOT__operator = 4U;
    vlSelfRef.tb_alu__DOT__operand_a = 7U;
    vlSelfRef.tb_alu__DOT__operand_b = 0x0000000aU;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         42);
    VL_WRITEF_NX("OP=%b (AND) OP1=%0b OP2=%0b RES=%0b\n",4
                 , '#',4,vlSelfRef.tb_alu__DOT__operator
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_a
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_b
                 , '#',32,vlSelfRef.tb_alu__DOT__result);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         43);
    vlSelfRef.tb_alu__DOT__operator = 5U;
    vlSelfRef.tb_alu__DOT__operand_a = 7U;
    vlSelfRef.tb_alu__DOT__operand_b = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         46);
    VL_WRITEF_NX("OP=%b (SRA) OP1=%0b OP2=%0d RES=%0b\n",4
                 , '#',4,vlSelfRef.tb_alu__DOT__operator
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_a
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_b
                 , '#',32,vlSelfRef.tb_alu__DOT__result);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         47);
    vlSelfRef.tb_alu__DOT__operator = 7U;
    vlSelfRef.tb_alu__DOT__operand_a = 7U;
    vlSelfRef.tb_alu__DOT__operand_b = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         50);
    VL_WRITEF_NX("OP=%b (SLL) OP1=%0b OP2=%0d RES=%0b\n",4
                 , '#',4,vlSelfRef.tb_alu__DOT__operator
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_a
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_b
                 , '#',32,vlSelfRef.tb_alu__DOT__result);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         51);
    vlSelfRef.tb_alu__DOT__operator = 6U;
    vlSelfRef.tb_alu__DOT__operand_a = 7U;
    vlSelfRef.tb_alu__DOT__operand_b = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         54);
    VL_WRITEF_NX("OP=%b (SLR) OP1=%0b OP2=%0d RES=%0b\n",4
                 , '#',4,vlSelfRef.tb_alu__DOT__operator
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_a
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_b
                 , '#',32,vlSelfRef.tb_alu__DOT__result);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         55);
    vlSelfRef.tb_alu__DOT__operator = 8U;
    vlSelfRef.tb_alu__DOT__operand_a = 1U;
    vlSelfRef.tb_alu__DOT__operand_b = 0xffffffffU;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         58);
    VL_WRITEF_NX("OP=%b (SLT) OP1=%0b OP2=%0d RES=%0b\n",4
                 , '#',4,vlSelfRef.tb_alu__DOT__operator
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_a
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_b
                 , '#',32,vlSelfRef.tb_alu__DOT__result);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         59);
    vlSelfRef.tb_alu__DOT__operator = 9U;
    vlSelfRef.tb_alu__DOT__operand_a = 1U;
    vlSelfRef.tb_alu__DOT__operand_b = 0xffffffffU;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_alu.sv", 
                                         62);
    VL_WRITEF_NX("OP=%b (SLTU) OP1=%0b OP2=%0d RES=%0b\n",4
                 , '#',4,vlSelfRef.tb_alu__DOT__operator
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_a
                 , '#',32,vlSelfRef.tb_alu__DOT__operand_b
                 , '#',32,vlSelfRef.tb_alu__DOT__result);
    VL_FINISH_MT("tb/tb_alu.sv", 63, "");
    co_return;
}

VlCoroutine Vtb_alu___024root___eval_initial__TOP__Vtiming__1(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb/tb_alu.sv", 
                                             67);
        vlSelfRef.tb_alu__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_alu__DOT__clk)));
    }
    co_return;
}

void Vtb_alu___024root___eval_triggers_vec__act(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval_triggers_vec__act\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(vlSelfRef.__VdlySched.awaitingCurrentTime()));
}

bool Vtb_alu___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___trigger_anySet__act\n"); );
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

void Vtb_alu___024root___act_sequent__TOP__0(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___act_sequent__TOP__0\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_alu__DOT__alu__DOT__add_output;
    tb_alu__DOT__alu__DOT__add_output = 0;
    // Body
    tb_alu__DOT__alu__DOT__add_output = (vlSelfRef.tb_alu__DOT__operand_a 
                                         + vlSelfRef.tb_alu__DOT__operand_b);
    vlSelfRef.tb_alu__DOT__result = ((8U & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                      ? ((4U & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                          ? tb_alu__DOT__alu__DOT__add_output
                                          : ((2U & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                              ? tb_alu__DOT__alu__DOT__add_output
                                              : ((1U 
                                                  & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                                  ? 
                                                 (vlSelfRef.tb_alu__DOT__operand_a 
                                                  < vlSelfRef.tb_alu__DOT__operand_b)
                                                  : 
                                                 VL_LTS_III(32, vlSelfRef.tb_alu__DOT__operand_a, vlSelfRef.tb_alu__DOT__operand_b))))
                                      : ((4U & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                          ? ((2U & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                                  ? 
                                                 VL_SHIFTL_III(32,32,32, vlSelfRef.tb_alu__DOT__operand_a, 
                                                               (0x0000001fU 
                                                                & vlSelfRef.tb_alu__DOT__operand_b))
                                                  : 
                                                 VL_SHIFTR_III(32,32,32, vlSelfRef.tb_alu__DOT__operand_a, 
                                                               (0x0000001fU 
                                                                & vlSelfRef.tb_alu__DOT__operand_b)))
                                              : ((1U 
                                                  & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                                  ? 
                                                 VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_alu__DOT__operand_a, 
                                                                (0x0000001fU 
                                                                 & vlSelfRef.tb_alu__DOT__operand_b))
                                                  : 
                                                 (vlSelfRef.tb_alu__DOT__operand_a 
                                                  & vlSelfRef.tb_alu__DOT__operand_b)))
                                          : ((2U & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                                  ? 
                                                 (vlSelfRef.tb_alu__DOT__operand_a 
                                                  | vlSelfRef.tb_alu__DOT__operand_b)
                                                  : 
                                                 (vlSelfRef.tb_alu__DOT__operand_a 
                                                  ^ vlSelfRef.tb_alu__DOT__operand_b))
                                              : ((1U 
                                                  & (IData)(vlSelfRef.tb_alu__DOT__operator))
                                                  ? 
                                                 (vlSelfRef.tb_alu__DOT__operand_a 
                                                  - vlSelfRef.tb_alu__DOT__operand_b)
                                                  : tb_alu__DOT__alu__DOT__add_output))));
}

void Vtb_alu___024root___eval_act(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval_act\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_alu___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_alu___024root___eval_nba(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval_nba\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_alu___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_alu___024root___timing_resume(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___timing_resume\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_alu___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___trigger_orInto__act_vec_vec\n"); );
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
VL_ATTR_COLD void Vtb_alu___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_alu___024root___eval_phase__act(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval_phase__act\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_alu___024root___eval_triggers_vec__act(vlSelf);
    Vtb_alu___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_alu___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_alu___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_alu___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_alu___024root___timing_resume(vlSelf);
        Vtb_alu___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_alu___024root___eval_phase__inact(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval_phase__inact\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb/tb_alu.sv", 4, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_alu___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_alu___024root___eval_phase__nba(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval_phase__nba\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_alu___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_alu___024root___eval_nba(vlSelf);
        Vtb_alu___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_alu___024root___eval(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_alu___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/tb_alu.sv", 4, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb/tb_alu.sv", 4, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_alu___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb/tb_alu.sv", 4, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_alu___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_alu___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_alu___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb_alu___024root___eval_debug_assertions(Vtb_alu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_alu___024root___eval_debug_assertions\n"); );
    Vtb_alu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
