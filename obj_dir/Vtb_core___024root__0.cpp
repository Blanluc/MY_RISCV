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
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000064ULL, 
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
    if (vlSelfRef.tb_core__DOT__rst_n) {
        vlSelfRef.__Vdly__tb_core__DOT__core__DOT__pc_if 
            = ((IData)(4U) + vlSelfRef.tb_core__DOT__core__DOT__pc_if);
        vlSelfRef.tb_core__DOT__core__DOT__funct7_ex 
            = (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
               >> 0x00000019U);
        vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex 
            = (vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
               [(0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                >> 0x00000014U))] & 
               (- (IData)((0U != (0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 0x00000014U))))));
        vlSelfRef.tb_core__DOT__core__DOT__opcode_ex 
            = (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id);
        vlSelfRef.tb_core__DOT__core__DOT__funct3_ex 
            = (7U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                     >> 0x0000000cU));
    } else {
        vlSelfRef.__Vdly__tb_core__DOT__core__DOT__pc_if = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__funct7_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__opcode_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__funct3_ex = 0U;
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_8 = (((4U 
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
}

void Vtb_core___024root___nba_sequent__TOP__1(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_sequent__TOP__1\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 = 0U;
    VL_WRITEF_NX("CYCLE=%d\n---------------------------\nSTAGE IF : PC=%0h INSTR=%0h\nREG_FILE : x0=%0d x1=%0d x2=%0d x3=%0d x4=%0d\n---------------------------\nSTAGE ID : PC=%0h INSTR=%0h OPCODE=%0b\n---------------------------\nSTAGE EX : PC=%0h ALU_IN_A=%0d ALU_IN_B=%0d, IMM=%0d, RS2_SEL=%0d\n---------------------------\nSTAGE WB : PC=%0h\n---------------------------\n",17
                 , '~',32,vlSelfRef.tb_core__DOT__i
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_if
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__instr_if
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[0U]
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[1U]
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[2U]
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[3U]
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[4U]
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_id
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__instr_id
                 , '#',7,(0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_ex
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__imm_ex
                 , '#',1,(IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex)
                 , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_wb);
    vlSelfRef.tb_core__DOT__i = ((IData)(1U) + vlSelfRef.tb_core__DOT__i);
    if (((IData)(vlSelfRef.tb_core__DOT__core__DOT__reg_write_wb) 
         & (0U != (IData)(vlSelfRef.tb_core__DOT__core__DOT__rd_wb)))) {
        vlSelfRef.__VdlyVal__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 
            = vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb;
        vlSelfRef.__VdlyDim0__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 
            = vlSelfRef.tb_core__DOT__core__DOT__rd_wb;
        vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 = 1U;
    }
}

extern const VlUnpacked<CData/*0:0*/, 128> Vtb_core__ConstPool__TABLE_h4988eadb_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_core__ConstPool__TABLE_h1ad98872_0;

void Vtb_core___024root___nba_sequent__TOP__2(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_sequent__TOP__2\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex = 
        ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id));
    if (vlSelfRef.tb_core__DOT__rst_n) {
        vlSelfRef.tb_core__DOT__core__DOT__pc_wb = vlSelfRef.tb_core__DOT__core__DOT__pc_ex;
        vlSelfRef.tb_core__DOT__core__DOT__imm_ex = 
            ((0x00000040U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
              ? ((0x00000020U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                  ? ((0x00000010U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                      ? vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I
                      : ((8U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                          ? ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                              ? ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                  ? ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                      ? (((- (IData)(
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
                          : ((4U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                              ? vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I
                              : ((2U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                  ? ((1U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                                      ? (((- (IData)(
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
              : ((0x00000020U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                  ? ((0x00000010U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                      ? vlSelfRef.__VdfgRegularize_hebeb780c_0_1
                      : (((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                      >> 0x0000001fU))) 
                          << 0x0000000bU) | (0x000007ffU 
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
                  : ((0x00000010U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                      ? vlSelfRef.__VdfgRegularize_hebeb780c_0_1
                      : vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I)));
        vlSelfRef.tb_core__DOT__core__DOT__rd_wb = vlSelfRef.tb_core__DOT__core__DOT__rd_ex;
        vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb 
            = ((8U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                ? ((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                    ? vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output
                    : ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                        ? vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output
                        : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                            ? VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex, 
                                             (0x0000001fU 
                                              & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))
                            : VL_SHIFTR_III(32,32,32, vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex, 
                                            (0x0000001fU 
                                             & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)))))
                : ((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                    ? ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                        ? ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                            ? VL_SHIFTL_III(32,32,32, vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex, 
                                            (0x0000001fU 
                                             & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))
                            : (vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
                               < vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))
                        : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                            ? VL_LTS_III(32, vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex, vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)
                            : (vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
                               ^ vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)))
                    : ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                        ? ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                            ? (vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
                               | vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)
                            : (vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
                               & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))
                        : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex))
                            ? (vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
                               - vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)
                            : vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output))));
        vlSelfRef.tb_core__DOT__core__DOT__pc_ex = vlSelfRef.tb_core__DOT__core__DOT__pc_id;
        vlSelfRef.tb_core__DOT__core__DOT__rd_ex = 
            (0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                            >> 7U));
        vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
            = (vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
               [(0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                >> 0x0000000fU))] & 
               (- (IData)((0U != (0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                 >> 0x0000000fU))))));
        vlSelfRef.tb_core__DOT__core__DOT__pc_id = vlSelfRef.tb_core__DOT__core__DOT__pc_if;
        vlSelfRef.tb_core__DOT__core__DOT__instr_id 
            = vlSelfRef.tb_core__DOT__core__DOT__instr_if;
    } else {
        vlSelfRef.tb_core__DOT__core__DOT__pc_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__imm_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__rd_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__rd_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__pc_id = 0U;
        vlSelfRef.tb_core__DOT__core__DOT__instr_id = 0U;
    }
    vlSelfRef.tb_core__DOT__core__DOT__reg_write_wb 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__reg_write_ex));
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
                 ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8) 
                  & ((- (IData)((1U & ((IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex) 
                                       >> 4U)))) & 
                     (- (IData)((1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex) 
                                          >> 2U))))))))
              : ((- (IData)((1U & (~ ((IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex) 
                                      >> 3U))))) & 
                 (((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))
                    ? (7U & (- (IData)((3U == (3U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))))))
                    : (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8)) 
                  & (- (IData)((1U & ((IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex) 
                                      >> 4U))))))));
    vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
        = ((IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex)
            ? vlSelfRef.tb_core__DOT__core__DOT__imm_ex
            : vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex);
    vlSelfRef.tb_core__DOT__core__DOT__reg_write_ex 
        = ((IData)(vlSelfRef.tb_core__DOT__rst_n) && (IData)(vlSelfRef.tb_core__DOT__core__DOT__reg_write_id));
    vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output 
        = (vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
           + vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex);
    vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I 
        = (((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                        >> 0x0000001fU))) << 0x0000000bU) 
           | (0x000007ffU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                             >> 0x00000014U)));
    __Vtableidx1 = (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id);
    vlSelfRef.tb_core__DOT__core__DOT__reg_write_id 
        = Vtb_core__ConstPool__TABLE_h4988eadb_0[__Vtableidx1];
    vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id = Vtb_core__ConstPool__TABLE_h1ad98872_0
        [__Vtableidx1];
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

void Vtb_core___024root___nba_sequent__TOP__3(Vtb_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root___nba_sequent__TOP__3\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0) {
        vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[vlSelfRef.__VdlyDim0__tb_core__DOT__core__DOT__regfile__DOT__regs__v0] 
            = vlSelfRef.__VdlyVal__tb_core__DOT__core__DOT__regfile__DOT__regs__v0;
    }
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
        if (vlSelfRef.tb_core__DOT__rst_n) {
            vlSelfRef.__Vdly__tb_core__DOT__core__DOT__pc_if 
                = ((IData)(4U) + vlSelfRef.tb_core__DOT__core__DOT__pc_if);
            vlSelfRef.tb_core__DOT__core__DOT__funct7_ex 
                = (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                   >> 0x00000019U);
            vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex 
                = (vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
                   [(0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                    >> 0x00000014U))] 
                   & (- (IData)((0U != (0x0000001fU 
                                        & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                           >> 0x00000014U))))));
            vlSelfRef.tb_core__DOT__core__DOT__opcode_ex 
                = (0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id);
            vlSelfRef.tb_core__DOT__core__DOT__funct3_ex 
                = (7U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                         >> 0x0000000cU));
        } else {
            vlSelfRef.__Vdly__tb_core__DOT__core__DOT__pc_if = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__funct7_ex = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__opcode_ex = 0U;
            vlSelfRef.tb_core__DOT__core__DOT__funct3_ex = 0U;
        }
        vlSelfRef.__VdfgRegularize_hebeb780c_0_8 = 
            (((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
               ? ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                   ? ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                       ? 2U : 3U) : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex))
                                      ? ((0U == (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct7_ex))
                                          ? 8U : ((0x20U 
                                                   == (IData)(vlSelfRef.tb_core__DOT__core__DOT__funct7_ex))
                                                   ? 9U
                                                   : 8U))
                                      : 4U)) : ((2U 
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
             & (- (IData)((3U == (3U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex))))));
    }
    if (VL_UNLIKELY(((1ULL & vlSelfRef.__VnbaTriggered[0U])))) {
        vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 = 0U;
        VL_WRITEF_NX("CYCLE=%d\n---------------------------\nSTAGE IF : PC=%0h INSTR=%0h\nREG_FILE : x0=%0d x1=%0d x2=%0d x3=%0d x4=%0d\n---------------------------\nSTAGE ID : PC=%0h INSTR=%0h OPCODE=%0b\n---------------------------\nSTAGE EX : PC=%0h ALU_IN_A=%0d ALU_IN_B=%0d, IMM=%0d, RS2_SEL=%0d\n---------------------------\nSTAGE WB : PC=%0h\n---------------------------\n",17
                     , '~',32,vlSelfRef.tb_core__DOT__i
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_if
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__instr_if
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[0U]
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[1U]
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[2U]
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[3U]
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[4U]
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_id
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__instr_id
                     , '#',7,(0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id)
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_ex
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__imm_ex
                     , '#',1,(IData)(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex)
                     , '#',32,vlSelfRef.tb_core__DOT__core__DOT__pc_wb);
        vlSelfRef.tb_core__DOT__i = ((IData)(1U) + vlSelfRef.tb_core__DOT__i);
        if (((IData)(vlSelfRef.tb_core__DOT__core__DOT__reg_write_wb) 
             & (0U != (IData)(vlSelfRef.tb_core__DOT__core__DOT__rd_wb)))) {
            vlSelfRef.__VdlyVal__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 
                = vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb;
            vlSelfRef.__VdlyDim0__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 
                = vlSelfRef.tb_core__DOT__core__DOT__rd_wb;
            vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0 = 1U;
        }
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_core___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        if (vlSelfRef.__VdlySet__tb_core__DOT__core__DOT__regfile__DOT__regs__v0) {
            vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs[vlSelfRef.__VdlyDim0__tb_core__DOT__core__DOT__regfile__DOT__regs__v0] 
                = vlSelfRef.__VdlyVal__tb_core__DOT__core__DOT__regfile__DOT__regs__v0;
        }
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
