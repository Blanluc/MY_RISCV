// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_core.h for the primary calling header

#include "Vtb_core__pch.h"

VL_ATTR_COLD void Vtb_core___024root___eval_static(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_static\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_core__DOT__clk__0 
        = vlSelfRef.tb_core__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_core__DOT__rst_n__0 
        = vlSelfRef.tb_core__DOT__rst_n;
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_core___024root___eval_initial__TOP(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_initial__TOP\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 32, 1024, 0, "program.hex"s,  &(vlSelfRef.tb_core__DOT__core__DOT__u_imem__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_core___024root___eval_final(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_final\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_core___024root___eval_settle(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_settle\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtb_core___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_core___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_core___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_core.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb_core.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_core___024root___ctor_var_reset(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___ctor_var_reset\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_core__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6610376131445473662ull);
    vlSelf->tb_core__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9966589053022997338ull);
    vlSelf->tb_core__DOT__core__DOT__pc_if = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4147165525560472574ull);
    vlSelf->tb_core__DOT__core__DOT__instr_if = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4155192122099271765ull);
    vlSelf->tb_core__DOT__core__DOT__pc_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10553212983592174086ull);
    vlSelf->tb_core__DOT__core__DOT__instr_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5002804404332099589ull);
    vlSelf->tb_core__DOT__core__DOT__opcode_ex = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 6067810694724199630ull);
    vlSelf->tb_core__DOT__core__DOT__pc_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 957021774511192083ull);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb_core__DOT__core__DOT__u_imem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7383949812641418920ull);
    }
    vlSelf->__Vdly__tb_core__DOT__core__DOT__pc_if = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_core__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_core__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
