// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_core.h for the primary calling header

#include "Vtb_core__pch.h"

VL_ATTR_COLD void Vtb_core___024root___eval_initial__TOP(Vtb_core___024root* vlSelf);
VlCoroutine Vtb_core___024root___eval_initial__TOP__Vtiming__0(Vtb_core___024root* vlSelf);
VlCoroutine Vtb_core___024root___eval_initial__TOP__Vtiming__1(Vtb_core___024root* vlSelf);

void Vtb_core___024root___eval_initial(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_initial\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_core___024root___eval_initial__TOP(vlSelf);
    Vtb_core___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_core___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtb_core___024root___eval_initial__TOP__Vtiming__0(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("waves.vcd"s);
    vlSymsp->_traceDumpOpen();
    vlSelfRef.tb_core__DOT__rst_n = 0U;
    vlSelfRef.tb_core__DOT__clk = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "tb/tb_core.sv", 
                                         22);
    vlSelfRef.tb_core__DOT__rst_n = 1U;
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
                                             46);
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
    // Locals
    IData/*31:0*/ __Vdly__tb_core__DOT__cycle_count;
    __Vdly__tb_core__DOT__cycle_count = 0;
    // Body
    __Vdly__tb_core__DOT__cycle_count = vlSelfRef.tb_core__DOT__cycle_count;
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_core__DOT__core__DOT__mem_w_mem) 
                      & (0x20000000U == vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem))))) {
        VL_FINISH_MT("tb/tb_core.sv", 108, "");
    }
    vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0 = 0U;
    vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 = 0U;
    __Vdly__tb_core__DOT__cycle_count = ((IData)(1U) 
                                         + vlSelfRef.tb_core__DOT__cycle_count);
    if (VL_UNLIKELY((VL_LTES_III(32, 0x00989680U, vlSelfRef.tb_core__DOT__cycle_count)))) {
        VL_WRITEF_NX("TIMEOUT\n",0);
        VL_FINISH_MT("tb/tb_core.sv", 97, "");
    }
    if (vlSelfRef.tb_core__DOT__core__DOT__mem_w_mem) {
        if (VL_UNLIKELY(((((IData)(vlSelfRef.tb_core__DOT__core__DOT__mem_w_mem) 
                           & (~ (IData)(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_write_en_prev))) 
                          & (0x10000000U == vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem))))) {
            VL_WRITEF_NX("%c",1, '#',8,(0x000000ffU 
                                        & vlSelfRef.tb_core__DOT__core__DOT__rs2_data_mem));
        } else {
            vlSelfRef.__VdlyVal__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0 
                = (((vlSelfRef.tb_core__DOT__core__DOT__rs2_data_mem 
                     << (IData)(vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem)) 
                    & vlSelfRef.tb_core__DOT__core__DOT__bit_mask_mem) 
                   | (vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__mem
                      [(0x0003ffffU & ((vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem 
                                        - (IData)(0x00004000U)) 
                                       >> 2U))] & (~ vlSelfRef.tb_core__DOT__core__DOT__bit_mask_mem)));
            vlSelfRef.__VdlyDim0__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0 
                = (0x0003ffffU & ((vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem 
                                   - (IData)(0x00004000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0 = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_core__DOT__core__DOT__reg_write_wb) 
         & (0U != (IData)(vlSelfRef.tb_core__DOT__core__DOT__rd_wb)))) {
        vlSelfRef.__VdlyVal__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 
            = ((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                ? ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                    ? vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb
                    : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                        ? vlSelfRef.tb_core__DOT__core__DOT__csr_content_wb
                        : vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_wb))
                : ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                    ? ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                        ? vlSelfRef.tb_core__DOT__core__DOT__lui_wb
                        : vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb)
                    : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                        ? vlSelfRef.tb_core__DOT__core__DOT__r_data_wb
                        : vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb)));
        vlSelfRef.__VdlyDim0__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 
            = vlSelfRef.tb_core__DOT__core__DOT__rd_wb;
        vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 = 1U;
    }
    vlSelfRef.tb_core__DOT__cycle_count = __Vdly__tb_core__DOT__cycle_count;
    vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_write_en_prev 
        = vlSelfRef.tb_core__DOT__core__DOT__mem_w_mem;
}

