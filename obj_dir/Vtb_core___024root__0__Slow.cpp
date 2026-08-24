// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_core.h for the primary calling header

#include "Vtb_core__pch.h"

VL_ATTR_COLD void Vtb_core___024root___eval_static__TOP(Vtb_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_core___024root____Vm_traceActivitySetAll(Vtb_core___024root* vlSelf);

VL_ATTR_COLD void Vtb_core___024root___eval_static(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_static\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_core___024root___eval_static__TOP(vlSelf);
    Vtb_core___024root____Vm_traceActivitySetAll(vlSelf);
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
    vlSelfRef.tb_core__DOT__y = 0U;
    vlSelfRef.tb_core__DOT__cycle_count = 0U;
    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__misa = 0x40000100U;
    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mvendorid = 0U;
    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mimpid = 0U;
    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__marchid = 0U;
    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mhartid = 0U;
}

VL_ATTR_COLD void Vtb_core___024root___eval_initial__TOP(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_initial__TOP\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_core__DOT__core__DOT__main_mem__DOT__unnamedblk1__DOT__i;
    tb_core__DOT__core__DOT__main_mem__DOT__unnamedblk1__DOT__i = 0;
    // Body
    vlSelfRef.tb_core__DOT__core__DOT__pc_if = 0x00004000U;
    vlSelfRef.tb_core__DOT__core__DOT__imem_en = 0U;
    tb_core__DOT__core__DOT__main_mem__DOT__unnamedblk1__DOT__i = 0U;
    while ((0x00040000U > tb_core__DOT__core__DOT__main_mem__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__mem[(0x0003ffffU 
                                                               & tb_core__DOT__core__DOT__main_mem__DOT__unnamedblk1__DOT__i)] = 0U;
        tb_core__DOT__core__DOT__main_mem__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + tb_core__DOT__core__DOT__main_mem__DOT__unnamedblk1__DOT__i);
    }
    VL_READMEM_N(true, 32, 262144, 0, "sw/rom.hex"s
                 ,  &(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__mem)
                 , 0, ~0ULL);
    vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__write_toggle = 0U;
    vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__rst = 1U;
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

VL_ATTR_COLD void Vtb_core___024root___stl_sequent__TOP__0(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___stl_sequent__TOP__0\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_2;
    __VdfgRegularize_hebeb780c_0_2 = 0;
    CData/*3:0*/ __VdfgRegularize_hebeb780c_0_3;
    __VdfgRegularize_hebeb780c_0_3 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_5;
    __VdfgRegularize_hebeb780c_0_5 = 0;
    // Body
    vlSelfRef.tb_core__DOT__core__DOT__mem_w_id = (
                                                   (1U 
                                                    & (~ 
                                                       (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                        >> 6U))) 
                                                   && ((1U 
                                                        & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                           >> 5U)) 
                                                       && ((1U 
                                                            & (~ 
                                                               (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                >> 4U))) 
                                                           && ((1U 
                                                                & (~ 
                                                                   (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                    >> 3U))) 
                                                               && ((1U 
                                                                    & (~ 
                                                                       (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                        >> 2U))) 
                                                                   && ((1U 
                                                                        & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                           >> 1U)) 
                                                                       && (1U 
                                                                           & vlSelfRef.tb_core__DOT__core__DOT__instr_id)))))));
    vlSelfRef.tb_core__DOT__core__DOT__sign_extend_mem 
        = ((1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem) 
                     >> 2U))) && (1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem) 
                                           >> 1U))));
    vlSelfRef.tb_core__DOT__y = vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[10U];
    vlSelfRef.tb_core__DOT__core__DOT__zimm_id = ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                  >> 0x00000013U)))) 
                                                   << 4U) 
                                                  | (0x0000000fU 
                                                     & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                        >> 0x0000000fU)));
    vlSelfRef.tb_core__DOT__core__DOT__rs1_data_id 
        = (vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
           [(0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                            >> 0x0000000fU))] & (- (IData)(
                                                           (0U 
                                                            != 
                                                            (0x0000001fU 
                                                             & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                >> 0x0000000fU))))));
    vlSelfRef.tb_core__DOT__core__DOT__csr_r_en_id 
        = ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                  >> 6U)) && ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                     >> 5U)) && ((1U 
                                                  & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                     >> 4U)) 
                                                 && ((1U 
                                                      & (~ 
                                                         (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                          >> 3U))) 
                                                     && ((1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                              >> 2U))) 
                                                         && ((1U 
                                                              & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                 >> 1U)) 
                                                             && ((1U 
                                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id) 
                                                                 && ((0x00004000U 
                                                                      & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                                      ? 
                                                                     ((1U 
                                                                       & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                          >> 0x0000000dU)) 
                                                                      || ((1U 
                                                                           & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                              >> 0x0000000cU)) 
                                                                          && (0U 
                                                                              == 
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                                >> 7U)))))
                                                                      : 
                                                                     ((1U 
                                                                       & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                          >> 0x0000000dU)) 
                                                                      || ((1U 
                                                                           & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                              >> 0x0000000cU)) 
                                                                          && (0U 
                                                                              == 
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                                >> 7U)))))))))))));
    vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem 
        = (0x0000001fU & VL_SHIFTL_III(5,5,32, (3U 
                                                & vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem), 3U));
    vlSelfRef.tb_core__DOT__core__DOT__bit_mask_mem 
        = ((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem))
            ? ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem))
                ? 0U : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem))
                         ? ((IData)(0x0000ffffU) << (IData)(vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem))
                         : ((IData)(0x000000ffU) << (IData)(vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem))))
            : ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem))
                ? ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem))
                    ? 0U : 0xffffffffU) : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem))
                                            ? ((IData)(0x0000ffffU) 
                                               << (IData)(vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem))
                                            : ((IData)(0x000000ffU) 
                                               << (IData)(vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem)))));
    vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I 
        = (((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                        >> 0x0000001fU))) << 0x0000000bU) 
           | (0x000007ffU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                             >> 0x00000014U)));
    vlSelfRef.tb_core__DOT__core__DOT__stall = 0U;
    if ((((IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_ex) 
          & (0U != (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex))) 
         & (((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                             >> 0x0000000fU)) == (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex)) 
            | ((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                               >> 0x00000014U)) == (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex))))) {
        vlSelfRef.tb_core__DOT__core__DOT__stall = 1U;
    }
    if ((((IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_mem) 
          & (0U != (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_mem))) 
         & (((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                             >> 0x0000000fU)) == (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_mem)) 
            | ((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                               >> 0x00000014U)) == (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_mem))))) {
        vlSelfRef.tb_core__DOT__core__DOT__stall = 1U;
    }
    if ((((IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_wb) 
          & (0U != (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_wb))) 
         & (((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                             >> 0x0000000fU)) == (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_wb)) 
            | ((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                               >> 0x00000014U)) == (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_wb))))) {
        vlSelfRef.tb_core__DOT__core__DOT__stall = 1U;
    }
    if (((IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_ex) 
         & ((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
             >> 0x00000014U) == (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_ex)))) {
        vlSelfRef.tb_core__DOT__core__DOT__stall = 1U;
    }
    if (((IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_mem) 
         & ((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
             >> 0x00000014U) == (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_mem)))) {
        vlSelfRef.tb_core__DOT__core__DOT__stall = 1U;
    }
    if (((IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_wb) 
         & ((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
             >> 0x00000014U) == (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_wb)))) {
        vlSelfRef.tb_core__DOT__core__DOT__stall = 1U;
    }
    __VdfgRegularize_hebeb780c_0_2 = (IData)((1U == 
                                              (5U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))));
    vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
        = ((IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex)
            ? vlSelfRef.tb_core__DOT__core__DOT__imm_ex
            : vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex);
    vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex 
        = ((1U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_ex))
            ? vlSelfRef.tb_core__DOT__core__DOT__pc_ex
            : ((2U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_ex))
                ? vlSelfRef.tb_core__DOT__core__DOT__zimm_ex
                : vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex));
    vlSelfRef.tb_core__DOT__core__DOT__csr_w_en_id 
        = ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                  >> 6U)) && ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                     >> 5U)) && ((1U 
                                                  & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                     >> 4U)) 
                                                 && ((1U 
                                                      & (~ 
                                                         (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                          >> 3U))) 
                                                     && ((1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                              >> 2U))) 
                                                         && ((1U 
                                                              & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                 >> 1U)) 
                                                             && ((1U 
                                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id) 
                                                                 && (1U 
                                                                     & ((0x00004000U 
                                                                         & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                                         ? 
                                                                        ((0x00002000U 
                                                                          & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                                          ? 
                                                                         (0U 
                                                                          == vlSelfRef.tb_core__DOT__core__DOT__zimm_id)
                                                                          : 
                                                                         (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                          >> 0x0000000cU))
                                                                         : 
                                                                        ((0x00002000U 
                                                                          & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                                          ? 
                                                                         (0U 
                                                                          == 
                                                                          (0x0000001fU 
                                                                           & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                              >> 0x0000000fU)))
                                                                          : 
                                                                         (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                          >> 0x0000000cU)))))))))));
    vlSelfRef.tb_core__DOT__core__DOT__csr_content_id = 0U;
    if (vlSelfRef.tb_core__DOT__core__DOT__csr_r_en_id) {
        vlSelfRef.tb_core__DOT__core__DOT__csr_content_id 
            = (((((((((0x0300U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                   >> 0x00000014U)) 
                      | (0x0305U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                     >> 0x00000014U))) 
                     | (0x0340U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                    >> 0x00000014U))) 
                    | (0x0341U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                   >> 0x00000014U))) 
                   | (0x0342U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                  >> 0x00000014U))) 
                  | (0x0343U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                 >> 0x00000014U))) 
                 | (0x0f13U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                >> 0x00000014U))) | 
                (0x0304U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                             >> 0x00000014U))) ? ((0x0300U 
                                                   == 
                                                   (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                    >> 0x00000014U))
                                                   ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mstatus
                                                   : 
                                                  ((0x0305U 
                                                    == 
                                                    (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                     >> 0x00000014U))
                                                    ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mtvec
                                                    : 
                                                   ((0x0340U 
                                                     == 
                                                     (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                      >> 0x00000014U))
                                                     ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mscratch
                                                     : 
                                                    ((0x0341U 
                                                      == 
                                                      (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                       >> 0x00000014U))
                                                      ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mepc
                                                      : 
                                                     ((0x0342U 
                                                       == 
                                                       (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                        >> 0x00000014U))
                                                       ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mcause
                                                       : 
                                                      ((0x0343U 
                                                        == 
                                                        (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                         >> 0x00000014U))
                                                        ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mtval
                                                        : 
                                                       ((0x0f13U 
                                                         == 
                                                         (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                          >> 0x00000014U))
                                                         ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mhartid
                                                         : vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mie)))))))
                : ((0x0344U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                >> 0x00000014U)) ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mip
                    : ((0x0301U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                    >> 0x00000014U))
                        ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__misa
                        : ((0x0f12U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                        >> 0x00000014U))
                            ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__marchid
                            : ((0x0f11U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                            >> 0x00000014U))
                                ? vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mvendorid
                                : 0U)))));
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((((
                                                   (0x0f11U 
                                                    == 
                                                    (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                     >> 0x00000014U)) 
                                                   << 5U) 
                                                  | (((0x0f12U 
                                                       == 
                                                       (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                        >> 0x00000014U)) 
                                                      << 4U) 
                                                     | ((0x0301U 
                                                         == 
                                                         (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                          >> 0x00000014U)) 
                                                        << 3U))) 
                                                 | (((0x0344U 
                                                      == 
                                                      (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                       >> 0x00000014U)) 
                                                     << 2U) 
                                                    | (((0x0304U 
                                                         == 
                                                         (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                          >> 0x00000014U)) 
                                                        << 1U) 
                                                       | (0x0f13U 
                                                          == 
                                                          (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                           >> 0x00000014U))))) 
                                                << 6U) 
                                               | ((((0x0343U 
                                                     == 
                                                     (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                      >> 0x00000014U)) 
                                                    << 5U) 
                                                   | (((0x0342U 
                                                        == 
                                                        (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                         >> 0x00000014U)) 
                                                       << 4U) 
                                                      | ((0x0341U 
                                                          == 
                                                          (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                           >> 0x00000014U)) 
                                                         << 3U))) 
                                                  | (((0x0340U 
                                                       == 
                                                       (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                        >> 0x00000014U)) 
                                                      << 2U) 
                                                     | (((0x0305U 
                                                          == 
                                                          (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                           >> 0x00000014U)) 
                                                         << 1U) 
                                                        | (0x0300U 
                                                           == 
                                                           (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                            >> 0x00000014U)))))))))))) {
            if ((0U != ((((((0x0f11U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                         >> 0x00000014U)) 
                            << 5U) | (((0x0f12U == 
                                        (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                         >> 0x00000014U)) 
                                       << 4U) | ((0x0301U 
                                                  == 
                                                  (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                   >> 0x00000014U)) 
                                                 << 3U))) 
                          | (((0x0344U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                           >> 0x00000014U)) 
                              << 2U) | (((0x0304U == 
                                          (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                           >> 0x00000014U)) 
                                         << 1U) | (0x0f13U 
                                                   == 
                                                   (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                    >> 0x00000014U))))) 
                         << 6U) | ((((0x0343U == (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                  >> 0x00000014U)) 
                                     << 5U) | (((0x0342U 
                                                 == 
                                                 (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                  >> 0x00000014U)) 
                                                << 4U) 
                                               | ((0x0341U 
                                                   == 
                                                   (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                    >> 0x00000014U)) 
                                                  << 3U))) 
                                   | (((0x0340U == 
                                        (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                         >> 0x00000014U)) 
                                       << 2U) | (((0x0305U 
                                                   == 
                                                   (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                    >> 0x00000014U)) 
                                                  << 1U) 
                                                 | (0x0300U 
                                                    == 
                                                    (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                     >> 0x00000014U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: csr_file.sv:90: Assertion failed in %m: unique case, but multiple matches found for '12'h%X'\n",4, 'M',vlSymsp->name(),"tb_core.core.csr_file", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',12,(vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                           >> 0x00000014U));
                    VL_STOP_MT("rtl/csr_file.sv", 90, "");
                }
            }
        }
    }
    vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__shifted_mask 
        = (vlSelfRef.tb_core__DOT__core__DOT__bit_mask_mem 
           >> (IData)(vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem));
    vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw 
        = ((vlSelfRef.tb_core__DOT__core__DOT__bit_mask_mem 
            & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__mem
            [(0x0003ffffU & ((vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem 
                              - (IData)(0x00004000U)) 
                             >> 2U))]) >> (IData)(vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem));
    __VdfgRegularize_hebeb780c_0_5 = ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                       ? vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I
                                       : ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                           ? ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                               ? ((1U 
                                                   & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                   : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                                               : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                                           : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I));
    if ((0x00000040U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
        if ((0x00000020U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
            if ((0x00000010U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
                vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id 
                    = ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                        ? 0U : ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                 ? 0U : ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                          ? ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                              ? 5U : 0U)
                                          : 0U)));
                vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
                vlSelfRef.tb_core__DOT__core__DOT__imm_id 
                    = vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I;
            } else if ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
                if ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
                    if ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
                        if ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
                            vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 4U;
                            vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 1U;
                        } else {
                            vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 0U;
                            vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
                        }
                        vlSelfRef.tb_core__DOT__core__DOT__imm_id 
                            = ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                ? (((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 0x0000001fU))) 
                                    << 0x00000014U) 
                                   | ((((0x000001feU 
                                         & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                            >> 0x0000000bU)) 
                                        | (1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 0x00000014U))) 
                                       << 0x0000000bU) 
                                      | (0x000007feU 
                                         & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                            >> 0x00000014U))))
                                : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I);
                    } else {
                        vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 0U;
                        vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
                        vlSelfRef.tb_core__DOT__core__DOT__imm_id 
                            = vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I;
                    }
                } else {
                    vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 0U;
                    vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
                    vlSelfRef.tb_core__DOT__core__DOT__imm_id 
                        = vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I;
                }
            } else {
                if ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
                    vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id 
                        = ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                            ? ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                ? 4U : 0U) : 0U);
                    vlSelfRef.tb_core__DOT__core__DOT__imm_id 
                        = vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I;
                } else {
                    vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 0U;
                    vlSelfRef.tb_core__DOT__core__DOT__imm_id 
                        = ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                            ? ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                ? (((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 0x0000001fU))) 
                                    << 0x0000000cU) 
                                   | ((0x00000800U 
                                       & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                          << 4U)) | 
                                      ((0x000007e0U 
                                        & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                           >> 0x00000014U)) 
                                       | (0x0000001eU 
                                          & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                             >> 7U)))))
                                : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                            : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I);
                }
                vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
            }
        } else {
            vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__imm_id 
                = vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I;
        }
        vlSelfRef.tb_core__DOT__core__DOT__reg_write_id 
            = ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                      >> 5U)) && ((0x00000010U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                   ? ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 3U))) 
                                      && ((1U & (~ 
                                                 (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                  >> 2U))) 
                                          && ((1U & 
                                               (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id))))
                                   : ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                       ? ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id)))
                                       : ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id))))));
        vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id 
            = ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                      >> 5U)) && ((0x00000010U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                   ? ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 3U))) 
                                      && ((1U & (~ 
                                                 (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                  >> 2U))) 
                                          && ((1U & 
                                               (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id))))
                                   : ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                       ? ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id)))
                                       : ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id))))));
    } else if ((0x00000020U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
        if ((0x00000010U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
            vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id 
                = ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                    ? 0U : ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                             ? ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                 ? ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                     ? 3U : 0U) : 0U)
                             : ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                 ? ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                     ? 2U : 0U) : 0U)));
            vlSelfRef.tb_core__DOT__core__DOT__imm_id 
                = __VdfgRegularize_hebeb780c_0_5;
        } else {
            vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__imm_id 
                = (((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                >> 0x0000001fU))) << 0x0000000bU) 
                   | (0x000007ffU & ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                      ? (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                         >> 0x00000014U)
                                      : ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                          ? (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                             >> 0x00000014U)
                                          : ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                              ? ((1U 
                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                  ? 
                                                 ((0x000007e0U 
                                                   & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001fU 
                                                     & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                        >> 7U)))
                                                  : 
                                                 (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                  >> 0x00000014U))
                                              : (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 0x00000014U))))));
        }
        vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__reg_write_id 
            = ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                      >> 4U)) && ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                            >> 3U))) 
                                  && ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                       ? ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id))
                                       : ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)))));
        vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id 
            = ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                         >> 4U))) && ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 3U))) 
                                      && ((1U & (~ 
                                                 (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                  >> 2U))) 
                                          && ((1U & 
                                               (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id)))));
    } else if ((0x00000010U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
        if ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
            vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
        } else if ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
            if ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
                if ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) {
                    vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 2U;
                    vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 1U;
                } else {
                    vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 0U;
                    vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
                }
            } else {
                vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = 0U;
                vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
            }
        } else {
            vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id 
                = ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                    ? ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                        ? 2U : 0U) : 0U);
            vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
        }
        vlSelfRef.tb_core__DOT__core__DOT__reg_write_id 
            = ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                         >> 3U))) && ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                       ? ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id))
                                       : ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id))));
        vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id 
            = ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                         >> 3U))) && ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                       ? ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id))
                                       : ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id))));
        vlSelfRef.tb_core__DOT__core__DOT__imm_id = __VdfgRegularize_hebeb780c_0_5;
    } else {
        vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id 
            = ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                ? 0U : ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                         ? 0U : ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                  ? ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                      ? 1U : 0U) : 0U)));
        vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__reg_write_id 
            = ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id))));
        vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id 
            = ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id))));
        vlSelfRef.tb_core__DOT__core__DOT__imm_id = vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I;
    }
    __VdfgRegularize_hebeb780c_0_3 = (0x0000000fU & 
                                      (- (IData)(((IData)(__VdfgRegularize_hebeb780c_0_2) 
                                                  & (2U 
                                                     == 
                                                     (0x0aU 
                                                      & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex)))))));
    vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output 
        = (vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
           + vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex);
    vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__sub_output 
        = (vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex 
           - vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex);
    vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__slt_output 
        = VL_LTS_III(32, vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex, vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex);
    vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__sltu_output 
        = (vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex 
           < vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex);
    vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex = 
        ((0x00000040U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))
          ? (((0x00000010U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))
               ? (((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                    ? (0x0aU & (- (IData)((1U & ((IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex) 
                                                 >> 1U)))))
                    : (2U & (- (IData)((1U & ((IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex) 
                                              >> 1U)))))) 
                  & (IData)(__VdfgRegularize_hebeb780c_0_3))
               : (((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                    ? ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                        ? 6U : 5U) : ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                                       ? 2U : 1U)) 
                  & (IData)(__VdfgRegularize_hebeb780c_0_3))) 
             & (- (IData)((1U & ((IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex) 
                                 >> 5U))))) : (((4U 
                                                 & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                                                   ? 2U
                                                   : 3U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct7_ex))
                                                    ? 8U
                                                    : 
                                                   ((0x20U 
                                                     == (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct7_ex))
                                                     ? 9U
                                                     : 8U))
                                                   : 4U))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                                                   ? 6U
                                                   : 5U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                                                   ? 7U
                                                   : 
                                                  (1U 
                                                   & (- (IData)(
                                                                ((0x20U 
                                                                  == (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct7_ex)) 
                                                                 & ((0U 
                                                                     != (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct7_ex)) 
                                                                    & (0x33U 
                                                                       == (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex)))))))))) 
                                               & (- (IData)((IData)(
                                                                    ((0x12U 
                                                                      == 
                                                                      (0x1aU 
                                                                       & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))) 
                                                                     & (IData)(__VdfgRegularize_hebeb780c_0_2)))))));
    vlSelfRef.tb_core__DOT__core__DOT__alu_result_ex 
        = ((8U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
            ? ((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                ? vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output
                : ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                    ? ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                        ? vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output
                        : ((~ vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex) 
                           & vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex))
                    : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                        ? VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex, 
                                         (0x0000001fU 
                                          & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))
                        : VL_SHIFTR_III(32,32,32, vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex, 
                                        (0x0000001fU 
                                         & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)))))
            : ((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                ? ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                    ? ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                        ? VL_SHIFTL_III(32,32,32, vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex, 
                                        (0x0000001fU 
                                         & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))
                        : vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__sltu_output)
                    : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                        ? vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__slt_output
                        : (vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
                           ^ vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex)))
                : ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                    ? ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                        ? (vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
                           | vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex)
                        : (vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
                           & vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex))
                    : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                        ? vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__sub_output
                        : vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output))));
    vlSelfRef.tb_core__DOT__core__DOT__alu_zero_in_ex 
        = ((1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex) 
                     >> 3U))) && ((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                                   ? ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                                       ? ((1U & (~ (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))) 
                                          && (1U & vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__sltu_output))
                                       : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex)) 
                                          && (1U & vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__slt_output)))
                                   : ((1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex) 
                                                >> 1U))) 
                                      && ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex)) 
                                          && (0U == vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__sub_output)))));
    vlSelfRef.tb_core__DOT__core__DOT__alu_zero_out_ex 
        = ((0x63U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex)) 
           & (((0U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex)) 
               | ((4U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex)) 
                  | (6U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))))
               ? (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_in_ex)
               : (~ (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_in_ex))));
    vlSelfRef.tb_core__DOT__core__DOT__flush_ex = (
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.tb_core__DOT__core__DOT__stall))) 
                                                   && ((0x63U 
                                                        == (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex)) 
                                                       & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_out_ex)));
    vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump = 0U;
    vlSelfRef.tb_core__DOT__core__DOT__flush_id = (
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.tb_core__DOT__core__DOT__stall))) 
                                                   && (((0x63U 
                                                         == (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex)) 
                                                        & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_out_ex)) 
                                                       || ((0x6fU 
                                                            == 
                                                            (0x0000007fU 
                                                             & vlSelfRef.tb_core__DOT__core__DOT__instr_id)) 
                                                           || (0x67U 
                                                               == 
                                                               (0x0000007fU 
                                                                & vlSelfRef.tb_core__DOT__core__DOT__instr_id)))));
    vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__jalr_target_raw 
        = (vlSelfRef.tb_core__DOT__core__DOT__imm_id 
           + vlSelfRef.tb_core__DOT__core__DOT__rs1_data_id);
    if (vlSelfRef.tb_core__DOT__core__DOT__stall) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_next 
            = vlSelfRef.tb_core__DOT__core__DOT__pc_if;
    } else if (((0x63U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex)) 
                & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_out_ex))) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump = 1U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_next 
            = (vlSelfRef.tb_core__DOT__core__DOT__pc_ex 
               + vlSelfRef.tb_core__DOT__core__DOT__imm_ex);
    } else if ((0x6fU == (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id))) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump = 1U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_next 
            = (vlSelfRef.tb_core__DOT__core__DOT__pc_id 
               + vlSelfRef.tb_core__DOT__core__DOT__imm_id);
    } else if ((0x67U == (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id))) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump = 1U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_next 
            = (0xfffffffeU & vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__jalr_target_raw);
    } else {
        vlSelfRef.tb_core__DOT__core__DOT__pc_next 
            = ((IData)(4U) + vlSelfRef.tb_core__DOT__core__DOT__pc_if);
    }
}

