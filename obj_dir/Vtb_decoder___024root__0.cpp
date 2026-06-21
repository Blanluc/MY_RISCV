// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_decoder.h for the primary calling header

#include "Vtb_decoder__pch.h"

VlCoroutine Vtb_decoder___024root___eval_initial__TOP__Vtiming__0(Vtb_decoder___024root* vlSelf);
VlCoroutine Vtb_decoder___024root___eval_initial__TOP__Vtiming__1(Vtb_decoder___024root* vlSelf);

void Vtb_decoder___024root___eval_initial(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval_initial\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_decoder___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_decoder___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtb_decoder___024root___eval_initial__TOP__Vtiming__0(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_decoder__DOT__clk = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_decoder.sv", 
                                         30);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_decoder.sv", 
                                         31);
    vlSelfRef.tb_decoder__DOT__instr = 0x00b50533U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_decoder.sv", 
                                         32);
    VL_WRITEF_NX("OPCODE=%b RD=%d funct3=%b funct7=%b RS1=%d RS2=%d IMM=%0d\n",7
                 , '#',7,(0x0000007fU & vlSelfRef.tb_decoder__DOT__instr)
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 7U)), '#',3,
                 (7U & (vlSelfRef.tb_decoder__DOT__instr 
                        >> 0x0000000cU)), '#',7,(vlSelfRef.tb_decoder__DOT__instr 
                                                 >> 0x00000019U)
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 0x0000000fU))
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 0x00000014U))
                 , '#',32,vlSelfRef.tb_decoder__DOT__imm);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_decoder.sv", 
                                         34);
    vlSelfRef.tb_decoder__DOT__instr = 0x00155513U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_decoder.sv", 
                                         35);
    VL_WRITEF_NX("OPCODE=%b RD=%d funct3=%b funct7=%b RS1=%d RS2=%d IMM=%0d\n",7
                 , '#',7,(0x0000007fU & vlSelfRef.tb_decoder__DOT__instr)
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 7U)), '#',3,
                 (7U & (vlSelfRef.tb_decoder__DOT__instr 
                        >> 0x0000000cU)), '#',7,(vlSelfRef.tb_decoder__DOT__instr 
                                                 >> 0x00000019U)
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 0x0000000fU))
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 0x00000014U))
                 , '#',32,vlSelfRef.tb_decoder__DOT__imm);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_decoder.sv", 
                                         37);
    vlSelfRef.tb_decoder__DOT__instr = 0x0c0000efU;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_decoder.sv", 
                                         38);
    VL_WRITEF_NX("OPCODE=%b RD=%d funct3=%b funct7=%b RS1=%d RS2=%d IMM=%0d\n",7
                 , '#',7,(0x0000007fU & vlSelfRef.tb_decoder__DOT__instr)
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 7U)), '#',3,
                 (7U & (vlSelfRef.tb_decoder__DOT__instr 
                        >> 0x0000000cU)), '#',7,(vlSelfRef.tb_decoder__DOT__instr 
                                                 >> 0x00000019U)
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 0x0000000fU))
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 0x00000014U))
                 , '#',32,vlSelfRef.tb_decoder__DOT__imm);
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_decoder.sv", 
                                         40);
    vlSelfRef.tb_decoder__DOT__instr = 0x00010117U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_decoder.sv", 
                                         41);
    VL_WRITEF_NX("OPCODE=%b RD=%d funct3=%b funct7=%b RS1=%d RS2=%d IMM=%0d\n",7
                 , '#',7,(0x0000007fU & vlSelfRef.tb_decoder__DOT__instr)
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 7U)), '#',3,
                 (7U & (vlSelfRef.tb_decoder__DOT__instr 
                        >> 0x0000000cU)), '#',7,(vlSelfRef.tb_decoder__DOT__instr 
                                                 >> 0x00000019U)
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 0x0000000fU))
                 , '#',5,(0x0000001fU & (vlSelfRef.tb_decoder__DOT__instr 
                                         >> 0x00000014U))
                 , '#',32,vlSelfRef.tb_decoder__DOT__imm);
    VL_FINISH_MT("tb/tb_decoder.sv", 43, "");
    co_return;
}

VlCoroutine Vtb_decoder___024root___eval_initial__TOP__Vtiming__1(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb/tb_decoder.sv", 
                                             47);
        vlSelfRef.tb_decoder__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_decoder__DOT__clk)));
    }
    co_return;
}

void Vtb_decoder___024root___eval_triggers_vec__act(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval_triggers_vec__act\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(vlSelfRef.__VdlySched.awaitingCurrentTime()));
}

bool Vtb_decoder___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___trigger_anySet__act\n"); );
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