void Vtb_core___024root___nba_sequent__TOP__1(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_sequent__TOP__1\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_2;
    __VdfgRegularize_hebeb780c_0_2 = 0;
    CData/*3:0*/ __VdfgRegularize_hebeb780c_0_3;
    __VdfgRegularize_hebeb780c_0_3 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_5;
    __VdfgRegularize_hebeb780c_0_5 = 0;
    IData/*31:0*/ __Vdly__tb_core__DOT__core__DOT__pc_if;
    __Vdly__tb_core__DOT__core__DOT__pc_if = 0;
    IData/*31:0*/ __Vdly__tb_core__DOT__core__DOT__instr_id;
    __Vdly__tb_core__DOT__core__DOT__instr_id = 0;
    IData/*31:0*/ __Vdly__tb_core__DOT__core__DOT__pc_plus_4_id;
    __Vdly__tb_core__DOT__core__DOT__pc_plus_4_id = 0;
    IData/*31:0*/ __Vdly__tb_core__DOT__core__DOT__pc_id;
    __Vdly__tb_core__DOT__core__DOT__pc_id = 0;
    IData/*31:0*/ __Vdly__tb_core__DOT__core__DOT__pc_ex;
    __Vdly__tb_core__DOT__core__DOT__pc_ex = 0;
    IData/*31:0*/ __Vdly__tb_core__DOT__core__DOT__pc_plus_4_ex;
    __Vdly__tb_core__DOT__core__DOT__pc_plus_4_ex = 0;
    CData/*6:0*/ __Vdly__tb_core__DOT__core__DOT__opcode_ex;
    __Vdly__tb_core__DOT__core__DOT__opcode_ex = 0;
    CData/*4:0*/ __Vdly__tb_core__DOT__core__DOT__rd_ex;
    __Vdly__tb_core__DOT__core__DOT__rd_ex = 0;
    SData/*11:0*/ __Vdly__tb_core__DOT__core__DOT__csr_reg_ex;
    __Vdly__tb_core__DOT__core__DOT__csr_reg_ex = 0;
    CData/*2:0*/ __Vdly__tb_core__DOT__core__DOT__funct3_ex;
    __Vdly__tb_core__DOT__core__DOT__funct3_ex = 0;
    IData/*31:0*/ __Vdly__tb_core__DOT__core__DOT__csr_content_ex;
    __Vdly__tb_core__DOT__core__DOT__csr_content_ex = 0;
    IData/*31:0*/ __Vdly__tb_core__DOT__core__DOT__rs2_data_ex;
    __Vdly__tb_core__DOT__core__DOT__rs2_data_ex = 0;
    IData/*31:0*/ __Vdly__tb_core__DOT__core__DOT__imm_ex;
    __Vdly__tb_core__DOT__core__DOT__imm_ex = 0;
    CData/*0:0*/ __Vdly__tb_core__DOT__core__DOT__mem_w_ex;
    __Vdly__tb_core__DOT__core__DOT__mem_w_ex = 0;
    CData/*0:0*/ __Vdly__tb_core__DOT__core__DOT__reg_write_ex;
    __Vdly__tb_core__DOT__core__DOT__reg_write_ex = 0;
    CData/*0:0*/ __Vdly__tb_core__DOT__core__DOT__csr_write_ex;
    __Vdly__tb_core__DOT__core__DOT__csr_write_ex = 0;
    CData/*2:0*/ __Vdly__tb_core__DOT__core__DOT__wb_sel_ex;
    __Vdly__tb_core__DOT__core__DOT__wb_sel_ex = 0;
    // Body
    __Vdly__tb_core__DOT__core__DOT__pc_plus_4_id = vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_id;
    __Vdly__tb_core__DOT__core__DOT__mem_w_ex = vlSelfRef.tb_core__DOT__core__DOT__mem_w_ex;
    __Vdly__tb_core__DOT__core__DOT__wb_sel_ex = vlSelfRef.tb_core__DOT__core__DOT__wb_sel_ex;
    __Vdly__tb_core__DOT__core__DOT__pc_plus_4_ex = vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_ex;
    __Vdly__tb_core__DOT__core__DOT__reg_write_ex = vlSelfRef.tb_core__DOT__core__DOT__reg_write_ex;
    __Vdly__tb_core__DOT__core__DOT__csr_write_ex = vlSelfRef.tb_core__DOT__core__DOT__csr_write_ex;
    __Vdly__tb_core__DOT__core__DOT__csr_content_ex 
        = vlSelfRef.tb_core__DOT__core__DOT__csr_content_ex;
    __Vdly__tb_core__DOT__core__DOT__pc_if = vlSelfRef.tb_core__DOT__core__DOT__pc_if;
    __Vdly__tb_core__DOT__core__DOT__pc_id = vlSelfRef.tb_core__DOT__core__DOT__pc_id;
    __Vdly__tb_core__DOT__core__DOT__rd_ex = vlSelfRef.tb_core__DOT__core__DOT__rd_ex;
    __Vdly__tb_core__DOT__core__DOT__csr_reg_ex = vlSelfRef.tb_core__DOT__core__DOT__csr_reg_ex;
    __Vdly__tb_core__DOT__core__DOT__funct3_ex = vlSelfRef.tb_core__DOT__core__DOT__funct3_ex;
    __Vdly__tb_core__DOT__core__DOT__imm_ex = vlSelfRef.tb_core__DOT__core__DOT__imm_ex;
    __Vdly__tb_core__DOT__core__DOT__pc_ex = vlSelfRef.tb_core__DOT__core__DOT__pc_ex;
    __Vdly__tb_core__DOT__core__DOT__instr_id = vlSelfRef.tb_core__DOT__core__DOT__instr_id;
    __Vdly__tb_core__DOT__core__DOT__rs2_data_ex = vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex;
    __Vdly__tb_core__DOT__core__DOT__opcode_ex = vlSelfRef.tb_core__DOT__core__DOT__opcode_ex;
    if (vlSelfRef.tb_core__DOT__rst_n) {
        if (vlSelfRef.tb_core__DOT__core__DOT__flush_id) {
            __Vdly__tb_core__DOT__core__DOT__pc_plus_4_id = 0U;
            __Vdly__tb_core__DOT__core__DOT__pc_id = 0U;
            __Vdly__tb_core__DOT__core__DOT__instr_id = 0U;
        } else if (vlSelfRef.tb_core__DOT__core__DOT__stall) {
            __Vdly__tb_core__DOT__core__DOT__pc_plus_4_id 
                = vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_id;
            __Vdly__tb_core__DOT__core__DOT__pc_id 
                = vlSelfRef.tb_core__DOT__core__DOT__pc_id;
            __Vdly__tb_core__DOT__core__DOT__instr_id 
                = vlSelfRef.tb_core__DOT__core__DOT__instr_id;
        } else {
            __Vdly__tb_core__DOT__core__DOT__pc_plus_4_id 
                = ((IData)(4U) + vlSelfRef.tb_core__DOT__core__DOT__pc_if);
            __Vdly__tb_core__DOT__core__DOT__pc_id 
                = vlSelfRef.tb_core__DOT__core__DOT__pc_if;
            __Vdly__tb_core__DOT__core__DOT__instr_id 
                = vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__mem
                [(0x0003ffffU & ((vlSelfRef.tb_core__DOT__core__DOT__pc_if 
                                  - (IData)(0x00004000U)) 
                                 >> 2U))];
        }
        vlSelfRef.tb_core__DOT__core__DOT__funct3_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__funct3_ex;
        vlSelfRef.tb_core__DOT__core__DOT__opcode_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__opcode_ex;
        vlSelfRef.tb_core__DOT__core__DOT__pc_wb = vlSelfRef.tb_core__DOT__core__DOT__pc_mem;
        vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_wb 
            = vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_mem;
        vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_wb 
            = vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_mem;
        if (vlSelfRef.tb_core__DOT__core__DOT__csr_write_wb) {
            if ((1U & (~ VL_ONEHOT_I(((((((0x0f12U 
                                           == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                          << 4U) | 
                                         (((0x0344U 
                                            == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                           << 3U) | 
                                          ((0x0304U 
                                            == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                           << 2U))) 
                                        | (((0x0343U 
                                             == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                            << 1U) 
                                           | (0x0342U 
                                              == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)))) 
                                       << 4U) | (((
                                                   (0x0341U 
                                                    == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                                   << 3U) 
                                                  | ((0x0340U 
                                                      == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                                     << 2U)) 
                                                 | (((0x0305U 
                                                      == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                                     << 1U) 
                                                    | (0x0300U 
                                                       == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))))))))) {
                if ((0U != ((((((0x0f12U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                << 4U) | (((0x0344U 
                                            == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                           << 3U) | 
                                          ((0x0304U 
                                            == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                           << 2U))) 
                              | (((0x0343U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                  << 1U) | (0x0342U 
                                            == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)))) 
                             << 4U) | ((((0x0341U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                         << 3U) | (
                                                   (0x0340U 
                                                    == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                                   << 2U)) 
                                       | (((0x0305U 
                                            == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                                           << 1U) | 
                                          (0x0300U 
                                           == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: csr_file.sv:69: Assertion failed in %m: unique case, but multiple matches found for '12'h%X'\n",4, 'M',vlSymsp->name(),"tb_core.core.csr_file", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',12,(IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb));
                        VL_STOP_MT("rtl/csr_file.sv", 69, "");
                    }
                }
            }
            if (((((((((0x0300U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)) 
                       | (0x0305U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) 
                      | (0x0340U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) 
                     | (0x0341U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) 
                    | (0x0342U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) 
                   | (0x0343U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) 
                  | (0x0304U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) 
                 | (0x0344U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb)))) {
                if ((0x0300U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) {
                    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mstatus 
                        = vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb;
                } else if ((0x0305U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) {
                    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mtvec 
                        = vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb;
                } else if ((0x0340U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) {
                    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mscratch 
                        = vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb;
                } else if ((0x0341U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) {
                    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mepc 
                        = vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb;
                } else if ((0x0342U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) {
                    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mcause 
                        = vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb;
                } else if ((0x0343U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) {
                    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mtval 
                        = vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb;
                } else if ((0x0304U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) {
                    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mie 
                        = vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb;
                } else {
                    vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mip 
                        = vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb;
                }
            } else if ((0x0f12U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb))) {
                vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__marchid 
                    = vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb;
            }
        }
        vlSelfRef.tb_core__DOT__core__DOT__rs2_data_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex;
        vlSelfRef.tb_core__DOT__core__DOT__r_data_wb 
            = ((IData)(vlSelfRef.tb_core__DOT__core__DOT__sign_extend_mem)
                ? ((0x00008000U & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__shifted_mask)
                    ? VL_EXTENDS_II(32,16, (0x0000ffffU 
                                            & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw))
                    : ((0x00000080U & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__shifted_mask)
                        ? VL_EXTENDS_II(32,8, (0x000000ffU 
                                               & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw))
                        : vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw))
                : vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw);
        vlSelfRef.tb_core__DOT__core__DOT__rd_wb = vlSelfRef.tb_core__DOT__core__DOT__rd_mem;
        vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb 
            = vlSelfRef.tb_core__DOT__core__DOT__wb_sel_mem;
        vlSelfRef.tb_core__DOT__core__DOT__csr_content_wb 
            = vlSelfRef.tb_core__DOT__core__DOT__csr_content_mem;
        vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_wb 
            = vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_mem;
        vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb 
            = vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem;
        vlSelfRef.tb_core__DOT__core__DOT__lui_wb = vlSelfRef.tb_core__DOT__core__DOT__lui_mem;
        vlSelfRef.tb_core__DOT__core__DOT__pc_mem = vlSelfRef.tb_core__DOT__core__DOT__pc_ex;
        vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_ex;
        vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex;
        if (vlSelfRef.tb_core__DOT__core__DOT__stall) {
            __Vdly__tb_core__DOT__core__DOT__pc_if 
                = vlSelfRef.tb_core__DOT__core__DOT__pc_if;
            vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_ex = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex = 0U;
        } else {
            __Vdly__tb_core__DOT__core__DOT__pc_if 
                = vlSelfRef.tb_core__DOT__core__DOT__pc_next;
            vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_ex 
                = (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                   >> 0x00000014U);
            vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex 
                = (0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                  >> 7U));
        }
        vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb 
            = vlSelfRef.tb_core__DOT__core__DOT__csr_reg_mem;
        vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb 
            = vlSelfRef.tb_core__DOT__core__DOT__csr_data_mem;
        vlSelfRef.tb_core__DOT__core__DOT__rd_mem = vlSelfRef.tb_core__DOT__core__DOT__rd_ex;
        vlSelfRef.tb_core__DOT__core__DOT__wb_sel_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__wb_sel_ex;
        vlSelfRef.tb_core__DOT__core__DOT__csr_content_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__csr_content_ex;
        vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_ex;
        vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__alu_result_ex;
        vlSelfRef.tb_core__DOT__core__DOT__lui_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__imm_ex;
        vlSelfRef.tb_core__DOT__core__DOT__csr_reg_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__csr_reg_ex;
        vlSelfRef.tb_core__DOT__core__DOT__csr_data_mem 
            = vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex;
    } else {
        __Vdly__tb_core__DOT__core__DOT__pc_plus_4_id = 0U;
        __Vdly__tb_core__DOT__core__DOT__pc_if = 0x00004000U;
        __Vdly__tb_core__DOT__core__DOT__pc_id = 0U;
        __Vdly__tb_core__DOT__core__DOT__instr_id = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__funct3_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__opcode_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__misa = 0x40000100U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mstatus = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mtvec = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mepc = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mcause = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mscratch = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mtval = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mie = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mip = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mvendorid = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mimpid = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__marchid = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mhartid = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__rs2_data_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__r_data_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__rd_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_content_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__lui_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__rd_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__wb_sel_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_content_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__lui_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_reg_mem = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__csr_data_mem = 0U;
    }
    __Vdly__tb_core__DOT__core__DOT__mem_w_ex = ((1U 
                                                  & (~ 
                                                     ((~ (IData)(vlSelfRef.tb_core__DOT__rst_n)) 
                                                      | (IData)(vlSelfRef.tb_core__DOT__core__DOT__flush_ex)))) 
                                                 && ((IData)(vlSelfRef.tb_core__DOT__core__DOT__stall)
                                                      ? (IData)(vlSelfRef.tb_core__DOT__core__DOT__mem_w_ex)
                                                      : (IData)(vlSelfRef.tb_core__DOT__core__DOT__mem_w_id)));
    if ((1U & ((~ (IData)(vlSelfRef.tb_core__DOT__rst_n)) 
               | (IData)(vlSelfRef.tb_core__DOT__core__DOT__flush_ex)))) {
        __Vdly__tb_core__DOT__core__DOT__wb_sel_ex = 0U;
        __Vdly__tb_core__DOT__core__DOT__pc_plus_4_ex = 0U;
        __Vdly__tb_core__DOT__core__DOT__csr_content_ex = 0U;
        __Vdly__tb_core__DOT__core__DOT__rd_ex = 0U;
        __Vdly__tb_core__DOT__core__DOT__csr_reg_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__funct7_ex = 0U;
        __Vdly__tb_core__DOT__core__DOT__funct3_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__zimm_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex = 0U;
        __Vdly__tb_core__DOT__core__DOT__imm_ex = 0U;
        __Vdly__tb_core__DOT__core__DOT__pc_ex = 0U;
        __Vdly__tb_core__DOT__core__DOT__rs2_data_ex = 0U;
        __Vdly__tb_core__DOT__core__DOT__opcode_ex = 0U;
    } else if (vlSelfRef.tb_core__DOT__core__DOT__stall) {
        __Vdly__tb_core__DOT__core__DOT__wb_sel_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__wb_sel_ex;
        __Vdly__tb_core__DOT__core__DOT__pc_plus_4_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_ex;
        __Vdly__tb_core__DOT__core__DOT__csr_content_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__csr_content_ex;
        __Vdly__tb_core__DOT__core__DOT__rd_ex = (0x0000001fU 
                                                  & (IData)(vlSelfRef.tb_core__DOT__core__DOT__rd_ex));
        __Vdly__tb_core__DOT__core__DOT__csr_reg_ex 
            = (0x00000fffU & (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_ex));
        vlSelfRef.tb_core__DOT__core__DOT__funct7_ex 
            = (0x0000007fU & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct7_ex));
        __Vdly__tb_core__DOT__core__DOT__funct3_ex 
            = (7U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex));
        vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_ex;
        vlSelfRef.tb_core__DOT__core__DOT__zimm_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__zimm_ex;
        vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex;
        __Vdly__tb_core__DOT__core__DOT__imm_ex = vlSelfRef.tb_core__DOT__core__DOT__imm_ex;
        __Vdly__tb_core__DOT__core__DOT__pc_ex = vlSelfRef.tb_core__DOT__core__DOT__pc_ex;
        __Vdly__tb_core__DOT__core__DOT__rs2_data_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex;
        __Vdly__tb_core__DOT__core__DOT__opcode_ex 
            = (0x0000007fU & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex));
    } else {
        __Vdly__tb_core__DOT__core__DOT__wb_sel_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id;
        __Vdly__tb_core__DOT__core__DOT__pc_plus_4_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_id;
        __Vdly__tb_core__DOT__core__DOT__csr_content_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__csr_content_id;
        __Vdly__tb_core__DOT__core__DOT__rd_ex = (0x0000001fU 
                                                  & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                     >> 7U));
        __Vdly__tb_core__DOT__core__DOT__csr_reg_ex 
            = (0x00000fffU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                              >> 0x00000014U));
        vlSelfRef.tb_core__DOT__core__DOT__funct7_ex 
            = (0x0000007fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                              >> 0x00000019U));
        __Vdly__tb_core__DOT__core__DOT__funct3_ex 
            = (7U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                     >> 0x0000000cU));
        vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id;
        vlSelfRef.tb_core__DOT__core__DOT__zimm_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__zimm_id;
        vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
            = vlSelfRef.tb_core__DOT__core__DOT__rs1_data_id;
        __Vdly__tb_core__DOT__core__DOT__imm_ex = vlSelfRef.tb_core__DOT__core__DOT__imm_id;
        __Vdly__tb_core__DOT__core__DOT__pc_ex = vlSelfRef.tb_core__DOT__core__DOT__pc_id;
        __Vdly__tb_core__DOT__core__DOT__rs2_data_ex 
            = (vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
               [(0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                >> 0x00000014U))] & 
               (- (IData)((0U != (0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 0x00000014U))))));
        __Vdly__tb_core__DOT__core__DOT__opcode_ex 
            = (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id);
    }
    __Vdly__tb_core__DOT__core__DOT__reg_write_ex = 
        ((1U & (~ ((~ (IData)(vlSelfRef.tb_core__DOT__rst_n)) 
                   | (IData)(vlSelfRef.tb_core__DOT__core__DOT__flush_ex)))) 
         && ((IData)(vlSelfRef.tb_core__DOT__core__DOT__stall)
              ? (IData)(vlSelfRef.tb_core__DOT__core__DOT__reg_write_ex)
              : (IData)(vlSelfRef.tb_core__DOT__core__DOT__reg_write_id)));
    __Vdly__tb_core__DOT__core__DOT__csr_write_ex = 
        ((1U & (~ ((~ (IData)(vlSelfRef.tb_core__DOT__rst_n)) 
                   | (IData)(vlSelfRef.tb_core__DOT__core__DOT__flush_ex)))) 
         && ((IData)(vlSelfRef.tb_core__DOT__core__DOT__stall)
              ? (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_write_ex)
              : (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_w_en_id)));
    vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex = 
        ((1U & (~ ((~ (IData)(vlSelfRef.tb_core__DOT__rst_n)) 
                   | (IData)(vlSelfRef.tb_core__DOT__core__DOT__flush_ex)))) 
         && ((IData)(vlSelfRef.tb_core__DOT__core__DOT__stall)
              ? (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex)
              : (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id)));
    if ((1U & (~ (IData)(vlSelfRef.tb_core__DOT__rst_n)))) {
        vlSelfRef.tb_core__DOT__core__DOT__imem_en = 0U;
    }
    vlSelfRef.tb_core__DOT__core__DOT__imem_en = 1U;
    vlSelfRef.tb_core__DOT__core__DOT__mem_w_wb = ((IData)(vlSelfRef.tb_core__DOT__rst_n) 
                                                   && (IData)(vlSelfRef.tb_core__DOT__core__DOT__mem_w_mem));
    vlSelfRef.tb_core__DOT__core__DOT__alu_zero_wb 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_mem));
    vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_wb 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_mem));
    vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_wb 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_mem));
    vlSelfRef.tb_core__DOT__core__DOT__reg_write_wb 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__reg_write_mem));
    vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_id 
        = __Vdly__tb_core__DOT__core__DOT__pc_plus_4_id;
    vlSelfRef.tb_core__DOT__core__DOT__pc_id = __Vdly__tb_core__DOT__core__DOT__pc_id;
    vlSelfRef.tb_core__DOT__core__DOT__pc_if = __Vdly__tb_core__DOT__core__DOT__pc_if;
    vlSelfRef.tb_core__DOT__core__DOT__funct3_ex = __Vdly__tb_core__DOT__core__DOT__funct3_ex;
    vlSelfRef.tb_core__DOT__core__DOT__opcode_ex = __Vdly__tb_core__DOT__core__DOT__opcode_ex;
    vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex 
        = __Vdly__tb_core__DOT__core__DOT__rs2_data_ex;
    vlSelfRef.tb_core__DOT__core__DOT__sign_extend_mem 
        = ((1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem) 
                     >> 2U))) && (1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem) 
                                           >> 1U))));
    vlSelfRef.tb_core__DOT__core__DOT__mem_w_mem = 
        ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__mem_w_ex));
    vlSelfRef.tb_core__DOT__core__DOT__alu_zero_mem 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_out_ex));
    __VdfgRegularize_hebeb780c_0_2 = (IData)((1U == 
                                              (5U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))));
    vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_mem 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_ex));
    vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_mem 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_ex));
    vlSelfRef.tb_core__DOT__core__DOT__csr_write_wb 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_write_mem));
    vlSelfRef.tb_core__DOT__core__DOT__reg_write_mem 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__reg_write_ex));
    vlSelfRef.tb_core__DOT__core__DOT__mem_w_ex = __Vdly__tb_core__DOT__core__DOT__mem_w_ex;
    __VdfgRegularize_hebeb780c_0_3 = (0x0000000fU & 
                                      (- (IData)(((IData)(__VdfgRegularize_hebeb780c_0_2) 
                                                  & (2U 
                                                     == 
                                                     (0x0aU 
                                                      & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex)))))));
    vlSelfRef.tb_core__DOT__core__DOT__pc_ex = __Vdly__tb_core__DOT__core__DOT__pc_ex;
    vlSelfRef.tb_core__DOT__core__DOT__reg_write_ex 
        = __Vdly__tb_core__DOT__core__DOT__reg_write_ex;
    vlSelfRef.tb_core__DOT__core__DOT__rd_ex = __Vdly__tb_core__DOT__core__DOT__rd_ex;
    vlSelfRef.tb_core__DOT__core__DOT__wb_sel_ex = __Vdly__tb_core__DOT__core__DOT__wb_sel_ex;
    vlSelfRef.tb_core__DOT__core__DOT__csr_content_ex 
        = __Vdly__tb_core__DOT__core__DOT__csr_content_ex;
    vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_ex 
        = __Vdly__tb_core__DOT__core__DOT__pc_plus_4_ex;
    vlSelfRef.tb_core__DOT__core__DOT__imm_ex = __Vdly__tb_core__DOT__core__DOT__imm_ex;
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
    vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_ex 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && 
           ((~ (IData)(vlSelfRef.tb_core__DOT__core__DOT__stall)) 
            & (IData)(vlSelfRef.tb_core__DOT__core__DOT__reg_write_id)));
    vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_ex 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && 
           ((~ (IData)(vlSelfRef.tb_core__DOT__core__DOT__stall)) 
            & (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_w_en_id)));
    vlSelfRef.tb_core__DOT__core__DOT__csr_write_mem 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__csr_write_ex));
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
    vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
        = ((IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex)
            ? vlSelfRef.tb_core__DOT__core__DOT__imm_ex
            : vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex);
    vlSelfRef.tb_core__DOT__core__DOT__instr_id = __Vdly__tb_core__DOT__core__DOT__instr_id;
    vlSelfRef.tb_core__DOT__core__DOT__csr_write_ex 
        = __Vdly__tb_core__DOT__core__DOT__csr_write_ex;
    vlSelfRef.tb_core__DOT__core__DOT__csr_reg_ex = __Vdly__tb_core__DOT__core__DOT__csr_reg_ex;
    vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex 
        = ((1U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_ex))
            ? vlSelfRef.tb_core__DOT__core__DOT__pc_ex
            : ((2U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_ex))
                ? vlSelfRef.tb_core__DOT__core__DOT__zimm_ex
                : vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex));
    vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__shifted_mask 
        = (vlSelfRef.tb_core__DOT__core__DOT__bit_mask_mem 
           >> (IData)(vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem));
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
    vlSelfRef.tb_core__DOT__core__DOT__zimm_id = ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                  >> 0x00000013U)))) 
                                                   << 4U) 
                                                  | (0x0000000fU 
                                                     & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                        >> 0x0000000fU)));
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
    if (vlSelfRef.tb_core__DOT__core__DOT__stall) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump = 0U;
    } else if (((0x63U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex)) 
                & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_out_ex))) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump = 1U;
    } else if ((0x6fU == (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id))) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump = 1U;
    } else if ((0x67U == (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id))) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump = 1U;
    }
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
}

