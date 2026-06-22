// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_core.h for the primary calling header

#include "Vtb_core__pch.h"

VlCoroutine Vtb_core___024root___eval_initial__TOP__Vtiming__0(Vtb_core___024root* vlSelf);
VlCoroutine Vtb_core___024root___eval_initial__TOP__Vtiming__1(Vtb_core___024root* vlSelf);

void Vtb_core___024root___eval_initial(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_initial\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 32, 1024, 0, "program.hex"s,  &(vlSelfRef.tb_core__DOT__core__DOT__u_imem__DOT__mem)
                 , 0, ~0ULL);
    Vtb_core___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_core___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtb_core___024root___eval_initial__TOP__Vtiming__0(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_core__DOT__rst_n = 0U;
    vlSelfRef.tb_core__DOT__clk = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_core.sv", 
                                         22);
    vlSelfRef.tb_core__DOT__rst_n = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000028ULL, 
                                         nullptr, "tb/tb_core.sv", 
                                         30);
    VL_FINISH_MT("tb/tb_core.sv", 31, "");
    co_return;
}

VlCoroutine Vtb_core___024root___eval_initial__TOP__Vtiming__1(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb/tb_core.sv", 
                                             35);
        vlSelfRef.tb_core__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_core__DOT__clk)));
    }
    co_return;
}

void Vtb_core___024root___eval_triggers_vec__act(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_triggers_vec__act\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 2U) 
                                                     | ((((~ (IData)(vlSelfRef.tb_core__DOT__rst_n)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_core__DOT__rst_n__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.tb_core__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_core__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_core__DOT__clk__0 
        = vlSelfRef.tb_core__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_core__DOT__rst_n__0 
        = vlSelfRef.tb_core__DOT__rst_n;
}

bool Vtb_core___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___trigger_anySet__act\n"); );
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

void Vtb_core___024root___nba_sequent__TOP__0(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_sequent__TOP__0\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__tb_core__DOT__core__DOT__pc_if 
        = vlSelfRef.tb_core__DOT__core__DOT__pc_if;
    vlSelfRef.__Vdly__tb_core__DOT__core__DOT__pc_if 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) ? 
           ((IData)(4U) + vlSelfRef.tb_core__DOT__core__DOT__pc_if)
            : 0U);
}

void Vtb_core___024root___nba_sequent__TOP__1(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_sequent__TOP__1\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("STAGE IF : PC=%0h INSTR=%0h\n---------------------------\nSTAGE ID : PC=%0h INSTR=%0h OPCODE=%0b\n---------------------------\nSTAGE EX : PC=%0h INSTR=%0h OPCODE=%0b\n---------------------------\n",8
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_if
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__instr_if
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_id
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__instr_id
                 , '#',7,(0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_ex
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__instr_id
                 , '#',7,(IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex));
}

void Vtb_core___024root___nba_sequent__TOP__2(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_sequent__TOP__2\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb_core__DOT__rst_n) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_ex = vlSelfRef.tb_core__DOT__core__DOT__pc_id;
        vlSelfRef.tb_core__DOT__core__DOT__opcode_ex 
            = (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id);
        vlSelfRef.tb_core__DOT__core__DOT__pc_id = vlSelfRef.tb_core__DOT__core__DOT__pc_if;
        vlSelfRef.tb_core__DOT__core__DOT__instr_id 
            = vlSelfRef.tb_core__DOT__core__DOT__instr_if;
    } else {
        vlSelfRef.tb_core__DOT__core__DOT__pc_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__opcode_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_id = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__instr_id = 0U;
    }
}

void Vtb_core___024root___nba_sequent__TOP__3(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_sequent__TOP__3\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_core__DOT__core__DOT__instr_if = vlSelfRef.tb_core__DOT__core__DOT__u_imem__DOT__mem
        [(0x000003ffU & (vlSelfRef.tb_core__DOT__core__DOT__pc_if 
                         >> 2U))];
}

void Vtb_core___024root___nba_sequent__TOP__4(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_sequent__TOP__4\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_core__DOT__core__DOT__pc_if = vlSelfRef.__Vdly__tb_core__DOT__core__DOT__pc_if;
}

void Vtb_core___024root___eval_nba(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_nba\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.__Vdly__tb_core__DOT__core__DOT__pc_if 
            = vlSelfRef.tb_core__DOT__core__DOT__pc_if;
        vlSelfRef.__Vdly__tb_core__DOT__core__DOT__pc_if 
            = ((IData)(vlSelfRef.tb_core__DOT__rst_n)
                ? ((IData)(4U) + vlSelfRef.tb_core__DOT__core__DOT__pc_if)
                : 0U);
    }
    if (VL_UNLIKELY(((1ULL & vlSelfRef.__VnbaTriggered[0U])))) {
        VL_WRITEF_NX("STAGE IF : PC=%0h INSTR=%0h\n---------------------------\nSTAGE ID : PC=%0h INSTR=%0h OPCODE=%0b\n---------------------------\nSTAGE EX : PC=%0h INSTR=%0h OPCODE=%0b\n---------------------------\n",8
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_if
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__instr_if
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_id
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__instr_id
                     , '#',7,(0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_ex
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__instr_id
                     , '#',7,(IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        if (vlSelfRef.tb_core__DOT__rst_n) {
            vlSelfRef.tb_core__DOT__core__DOT__pc_ex 
                = vlSelfRef.tb_core__DOT__core__DOT__pc_id;
            vlSelfRef.tb_core__DOT__core__DOT__opcode_ex 
                = (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id);
            vlSelfRef.tb_core__DOT__core__DOT__pc_id 
                = vlSelfRef.tb_core__DOT__core__DOT__pc_if;
            vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                = vlSelfRef.tb_core__DOT__core__DOT__instr_if;
        } else {
            vlSelfRef.tb_core__DOT__core__DOT__pc_ex = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__opcode_ex = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__pc_id = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__instr_id = 0U;
        }
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.tb_core__DOT__core__DOT__instr_if 
            = vlSelfRef.tb_core__DOT__core__DOT__u_imem__DOT__mem
            [(0x000003ffU & (vlSelfRef.tb_core__DOT__core__DOT__pc_if 
                             >> 2U))];
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_if = vlSelfRef.__Vdly__tb_core__DOT__core__DOT__pc_if;
    }
}

void Vtb_core___024root___timing_resume(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___timing_resume\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_core___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___trigger_orInto__act_vec_vec\n"); );
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
VL_ATTR_COLD void Vtb_core___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_core___024root___eval_phase__act(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_phase__act\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_core___024root___eval_triggers_vec__act(vlSelf);
    Vtb_core___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_core___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_core___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_core___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_core___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_core___024root___eval_phase__inact(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_phase__inact\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb/tb_core.sv", 9, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_core___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_core___024root___eval_phase__nba(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_phase__nba\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_core___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_core___024root___eval_nba(vlSelf);
        Vtb_core___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_core___024root___eval(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_core___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/tb_core.sv", 9, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb/tb_core.sv", 9, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_core___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb/tb_core.sv", 9, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_core___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_core___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_core___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb_core___024root___eval_debug_assertions(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_debug_assertions\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
