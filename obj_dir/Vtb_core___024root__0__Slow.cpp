// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_core.h for the primary calling header

#include "Vtb_core__pch.h"

VL_ATTR_COLD void Vtb_core___024root___eval_static(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_static\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_core__DOT__i = 0U;
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

VL_ATTR_COLD void Vtb_core___024root___eval_static__TOP(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_static__TOP\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_core__DOT__i = 0U;
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

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_core___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_core___024root___eval_phase__stl(Vtb_core___024root* vlSelf);

VL_ATTR_COLD void Vtb_core___024root___eval_settle(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_settle\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_core___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb/tb_core.sv", 9, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_core___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_core___024root___eval_triggers_vec__stl(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_triggers_vec__stl\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_core___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_core___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_core___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_core___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___trigger_anySet__stl\n"); );
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

extern const VlUnpacked<CData/*0:0*/, 128> Vtb_core__ConstPool__TABLE_h1ad98872_0;

VL_ATTR_COLD void Vtb_core___024root___stl_sequent__TOP__0(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___stl_sequent__TOP__0\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.tb_core__DOT__core__DOT__src1_data_ex 
        = (vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
           [vlSelfRef.tb_core__DOT__core__DOT__rs1_ex] 
           & (- (IData)((0U != (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs1_ex)))));
    __Vtableidx1 = (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id);
    vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id = Vtb_core__ConstPool__TABLE_h1ad98872_0
        [__Vtableidx1];
    vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
        = ((IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex)
            ? vlSelfRef.tb_core__DOT__core__DOT__imm_ex
            : (vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
               [vlSelfRef.tb_core__DOT__core__DOT__rs2_ex] 
               & (- (IData)((0U != (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_ex))))));
    vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I 
        = (((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                        >> 0x0000001fU))) << 0x0000000bU) 
           | (0x000007ffU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                             >> 0x00000014U)));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_1 = ((8U 
                                                 & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                 ? vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I
                                                 : 
                                                ((4U 
                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                  ? 
                                                 ((2U 
                                                   & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                   ? 
                                                  ((1U 
                                                    & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                    : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                                                   : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                                                  : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I));
}

VL_ATTR_COLD void Vtb_core___024root___eval_stl(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_stl\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vinline__stl_sequent__TOP__0___Vtableidx1;
    __Vinline__stl_sequent__TOP__0___Vtableidx1 = 0;
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        vlSelfRef.tb_core__DOT__core__DOT__src1_data_ex 
            = (vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
               [vlSelfRef.tb_core__DOT__core__DOT__rs1_ex] 
               & (- (IData)((0U != (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs1_ex)))));
        __Vinline__stl_sequent__TOP__0___Vtableidx1 
            = (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id);
        vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id 
            = Vtb_core__ConstPool__TABLE_h1ad98872_0
            [__Vinline__stl_sequent__TOP__0___Vtableidx1];
        vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
            = ((IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex)
                ? vlSelfRef.tb_core__DOT__core__DOT__imm_ex
                : (vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
                   [vlSelfRef.tb_core__DOT__core__DOT__rs2_ex] 
                   & (- (IData)((0U != (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_ex))))));
        vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I 
            = (((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                            >> 0x0000001fU))) << 0x0000000bU) 
               | (0x000007ffU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                 >> 0x00000014U)));
        vlSelfRef.__VdfgRegularize_hebeb780c_0_1 = 
            ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
              ? vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I
              : ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                  ? ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                      ? ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                          ? (0xfffff000U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                          : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                      : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                  : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I));
    }
}

VL_ATTR_COLD bool Vtb_core___024root___eval_phase__stl(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_phase__stl\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_core___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_core___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_core___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_core___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
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
    vlSelf->tb_core__DOT__core__DOT__rs2_sel_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8511158423263191825ull);
    vlSelf->tb_core__DOT__core__DOT__rs1_ex = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14051007056780725631ull);
    vlSelf->tb_core__DOT__core__DOT__rs2_ex = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8380311782948989727ull);
    vlSelf->tb_core__DOT__core__DOT__imm_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9119010983467515046ull);
    vlSelf->tb_core__DOT__core__DOT__pc_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 957021774511192083ull);
    vlSelf->tb_core__DOT__core__DOT__rs2_sel_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4491831315272933009ull);
    vlSelf->tb_core__DOT__core__DOT__src1_data_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7559609252729773400ull);
    vlSelf->tb_core__DOT__core__DOT__alu_operand_b_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17296026416968773244ull);
    vlSelf->tb_core__DOT__core__DOT__pc_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14848580514322411521ull);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb_core__DOT__core__DOT__u_imem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7383949812641418920ull);
    }
    vlSelf->tb_core__DOT__core__DOT__decoder__DOT__imm_I = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7740123825237529701ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_core__DOT__core__DOT__regfile__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2602730502690321648ull);
    }
    vlSelf->__VdfgRegularize_hebeb780c_0_1 = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__pc_if = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
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