void Vtb_decoder___024root___act_sequent__TOP__0(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___act_sequent__TOP__0\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_decoder__DOT__decoder__DOT__imm_I;
    tb_decoder__DOT__decoder__DOT__imm_I = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_1;
    __VdfgRegularize_hebeb780c_0_1 = 0;
    // Body
    tb_decoder__DOT__decoder__DOT__imm_I = (((- (IData)(
                                                        (vlSelfRef.tb_decoder__DOT__instr 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000bU) 
                                            | (0x000007ffU 
                                               & (vlSelfRef.tb_decoder__DOT__instr 
                                                  >> 0x00000014U)));
    __VdfgRegularize_hebeb780c_0_1 = ((8U & vlSelfRef.tb_decoder__DOT__instr)
                                       ? tb_decoder__DOT__decoder__DOT__imm_I
                                       : ((4U & vlSelfRef.tb_decoder__DOT__instr)
                                           ? (0xfffff000U 
                                              & vlSelfRef.tb_decoder__DOT__instr)
                                           : tb_decoder__DOT__decoder__DOT__imm_I));
    vlSelfRef.tb_decoder__DOT__imm = ((0x00000040U 
                                       & vlSelfRef.tb_decoder__DOT__instr)
                                       ? ((0x00000020U 
                                           & vlSelfRef.tb_decoder__DOT__instr)
                                           ? ((0x00000010U 
                                               & vlSelfRef.tb_decoder__DOT__instr)
                                               ? tb_decoder__DOT__decoder__DOT__imm_I
                                               : ((8U 
                                                   & vlSelfRef.tb_decoder__DOT__instr)
                                                   ? 
                                                  ((4U 
                                                    & vlSelfRef.tb_decoder__DOT__instr)
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.tb_decoder__DOT__instr 
                                                                 >> 0x0000001fU))) 
                                                     << 0x00000014U) 
                                                    | ((((0x000001feU 
                                                          & (vlSelfRef.tb_decoder__DOT__instr 
                                                             >> 0x0000000bU)) 
                                                         | (1U 
                                                            & (vlSelfRef.tb_decoder__DOT__instr 
                                                               >> 0x00000014U))) 
                                                        << 0x0000000bU) 
                                                       | (0x000007feU 
                                                          & (vlSelfRef.tb_decoder__DOT__instr 
                                                             >> 0x00000014U))))
                                                    : tb_decoder__DOT__decoder__DOT__imm_I)
                                                   : 
                                                  ((4U 
                                                    & vlSelfRef.tb_decoder__DOT__instr)
                                                    ? tb_decoder__DOT__decoder__DOT__imm_I
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelfRef.tb_decoder__DOT__instr 
                                                                 >> 0x0000001fU))) 
                                                     << 0x0000000cU) 
                                                    | ((0x00000800U 
                                                        & (vlSelfRef.tb_decoder__DOT__instr 
                                                           << 4U)) 
                                                       | ((0x000007e0U 
                                                           & (vlSelfRef.tb_decoder__DOT__instr 
                                                              >> 0x00000014U)) 
                                                          | (0x0000001eU 
                                                             & (vlSelfRef.tb_decoder__DOT__instr 
                                                                >> 7U))))))))
                                           : tb_decoder__DOT__decoder__DOT__imm_I)
                                       : ((0x00000020U 
                                           & vlSelfRef.tb_decoder__DOT__instr)
                                           ? ((0x00000010U 
                                               & vlSelfRef.tb_decoder__DOT__instr)
                                               ? __VdfgRegularize_hebeb780c_0_1
                                               : ((
                                                   (- (IData)(
                                                              (vlSelfRef.tb_decoder__DOT__instr 
                                                               >> 0x0000001fU))) 
                                                   << 0x0000000bU) 
                                                  | (0x000007ffU 
                                                     & ((8U 
                                                         & vlSelfRef.tb_decoder__DOT__instr)
                                                         ? 
                                                        (vlSelfRef.tb_decoder__DOT__instr 
                                                         >> 0x00000014U)
                                                         : 
                                                        ((4U 
                                                          & vlSelfRef.tb_decoder__DOT__instr)
                                                          ? 
                                                         (vlSelfRef.tb_decoder__DOT__instr 
                                                          >> 0x00000014U)
                                                          : 
                                                         ((0x000007e0U 
                                                           & (vlSelfRef.tb_decoder__DOT__instr 
                                                              >> 0x00000014U)) 
                                                          | (0x0000001fU 
                                                             & (vlSelfRef.tb_decoder__DOT__instr 
                                                                >> 7U))))))))
                                           : ((0x00000010U 
                                               & vlSelfRef.tb_decoder__DOT__instr)
                                               ? __VdfgRegularize_hebeb780c_0_1
                                               : tb_decoder__DOT__decoder__DOT__imm_I)));
}

void Vtb_decoder___024root___eval_act(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval_act\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_decoder___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_decoder___024root___eval_nba(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval_nba\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_decoder___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_decoder___024root___timing_resume(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___timing_resume\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_decoder___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___trigger_orInto__act_vec_vec\n"); );
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
VL_ATTR_COLD void Vtb_decoder___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_decoder___024root___eval_phase__act(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval_phase__act\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_decoder___024root___eval_triggers_vec__act(vlSelf);
    Vtb_decoder___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_decoder___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_decoder___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_decoder___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_decoder___024root___timing_resume(vlSelf);
        Vtb_decoder___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_decoder___024root___eval_phase__inact(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval_phase__inact\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb/tb_decoder.sv", 4, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_decoder___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_decoder___024root___eval_phase__nba(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval_phase__nba\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_decoder___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_decoder___024root___eval_nba(vlSelf);
        Vtb_decoder___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_decoder___024root___eval(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_decoder___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/tb_decoder.sv", 4, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb/tb_decoder.sv", 4, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_decoder___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb/tb_decoder.sv", 4, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_decoder___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_decoder___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_decoder___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb_decoder___024root___eval_debug_assertions(Vtb_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_decoder___024root___eval_debug_assertions\n"); );
    Vtb_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
