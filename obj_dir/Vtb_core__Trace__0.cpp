// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_core__Syms.h"


void Vtb_core___024root__trace_chg_0_sub_0(Vtb_core___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_core___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root__trace_chg_0\n"); );
    // Body
    Vtb_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_core___024root*>(voidSelf);
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_core___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_core___024root__trace_chg_dtype____0(Vtb_core___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vtb_core___024root__trace_chg_0_sub_0(Vtb_core___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root__trace_chg_0_sub_0\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb_core__DOT__core__DOT__pc_id),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb_core__DOT__core__DOT__instr_id),32);
        bufp->chgCData(oldp+2,((0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id)),7);
        bufp->chgCData(oldp+3,((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                               >> 7U))),5);
        bufp->chgCData(oldp+4,((7U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                      >> 0x0000000cU))),3);
        bufp->chgCData(oldp+5,((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                >> 0x00000019U)),7);
        bufp->chgCData(oldp+6,((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                               >> 0x0000000fU))),5);
        bufp->chgCData(oldp+7,((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                               >> 0x00000014U))),5);
        bufp->chgIData(oldp+8,(vlSelfRef.tb_core__DOT__core__DOT__imm_id),32);
        bufp->chgBit(oldp+9,(vlSelfRef.tb_core__DOT__core__DOT__mem_w_id));
        bufp->chgBit(oldp+10,(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id));
        bufp->chgBit(oldp+11,(vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id));
        bufp->chgBit(oldp+12,(vlSelfRef.tb_core__DOT__core__DOT__reg_write_id));
        bufp->chgCData(oldp+13,(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id),3);
        bufp->chgCData(oldp+14,(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex),7);
        bufp->chgCData(oldp+15,(vlSelfRef.tb_core__DOT__core__DOT__rd_ex),5);
        bufp->chgCData(oldp+16,(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex),3);
        bufp->chgCData(oldp+17,(vlSelfRef.tb_core__DOT__core__DOT__funct7_ex),7);
        bufp->chgIData(oldp+18,(vlSelfRef.tb_core__DOT__core__DOT__imm_ex),32);
        bufp->chgIData(oldp+19,(vlSelfRef.tb_core__DOT__core__DOT__pc_ex),32);
        bufp->chgBit(oldp+20,(vlSelfRef.tb_core__DOT__core__DOT__mem_w_ex));
        bufp->chgBit(oldp+21,(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex));
        bufp->chgBit(oldp+22,(vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_ex));
        bufp->chgBit(oldp+23,(vlSelfRef.tb_core__DOT__core__DOT__reg_write_ex));
        bufp->chgCData(oldp+24,(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_ex),3);
        bufp->chgCData(oldp+25,(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex),4);
        bufp->chgIData(oldp+26,(vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex),32);
        bufp->chgIData(oldp+27,(vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex),32);
        bufp->chgIData(oldp+28,(vlSelfRef.tb_core__DOT__core__DOT__alu_result_ex),32);
        bufp->chgIData(oldp+29,(vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex),32);
        bufp->chgIData(oldp+30,(vlSelfRef.tb_core__DOT__core__DOT__pc_wb),32);
        bufp->chgCData(oldp+31,(vlSelfRef.tb_core__DOT__core__DOT__rd_wb),5);
        bufp->chgBit(oldp+32,(vlSelfRef.tb_core__DOT__core__DOT__mem_w_wb));
        bufp->chgBit(oldp+33,(vlSelfRef.tb_core__DOT__core__DOT__reg_write_wb));
        bufp->chgCData(oldp+34,(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb),3);
        bufp->chgIData(oldp+35,(vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb),32);
        bufp->chgIData(oldp+36,(vlSelfRef.tb_core__DOT__core__DOT__pc_mem),32);
        bufp->chgCData(oldp+37,(vlSelfRef.tb_core__DOT__core__DOT__rd_mem),5);
        bufp->chgBit(oldp+38,(vlSelfRef.tb_core__DOT__core__DOT__mem_w_mem));
        bufp->chgCData(oldp+39,(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_mem),3);
        bufp->chgBit(oldp+40,(vlSelfRef.tb_core__DOT__core__DOT__reg_write_mem));
        bufp->chgIData(oldp+41,(vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem),32);
        bufp->chgIData(oldp+42,(vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output),32);
        bufp->chgIData(oldp+43,((vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
                                 - vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)),32);
        bufp->chgIData(oldp+44,((vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
                                 ^ vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)),32);
        bufp->chgIData(oldp+45,((vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
                                 | vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)),32);
        bufp->chgIData(oldp+46,((vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
                                 & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)),32);
        bufp->chgIData(oldp+47,(VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex, 
                                               (0x0000001fU 
                                                & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))),32);
        bufp->chgIData(oldp+48,(VL_SHIFTL_III(32,32,32, vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex, 
                                              (0x0000001fU 
                                               & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))),32);
        bufp->chgIData(oldp+49,(VL_SHIFTR_III(32,32,32, vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex, 
                                              (0x0000001fU 
                                               & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))),32);
        bufp->chgIData(oldp+50,(VL_LTS_III(32, vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex, vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)),32);
        bufp->chgIData(oldp+51,((vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex 
                                 < vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex)),32);
        bufp->chgIData(oldp+52,(vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I),32);
        bufp->chgIData(oldp+53,((((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                              >> 0x0000001fU))) 
                                  << 0x0000000bU) | 
                                 ((0x000007e0U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                  >> 0x00000014U)) 
                                  | (0x0000001fU & 
                                     (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                      >> 7U))))),32);
        bufp->chgIData(oldp+54,((((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                              >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 ((0x00000800U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                  << 4U)) 
                                  | ((0x000007e0U & 
                                      (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                       >> 0x00000014U)) 
                                     | (0x0000001eU 
                                        & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                           >> 7U)))))),32);
        bufp->chgIData(oldp+55,((0xfffff000U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)),32);
        bufp->chgIData(oldp+56,((((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                              >> 0x0000001fU))) 
                                  << 0x00000014U) | 
                                 ((((0x000001feU & 
                                     (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                      >> 0x0000000bU)) 
                                    | (1U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                             >> 0x00000014U))) 
                                   << 0x0000000bU) 
                                  | (0x000007feU & 
                                     (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                      >> 0x00000014U))))),32);
        bufp->chgCData(oldp+57,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__reg_addr_ex),5);
        bufp->chgCData(oldp+58,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__reg_addr_mem),5);
        bufp->chgCData(oldp+59,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__reg_addr_wb),5);
        bufp->chgBit(oldp+60,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__detect));
        bufp->chgBit(oldp+61,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__toggle));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+62,(vlSelfRef.tb_core__DOT__y),32);
        bufp->chgIData(oldp+63,(vlSelfRef.tb_core__DOT__core__DOT__instr_if),32);
        Vtb_core___024root__trace_chg_dtype____0(vlSelf, bufp, 64, vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs);
    }
    bufp->chgBit(oldp+96,(vlSelfRef.tb_core__DOT__clk));
    bufp->chgBit(oldp+97,(vlSelfRef.tb_core__DOT__rst_n));
    bufp->chgIData(oldp+98,(vlSelfRef.tb_core__DOT__i),32);
    bufp->chgIData(oldp+99,(vlSelfRef.tb_core__DOT__core__DOT__pc_if),32);
    bufp->chgBit(oldp+100,(vlSelfRef.tb_core__DOT__core__DOT__imem_en));
    bufp->chgBit(oldp+101,(vlSelfRef.tb_core__DOT__core__DOT__stall));
    bufp->chgIData(oldp+102,((vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
                              [(0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                               >> 0x0000000fU))] 
                              & (- (IData)((0U != (0x0000001fU 
                                                   & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                      >> 0x0000000fU))))))),32);
    bufp->chgIData(oldp+103,((vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
                              [(0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                               >> 0x00000014U))] 
                              & (- (IData)((0U != (0x0000001fU 
                                                   & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                      >> 0x00000014U))))))),32);
    bufp->chgIData(oldp+104,(vlSelfRef.tb_core__DOT__core__DOT__dmem__DOT__mem
                             [(0x000003ffU & (vlSelfRef.tb_core__DOT__core__DOT__alu_result_ex 
                                              >> 2U))]),32);
    bufp->chgIData(oldp+105,((vlSelfRef.tb_core__DOT__core__DOT__pc_if 
                              + (4U & ((~ (IData)(vlSelfRef.tb_core__DOT__core__DOT__stall)) 
                                       << 2U)))),32);
}

void Vtb_core___024root__trace_chg_dtype____0(Vtb_core___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root__trace_chg_dtype____0\n"); );
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[31]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[0]),32);
}

void Vtb_core___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_core___024root__trace_cleanup\n"); );
    // Body
    Vtb_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_core___024root*>(voidSelf);
    Vtb_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