VL_ATTR_COLD void Vtb_core___024root___eval_stl(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_stl\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_core___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_core___024root____Vm_traceActivitySetAll(vlSelf);
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

VL_ATTR_COLD void Vtb_core___024root____Vm_traceActivitySetAll(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root____Vm_traceActivitySetAll\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
}

VL_ATTR_COLD void Vtb_core___024root___ctor_var_reset(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___ctor_var_reset\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_core__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6610376131445473662ull);
    vlSelf->tb_core__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9966589053022997338ull);
    vlSelf->tb_core__DOT__core__DOT__pc_if = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4147165525560472574ull);
    vlSelf->tb_core__DOT__core__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9933893879099770627ull);
    vlSelf->tb_core__DOT__core__DOT__imem_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17045578522840800934ull);
    vlSelf->tb_core__DOT__core__DOT__stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14124184816093760096ull);
    vlSelf->tb_core__DOT__core__DOT__pc_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10553212983592174086ull);
    vlSelf->tb_core__DOT__core__DOT__flush_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5273765998941339736ull);
    vlSelf->tb_core__DOT__core__DOT__instr_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5002804404332099589ull);
    vlSelf->tb_core__DOT__core__DOT__pc_plus_4_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18232497392192818539ull);
    vlSelf->tb_core__DOT__core__DOT__rs1_data_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1928335977486513083ull);
    vlSelf->tb_core__DOT__core__DOT__imm_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4147135398322122019ull);
    vlSelf->tb_core__DOT__core__DOT__mem_w_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11094999294683310198ull);
    vlSelf->tb_core__DOT__core__DOT__rs1_sel_id = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 82446360500391167ull);
    vlSelf->tb_core__DOT__core__DOT__rs2_sel_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8511158423263191825ull);
    vlSelf->tb_core__DOT__core__DOT__reg_write_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11730946578265984694ull);
    vlSelf->tb_core__DOT__core__DOT__csr_w_en_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18325796157325045044ull);
    vlSelf->tb_core__DOT__core__DOT__csr_r_en_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2351824364480081484ull);
    vlSelf->tb_core__DOT__core__DOT__wb_sel_id = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8224206102075130563ull);
    vlSelf->tb_core__DOT__core__DOT__zimm_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17642680371835534614ull);
    vlSelf->tb_core__DOT__core__DOT__csr_content_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14493905504701539071ull);
    vlSelf->tb_core__DOT__core__DOT__csr_r_en_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 829145088719654903ull);
    vlSelf->tb_core__DOT__core__DOT__csr_reg_ex = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 13030939464656773258ull);
    vlSelf->tb_core__DOT__core__DOT__csr_data_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17155990980546767017ull);
    vlSelf->tb_core__DOT__core__DOT__opcode_ex = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 6067810694724199630ull);
    vlSelf->tb_core__DOT__core__DOT__rd_ex = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7682750086964550996ull);
    vlSelf->tb_core__DOT__core__DOT__funct3_ex = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16677556946663248352ull);
    vlSelf->tb_core__DOT__core__DOT__funct7_ex = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 16581621323968693784ull);
    vlSelf->tb_core__DOT__core__DOT__imm_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9119010983467515046ull);
    vlSelf->tb_core__DOT__core__DOT__zimm_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6880175495700624828ull);
    vlSelf->tb_core__DOT__core__DOT__flush_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8788015522896202722ull);
    vlSelf->tb_core__DOT__core__DOT__pc_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 957021774511192083ull);
    vlSelf->tb_core__DOT__core__DOT__pc_plus_4_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8361001712256823380ull);
    vlSelf->tb_core__DOT__core__DOT__mem_w_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5862195846934843295ull);
    vlSelf->tb_core__DOT__core__DOT__rs2_sel_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4491831315272933009ull);
    vlSelf->tb_core__DOT__core__DOT__rs1_sel_ex = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6418237080517129485ull);
    vlSelf->tb_core__DOT__core__DOT__reg_write_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11738073116533557273ull);
    vlSelf->tb_core__DOT__core__DOT__csr_write_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 545089001225407750ull);
    vlSelf->tb_core__DOT__core__DOT__wb_sel_ex = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12337750354553631796ull);
    vlSelf->tb_core__DOT__core__DOT__alu_op_ex = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1846987712602779133ull);
    vlSelf->tb_core__DOT__core__DOT__rs1_data_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10568674102307868588ull);
    vlSelf->tb_core__DOT__core__DOT__rs2_data_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 607136653695965040ull);
    vlSelf->tb_core__DOT__core__DOT__csr_content_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18400252777062575733ull);
    vlSelf->tb_core__DOT__core__DOT__alu_result_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10763966366302986420ull);
    vlSelf->tb_core__DOT__core__DOT__alu_zero_in_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7671451627857740463ull);
    vlSelf->tb_core__DOT__core__DOT__alu_zero_out_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10938411808977689573ull);
    vlSelf->tb_core__DOT__core__DOT__alu_operand_b_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17296026416968773244ull);
    vlSelf->tb_core__DOT__core__DOT__pc_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4590549802859255947ull);
    vlSelf->tb_core__DOT__core__DOT__imm_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2334972195976991616ull);
    vlSelf->tb_core__DOT__core__DOT__rs2_data_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4436052216507799289ull);
    vlSelf->tb_core__DOT__core__DOT__rd_mem = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5878934959098461552ull);
    vlSelf->tb_core__DOT__core__DOT__csr_reg_mem = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 8416731834734050626ull);
    vlSelf->tb_core__DOT__core__DOT__mem_w_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17765032954043359083ull);
    vlSelf->tb_core__DOT__core__DOT__alu_zero_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 130630998737188057ull);
    vlSelf->tb_core__DOT__core__DOT__wb_sel_mem = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10162218423813502064ull);
    vlSelf->tb_core__DOT__core__DOT__reg_write_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1226588539786945312ull);
    vlSelf->tb_core__DOT__core__DOT__csr_write_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 739139197784628521ull);
    vlSelf->tb_core__DOT__core__DOT__alu_result_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10198411056624059772ull);
    vlSelf->tb_core__DOT__core__DOT__opcode_mem = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 15988376319903202827ull);
    vlSelf->tb_core__DOT__core__DOT__funct3_mem = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16977236336184878298ull);
    vlSelf->tb_core__DOT__core__DOT__pc_plus_4_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6710078189837155525ull);
    vlSelf->tb_core__DOT__core__DOT__csr_content_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17242544863047674811ull);
    vlSelf->tb_core__DOT__core__DOT__csr_data_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2895568081974472543ull);
    vlSelf->tb_core__DOT__core__DOT__w_data_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3935985388775488657ull);
    vlSelf->tb_core__DOT__core__DOT__bit_mask_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6655713912478041137ull);
    vlSelf->tb_core__DOT__core__DOT__shift_amt_mem = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 571252749376455959ull);
    vlSelf->tb_core__DOT__core__DOT__sign_extend_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1985400628234093852ull);
    vlSelf->tb_core__DOT__core__DOT__r_data_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17742469493509065398ull);
    vlSelf->tb_core__DOT__core__DOT__pc_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14848580514322411521ull);
    vlSelf->tb_core__DOT__core__DOT__rd_wb = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4708749839179066144ull);
    vlSelf->tb_core__DOT__core__DOT__csr_reg_wb = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 417274871725991169ull);
    vlSelf->tb_core__DOT__core__DOT__csr_data_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14931316215479072389ull);
    vlSelf->tb_core__DOT__core__DOT__imm_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11185393209812945484ull);
    vlSelf->tb_core__DOT__core__DOT__mem_w_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14512953456221329549ull);
    vlSelf->tb_core__DOT__core__DOT__reg_write_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1486767519904007886ull);
    vlSelf->tb_core__DOT__core__DOT__csr_write_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9643715987499543197ull);
    vlSelf->tb_core__DOT__core__DOT__wb_sel_wb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8567789125444777721ull);
    vlSelf->tb_core__DOT__core__DOT__alu_result_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1132786478519818078ull);
    vlSelf->tb_core__DOT__core__DOT__alu_zero_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13364178960288013797ull);
    vlSelf->tb_core__DOT__core__DOT__pc_plus_4_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12248163438582604112ull);
    vlSelf->tb_core__DOT__core__DOT__csr_content_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8373350839551710229ull);
    vlSelf->tb_core__DOT__core__DOT__pc_controller__DOT__jalr_target_raw = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10959704554362365544ull);
    vlSelf->tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3167115284344869420ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT____Vlvbound_h4bb6dde6__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 262144; ++__Vi0) {
        vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3723010822705835524ull);
    }
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11881940973643925321ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8174312921395967142ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_tx_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12703549675936782586ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__write_toggle = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15446143917096581520ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10243235143672573839ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__dram_write_en_prev = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9532792706693376429ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__msb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7275551092663364717ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11543702409081371270ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__shifted_mask = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14888234971878867566ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__write_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3837199730695669653ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__read_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14972722732948064604ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9570066627609677902ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_addr_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17394038262501828822ull);
    VL_SCOPED_RAND_RESET_W(440, vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__send_string, __VscopeHash, 16292076316993548370ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9610058976503607558ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__hold_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9425229087833000043ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__shift_reg = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 4742443702632716417ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__bit_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15855487202146460281ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__bit_counter_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17542326351332528050ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__cur_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8268890260258783707ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3427583140683557895ull);
    vlSelf->tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__debug_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4914239499945214241ull);
    vlSelf->tb_core__DOT__core__DOT__decoder__DOT__imm_I = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7740123825237529701ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7615203373935210827ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rd_mem = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4943244864895692704ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rw_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 140794536148498270ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rw_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10911611965833754783ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rd_wb = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5188620784693286557ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rw_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12027961713939369732ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__csr_ex = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 10639361381358350886ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__csr_mem = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 2565549564071348214ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16087215398662461070ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13225237334413674864ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__csr_wb = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 18306227354461972483ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14892200512805742189ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_core__DOT__core__DOT__regfile__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2602730502690321648ull);
    }
    vlSelf->tb_core__DOT__core__DOT__csr_file__DOT__mie = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9316797494931868447ull);
    vlSelf->tb_core__DOT__core__DOT__csr_file__DOT__mip = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8301133201241316919ull);
    vlSelf->tb_core__DOT__core__DOT__csr_file__DOT__mstatus = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12505982556817498665ull);
    vlSelf->tb_core__DOT__core__DOT__csr_file__DOT__mtvec = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8574071892644020942ull);
    vlSelf->tb_core__DOT__core__DOT__csr_file__DOT__mepc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15573874236110505797ull);
    vlSelf->tb_core__DOT__core__DOT__csr_file__DOT__mcause = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14788928864232647787ull);
    vlSelf->tb_core__DOT__core__DOT__csr_file__DOT__mscratch = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11526776993799031658ull);
    vlSelf->tb_core__DOT__core__DOT__csr_file__DOT__mtval = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2669722790219683940ull);
    vlSelf->tb_core__DOT__core__DOT__alu__DOT__add_output = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5635242385095453635ull);
    vlSelf->tb_core__DOT__core__DOT__alu__DOT__sub_output = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17379847204562275427ull);
    vlSelf->tb_core__DOT__core__DOT__alu__DOT__slt_output = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9090828395577295073ull);
    vlSelf->tb_core__DOT__core__DOT__alu__DOT__sltu_output = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6345487775189985529ull);
    vlSelf->tb_core__DOT__core__DOT__alu__DOT__alu_zero_slt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6876928559938083114ull);
    vlSelf->tb_core__DOT__core__DOT__alu__DOT__alu_zero_sltu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 721796147673308437ull);
    vlSelf->tb_core__DOT__core__DOT__alu__DOT__alu_zero_and = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17393865014248684637ull);
    vlSelf->__VdlyVal__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0 = 0;
    vlSelf->__VdlyDim0__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0 = 0;
    vlSelf->__VdlySet__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0 = 0;
    vlSelf->__VdlyVal__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 = 0;
    vlSelf->__VdlyDim0__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 = 0;
    vlSelf->__VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 = 0;
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
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
