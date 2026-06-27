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
    vlSelfRef.tb_core__DOT__i = 0U;
    vlSelfRef.tb_core__DOT__y = 0U;
}

VL_ATTR_COLD void Vtb_core___024root___eval_initial__TOP(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_initial__TOP\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_core__DOT__core__DOT__dmem__DOT__unnamedblk1__DOT__i;
    tb_core__DOT__core__DOT__dmem__DOT__unnamedblk1__DOT__i = 0;
    // Body
    vlSelfRef.tb_core__DOT__core__DOT__pc_if = 0U;
    vlSelfRef.tb_core__DOT__core__DOT__imem_en = 0U;
    VL_READMEM_N(true, 32, 1024, 0, "program2.hex"s
                 ,  &(vlSelfRef.tb_core__DOT__core__DOT__imem__DOT__mem)
                 , 0, ~0ULL);
    tb_core__DOT__core__DOT__dmem__DOT__unnamedblk1__DOT__i = 0U;
    while ((0x00000400U > tb_core__DOT__core__DOT__dmem__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.tb_core__DOT__core__DOT__dmem__DOT__mem[(0x000003ffU 
                                                           & tb_core__DOT__core__DOT__dmem__DOT__unnamedblk1__DOT__i)] = 0U;
        tb_core__DOT__core__DOT__dmem__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + tb_core__DOT__core__DOT__dmem__DOT__unnamedblk1__DOT__i);
    }
    vlSelfRef.tb_core__DOT__core__DOT__dmem__DOT__toggle = 0U;
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

extern const VlUnpacked<CData/*0:0*/, 8> Vtb_core__ConstPool__TABLE_h3548cf34_0;
extern const VlUnpacked<IData/*31:0*/, 8> Vtb_core__ConstPool__TABLE_h1e091857_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_core__ConstPool__TABLE_h87d4bd01_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_core__ConstPool__TABLE_h91114663_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vtb_core__ConstPool__TABLE_h32e0c5a1_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_core__ConstPool__TABLE_hba86f42b_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_core__ConstPool__TABLE_h1ad98872_0;

VL_ATTR_COLD void Vtb_core___024root___stl_sequent__TOP__0(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___stl_sequent__TOP__0\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*2:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_1;
    __VdfgRegularize_hebeb780c_0_1 = 0;
    // Body
    vlSelfRef.tb_core__DOT__y = vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[10U];
    __Vtableidx2 = vlSelfRef.tb_core__DOT__core__DOT__funct3_mem;
    vlSelfRef.tb_core__DOT__core__DOT__is_unsigned 
        = Vtb_core__ConstPool__TABLE_h3548cf34_0[__Vtableidx2];
    vlSelfRef.tb_core__DOT__core__DOT__bit_mask_mem 
        = Vtb_core__ConstPool__TABLE_h1e091857_0[__Vtableidx2];
    vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
        = ((IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex)
            ? vlSelfRef.tb_core__DOT__core__DOT__imm_ex
            : vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_9 = (((4U 
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
                                                & (- (IData)(
                                                             (3U 
                                                              == 
                                                              (3U 
                                                               & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))))));
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
    vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I 
        = (((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                        >> 0x0000001fU))) << 0x0000000bU) 
           | (0x000007ffU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                             >> 0x00000014U)));
    __Vtableidx1 = (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id);
    vlSelfRef.tb_core__DOT__core__DOT__mem_w_id = Vtb_core__ConstPool__TABLE_h87d4bd01_0
        [__Vtableidx1];
    vlSelfRef.tb_core__DOT__core__DOT__reg_write_id 
        = Vtb_core__ConstPool__TABLE_h91114663_0[__Vtableidx1];
    vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id = Vtb_core__ConstPool__TABLE_h32e0c5a1_0
        [__Vtableidx1];
    vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id = Vtb_core__ConstPool__TABLE_hba86f42b_0
        [__Vtableidx1];
    vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id = Vtb_core__ConstPool__TABLE_h1ad98872_0
        [__Vtableidx1];
    vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output 
        = (vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
           + vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex);
    vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex = 
        ((0x00000040U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))
          ? (((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
               ? ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                   ? 6U : 5U) : 2U) & (- (IData)((IData)(
                                                         (0x23U 
                                                          == 
                                                          (0x3fU 
                                                           & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex)))))))
          : ((0x00000020U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))
              ? ((- (IData)((1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex) 
                                      >> 3U))))) & 
                 ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_9) 
                  & ((- (IData)((1U & ((IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex) 
                                       >> 4U)))) & 
                     (- (IData)((1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex) 
                                          >> 2U))))))))
              : ((- (IData)((1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex) 
                                      >> 3U))))) & 
                 (((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))
                    ? (7U & (- (IData)((3U == (3U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))))))
                    : (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_9)) 
                  & (- (IData)((1U & ((IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex) 
                                      >> 4U))))))));
    vlSelfRef.tb_core__DOT__core__DOT__pc__DOT__pc_d 
        = (vlSelfRef.tb_core__DOT__core__DOT__pc_if 
           + (4U & ((~ (IData)(vlSelfRef.tb_core__DOT__core__DOT__stall)) 
                    << 2U)));
    __VdfgRegularize_hebeb780c_0_1 = ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
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
    vlSelfRef.tb_core__DOT__core__DOT__imm_id = ((0x00000040U 
                                                  & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                  ? 
                                                 ((0x00000020U 
                                                   & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                   ? 
                                                  ((0x00000010U 
                                                    & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                    ? vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I
                                                    : 
                                                   ((8U 
                                                     & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                     ? 
                                                    ((4U 
                                                      & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                      ? 
                                                     ((2U 
                                                       & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                        ? 
                                                       (((- (IData)(
                                                                    (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                     >> 0x0000001fU))) 
                                                         << 0x00000014U) 
                                                        | ((((0x000001feU 
                                                              & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                 >> 0x0000000bU)) 
                                                             | (1U 
                                                                & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                   >> 0x00000014U))) 
                                                            << 0x0000000bU) 
                                                           | (0x000007feU 
                                                              & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                 >> 0x00000014U))))
                                                        : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                                                       : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                                                      : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                                                     : 
                                                    ((4U 
                                                      & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                      ? vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I
                                                      : 
                                                     ((2U 
                                                       & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                        ? 
                                                       (((- (IData)(
                                                                    (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                     >> 0x0000001fU))) 
                                                         << 0x0000000cU) 
                                                        | ((0x00000800U 
                                                            & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                               << 4U)) 
                                                           | ((0x000007e0U 
                                                               & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                  >> 0x00000014U)) 
                                                              | (0x0000001eU 
                                                                 & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                    >> 7U)))))
                                                        : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                                                       : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I))))
                                                   : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)
                                                  : 
                                                 ((0x00000020U 
                                                   & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                   ? 
                                                  ((0x00000010U 
                                                    & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                    ? __VdfgRegularize_hebeb780c_0_1
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                 >> 0x0000001fU))) 
                                                     << 0x0000000bU) 
                                                    | (0x000007ffU 
                                                       & ((8U 
                                                           & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                           ? 
                                                          (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                           >> 0x00000014U)
                                                           : 
                                                          ((4U 
                                                            & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                            ? 
                                                           (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                            >> 0x00000014U)
                                                            : 
                                                           ((2U 
                                                             & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                             ? 
                                                            ((1U 
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
                                                             : 
                                                            (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                             >> 0x00000014U)))))))
                                                   : 
                                                  ((0x00000010U 
                                                    & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                                    ? __VdfgRegularize_hebeb780c_0_1
                                                    : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)));
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
    vlSelf->tb_core__DOT__core__DOT__instr_if = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4155192122099271765ull);
    vlSelf->tb_core__DOT__core__DOT__imem_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17045578522840800934ull);
    vlSelf->tb_core__DOT__core__DOT__stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14124184816093760096ull);
    vlSelf->tb_core__DOT__core__DOT__pc_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10553212983592174086ull);
    vlSelf->tb_core__DOT__core__DOT__instr_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5002804404332099589ull);
    vlSelf->tb_core__DOT__core__DOT__imm_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4147135398322122019ull);
    vlSelf->tb_core__DOT__core__DOT__mem_w_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11094999294683310198ull);
    vlSelf->tb_core__DOT__core__DOT__rs2_sel_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8511158423263191825ull);
    vlSelf->tb_core__DOT__core__DOT__rs1_sel_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 82446360500391167ull);
    vlSelf->tb_core__DOT__core__DOT__reg_write_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11730946578265984694ull);
    vlSelf->tb_core__DOT__core__DOT__wb_sel_id = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8224206102075130563ull);
    vlSelf->tb_core__DOT__core__DOT__opcode_ex = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 6067810694724199630ull);
    vlSelf->tb_core__DOT__core__DOT__rd_ex = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7682750086964550996ull);
    vlSelf->tb_core__DOT__core__DOT__funct3_ex = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16677556946663248352ull);
    vlSelf->tb_core__DOT__core__DOT__funct7_ex = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 16581621323968693784ull);
    vlSelf->tb_core__DOT__core__DOT__imm_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9119010983467515046ull);
    vlSelf->tb_core__DOT__core__DOT__pc_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 957021774511192083ull);
    vlSelf->tb_core__DOT__core__DOT__mem_w_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5862195846934843295ull);
    vlSelf->tb_core__DOT__core__DOT__rs2_sel_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4491831315272933009ull);
    vlSelf->tb_core__DOT__core__DOT__rs1_sel_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6418237080517129485ull);
    vlSelf->tb_core__DOT__core__DOT__reg_write_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11738073116533557273ull);
    vlSelf->tb_core__DOT__core__DOT__wb_sel_ex = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12337750354553631796ull);
    vlSelf->tb_core__DOT__core__DOT__alu_op_ex = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1846987712602779133ull);
    vlSelf->tb_core__DOT__core__DOT__rs1_data_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10568674102307868588ull);
    vlSelf->tb_core__DOT__core__DOT__rs2_data_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 607136653695965040ull);
    vlSelf->tb_core__DOT__core__DOT__alu_operand_b_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17296026416968773244ull);
    vlSelf->tb_core__DOT__core__DOT__pc_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14848580514322411521ull);
    vlSelf->tb_core__DOT__core__DOT__rd_wb = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4708749839179066144ull);
    vlSelf->tb_core__DOT__core__DOT__mem_w_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14512953456221329549ull);
    vlSelf->tb_core__DOT__core__DOT__reg_write_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1486767519904007886ull);
    vlSelf->tb_core__DOT__core__DOT__wb_sel_wb = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8567789125444777721ull);
    vlSelf->tb_core__DOT__core__DOT__alu_result_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1132786478519818078ull);
    vlSelf->tb_core__DOT__core__DOT__pc_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4590549802859255947ull);
    vlSelf->tb_core__DOT__core__DOT__rs2_data_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4436052216507799289ull);
    vlSelf->tb_core__DOT__core__DOT__rd_mem = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5878934959098461552ull);
    vlSelf->tb_core__DOT__core__DOT__mem_w_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17765032954043359083ull);
    vlSelf->tb_core__DOT__core__DOT__wb_sel_mem = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10162218423813502064ull);
    vlSelf->tb_core__DOT__core__DOT__reg_write_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1226588539786945312ull);
    vlSelf->tb_core__DOT__core__DOT__alu_result_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10198411056624059772ull);
    vlSelf->tb_core__DOT__core__DOT__opcode_mem = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 15988376319903202827ull);
    vlSelf->tb_core__DOT__core__DOT__funct3_mem = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16977236336184878298ull);
    vlSelf->tb_core__DOT__core__DOT__w_data_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3935985388775488657ull);
    vlSelf->tb_core__DOT__core__DOT__bit_mask_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6655713912478041137ull);
    vlSelf->tb_core__DOT__core__DOT__is_unsigned = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4601703475567781274ull);
    vlSelf->tb_core__DOT__core__DOT__r_data_wb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17742469493509065398ull);
    vlSelf->tb_core__DOT__core__DOT__pc__DOT__pc_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5590708854255258025ull);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb_core__DOT__core__DOT__imem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5170356458529840868ull);
    }
    vlSelf->tb_core__DOT__core__DOT__decoder__DOT__imm_I = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7740123825237529701ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7615203373935210827ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rd_mem = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4943244864895692704ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rw_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 140794536148498270ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rw_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10911611965833754783ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rd_wb = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5188620784693286557ull);
    vlSelf->tb_core__DOT__core__DOT__hazard_unit__DOT__rw_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12027961713939369732ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_core__DOT__core__DOT__regfile__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2602730502690321648ull);
    }
    vlSelf->tb_core__DOT__core__DOT__alu__DOT__add_output = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5635242385095453635ull);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb_core__DOT__core__DOT__dmem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 737414424961399518ull);
    }
    vlSelf->tb_core__DOT__core__DOT__dmem__DOT__toggle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15767436078737319628ull);
    vlSelf->__VdfgRegularize_hebeb780c_0_9 = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__pc_if = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__instr_id = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__pc_id = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__rs2_data_ex = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__rd_ex = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__pc_ex = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__rs1_data_ex = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__imm_ex = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__mem_w_ex = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__rs2_sel_ex = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__reg_write_ex = 0;
    vlSelf->__Vdly__tb_core__DOT__core__DOT__wb_sel_ex = 0;
    vlSelf->__VdlyVal__tb_core__DOT__core__DOT__dmem__DOT__mem__v0 = 0;
    vlSelf->__VdlyDim0__tb_core__DOT__core__DOT__dmem__DOT__mem__v0 = 0;
    vlSelf->__VdlySet__tb_core__DOT__core__DOT__dmem__DOT__mem__v0 = 0;
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