void Vtb_core___024root___nba_sequent__TOP__2(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_sequent__TOP__2\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0) {
        vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__mem[vlSelfRef.__VdlyDim0__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0] 
            = vlSelfRef.__VdlyVal__tb_core__DOT__core__DOT__main_mem__DOT__mem__v0;
    }
    if (vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0) {
        vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[vlSelfRef.__VdlyDim0__tb_core__DOT__core__DOT__regfile__DOT__regs__v0] 
            = vlSelfRef.__VdlyVal__tb_core__DOT__core__DOT__regfile__DOT__regs__v0;
    }
    vlSelfRef.tb_core__DOT__y = vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[10U];
}

void Vtb_core___024root___nba_comb__TOP__0(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_comb__TOP__0\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw 
        = ((vlSelfRef.tb_core__DOT__core__DOT__bit_mask_mem 
            & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__mem
            [(0x0003ffffU & ((vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem 
                              - (IData)(0x00004000U)) 
                             >> 2U))]) >> (IData)(vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem));
    vlSelfRef.tb_core__DOT__core__DOT__rs1_data_id 
        = (vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
           [(0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                            >> 0x0000000fU))] & (- (IData)(
                                                           (0U 
                                                            != 
                                                            (0x0000001fU 
                                                             & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                                >> 0x0000000fU))))));
    vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__jalr_target_raw 
        = (vlSelfRef.tb_core__DOT__core__DOT__imm_id 
           + vlSelfRef.tb_core__DOT__core__DOT__rs1_data_id);
    vlSelfRef.tb_core__DOT__core__DOT__pc_next = ((IData)(vlSelfRef.tb_core__DOT__core__DOT__stall)
                                                   ? vlSelfRef.tb_core__DOT__core__DOT__pc_if
                                                   : 
                                                  (((0x63U 
                                                     == (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex)) 
                                                    & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_out_ex))
                                                    ? 
                                                   (vlSelfRef.tb_core__DOT__core__DOT__pc_ex 
                                                    + vlSelfRef.tb_core__DOT__core__DOT__imm_ex)
                                                    : 
                                                   ((0x6fU 
                                                     == 
                                                     (0x0000007fU 
                                                      & vlSelfRef.tb_core__DOT__core__DOT__instr_id))
                                                     ? 
                                                    (vlSelfRef.tb_core__DOT__core__DOT__pc_id 
                                                     + vlSelfRef.tb_core__DOT__core__DOT__imm_id)
                                                     : 
                                                    ((0x67U 
                                                      == 
                                                      (0x0000007fU 
                                                       & vlSelfRef.tb_core__DOT__core__DOT__instr_id))
                                                      ? 
                                                     (0xfffffffeU 
                                                      & vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__jalr_target_raw)
                                                      : 
                                                     ((IData)(4U) 
                                                      + vlSelfRef.tb_core__DOT__core__DOT__pc_if)))));
}

void Vtb_core___024root___eval_nba(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___eval_nba\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_core___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_core___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_core___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_core___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
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
