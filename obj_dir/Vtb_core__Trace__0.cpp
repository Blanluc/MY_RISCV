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
        bufp->chgIData(oldp+0,(vlSelfRef.tb_core__DOT__cycle_count),32);
        bufp->chgBit(oldp+1,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_busy));
        bufp->chgCData(oldp+2,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_data),8);
        bufp->chgBit(oldp+3,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_tx_en));
        bufp->chgBit(oldp+4,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_write_en_prev));
        bufp->chgIData(oldp+5,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__write_counter),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__read_counter),32);
        bufp->chgIData(oldp+7,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_addr),32);
        bufp->chgCData(oldp+8,((3U & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_addr)),2);
        bufp->chgCData(oldp+9,((0x00000018U & (vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_addr 
                                               << 3U))),5);
        bufp->chgWData(oldp+10,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__send_string),440);
        bufp->chgBit(oldp+24,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_out));
        bufp->chgIData(oldp+25,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__hold_counter),32);
        bufp->chgSData(oldp+26,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__shift_reg),10);
        bufp->chgIData(oldp+27,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__bit_counter),32);
        bufp->chgIData(oldp+28,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__bit_counter_next),32);
        bufp->chgCData(oldp+29,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__cur_state),2);
        bufp->chgCData(oldp+30,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__next_state),2);
        bufp->chgIData(oldp+31,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_transmitter__DOT__debug_counter),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+32,(vlSelfRef.tb_core__DOT__core__DOT__stall));
        bufp->chgIData(oldp+33,(vlSelfRef.tb_core__DOT__core__DOT__pc_id),32);
        bufp->chgBit(oldp+34,(vlSelfRef.tb_core__DOT__core__DOT__flush_id));
        bufp->chgIData(oldp+35,(vlSelfRef.tb_core__DOT__core__DOT__instr_id),32);
        bufp->chgIData(oldp+36,(vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_id),32);
        bufp->chgCData(oldp+37,((0x0000007fU & vlSelfRef.tb_core__DOT__core__DOT__instr_id)),7);
        bufp->chgCData(oldp+38,((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 7U))),5);
        bufp->chgSData(oldp+39,((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                 >> 0x00000014U)),12);
        bufp->chgCData(oldp+40,((7U & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                       >> 0x0000000cU))),3);
        bufp->chgCData(oldp+41,((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                 >> 0x00000019U)),7);
        bufp->chgCData(oldp+42,((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 0x0000000fU))),5);
        bufp->chgCData(oldp+43,((0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                >> 0x00000014U))),5);
        bufp->chgIData(oldp+44,(vlSelfRef.tb_core__DOT__core__DOT__imm_id),32);
        bufp->chgBit(oldp+45,(vlSelfRef.tb_core__DOT__core__DOT__mem_w_id));
        bufp->chgCData(oldp+46,(vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_id),2);
        bufp->chgBit(oldp+47,(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_id));
        bufp->chgBit(oldp+48,(vlSelfRef.tb_core__DOT__core__DOT__reg_write_id));
        bufp->chgBit(oldp+49,(vlSelfRef.tb_core__DOT__core__DOT__csr_w_en_id));
        bufp->chgBit(oldp+50,(vlSelfRef.tb_core__DOT__core__DOT__csr_r_en_id));
        bufp->chgCData(oldp+51,(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_id),3);
        bufp->chgIData(oldp+52,(vlSelfRef.tb_core__DOT__core__DOT__zimm_id),32);
        bufp->chgIData(oldp+53,(vlSelfRef.tb_core__DOT__core__DOT__csr_content_id),32);
        bufp->chgBit(oldp+54,((0U == (0x0000001fU & 
                                      (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                       >> 7U)))));
        bufp->chgBit(oldp+55,((0U == (0x0000001fU & 
                                      (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                       >> 0x0000000fU)))));
        bufp->chgSData(oldp+56,(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_ex),12);
        bufp->chgIData(oldp+57,(vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex),32);
        bufp->chgCData(oldp+58,(vlSelfRef.tb_core__DOT__core__DOT__opcode_ex),7);
        bufp->chgCData(oldp+59,(vlSelfRef.tb_core__DOT__core__DOT__rd_ex),5);
        bufp->chgCData(oldp+60,(vlSelfRef.tb_core__DOT__core__DOT__funct3_ex),3);
        bufp->chgCData(oldp+61,(vlSelfRef.tb_core__DOT__core__DOT__funct7_ex),7);
        bufp->chgIData(oldp+62,(vlSelfRef.tb_core__DOT__core__DOT__imm_ex),32);
        bufp->chgIData(oldp+63,(vlSelfRef.tb_core__DOT__core__DOT__zimm_ex),32);
        bufp->chgBit(oldp+64,(vlSelfRef.tb_core__DOT__core__DOT__flush_ex));
        bufp->chgIData(oldp+65,(vlSelfRef.tb_core__DOT__core__DOT__pc_ex),32);
        bufp->chgIData(oldp+66,(vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_ex),32);
        bufp->chgBit(oldp+67,(vlSelfRef.tb_core__DOT__core__DOT__mem_w_ex));
        bufp->chgBit(oldp+68,(vlSelfRef.tb_core__DOT__core__DOT__rs2_sel_ex));
        bufp->chgCData(oldp+69,(vlSelfRef.tb_core__DOT__core__DOT__rs1_sel_ex),2);
        bufp->chgBit(oldp+70,(vlSelfRef.tb_core__DOT__core__DOT__reg_write_ex));
        bufp->chgBit(oldp+71,(vlSelfRef.tb_core__DOT__core__DOT__csr_write_ex));
        bufp->chgCData(oldp+72,(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_ex),3);
        bufp->chgCData(oldp+73,(vlSelfRef.tb_core__DOT__core__DOT__alu_op_ex),4);
        bufp->chgIData(oldp+74,(vlSelfRef.tb_core__DOT__core__DOT__rs1_data_ex),32);
        bufp->chgIData(oldp+75,(vlSelfRef.tb_core__DOT__core__DOT__rs2_data_ex),32);
        bufp->chgIData(oldp+76,(vlSelfRef.tb_core__DOT__core__DOT__csr_content_ex),32);
        bufp->chgIData(oldp+77,(vlSelfRef.tb_core__DOT__core__DOT__alu_result_ex),32);
        bufp->chgBit(oldp+78,(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_in_ex));
        bufp->chgBit(oldp+79,(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_out_ex));
        bufp->chgIData(oldp+80,(vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex),32);
        bufp->chgIData(oldp+81,(vlSelfRef.tb_core__DOT__core__DOT__pc_mem),32);
        bufp->chgIData(oldp+82,(vlSelfRef.tb_core__DOT__core__DOT__imm_mem),32);
        bufp->chgIData(oldp+83,(vlSelfRef.tb_core__DOT__core__DOT__rs2_data_mem),32);
        bufp->chgCData(oldp+84,(vlSelfRef.tb_core__DOT__core__DOT__rd_mem),5);
        bufp->chgSData(oldp+85,(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_mem),12);
        bufp->chgBit(oldp+86,(vlSelfRef.tb_core__DOT__core__DOT__mem_w_mem));
        bufp->chgBit(oldp+87,(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_mem));
        bufp->chgCData(oldp+88,(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_mem),3);
        bufp->chgBit(oldp+89,(vlSelfRef.tb_core__DOT__core__DOT__reg_write_mem));
        bufp->chgBit(oldp+90,(vlSelfRef.tb_core__DOT__core__DOT__csr_write_mem));
        bufp->chgIData(oldp+91,(vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem),32);
        bufp->chgCData(oldp+92,(vlSelfRef.tb_core__DOT__core__DOT__opcode_mem),7);
        bufp->chgCData(oldp+93,(vlSelfRef.tb_core__DOT__core__DOT__funct3_mem),3);
        bufp->chgIData(oldp+94,(vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_mem),32);
        bufp->chgIData(oldp+95,(vlSelfRef.tb_core__DOT__core__DOT__csr_content_mem),32);
        bufp->chgIData(oldp+96,(vlSelfRef.tb_core__DOT__core__DOT__csr_data_mem),32);
        bufp->chgIData(oldp+97,(vlSelfRef.tb_core__DOT__core__DOT__bit_mask_mem),32);
        bufp->chgCData(oldp+98,(vlSelfRef.tb_core__DOT__core__DOT__shift_amt_mem),5);
        bufp->chgBit(oldp+99,(vlSelfRef.tb_core__DOT__core__DOT__sign_extend_mem));
        bufp->chgIData(oldp+100,(vlSelfRef.tb_core__DOT__core__DOT__r_data_wb),32);
        bufp->chgIData(oldp+101,(vlSelfRef.tb_core__DOT__core__DOT__pc_wb),32);
        bufp->chgCData(oldp+102,(vlSelfRef.tb_core__DOT__core__DOT__rd_wb),5);
        bufp->chgSData(oldp+103,(vlSelfRef.tb_core__DOT__core__DOT__csr_reg_wb),12);
        bufp->chgIData(oldp+104,(vlSelfRef.tb_core__DOT__core__DOT__csr_data_wb),32);
        bufp->chgIData(oldp+105,(vlSelfRef.tb_core__DOT__core__DOT__imm_wb),32);
        bufp->chgBit(oldp+106,(vlSelfRef.tb_core__DOT__core__DOT__mem_w_wb));
        bufp->chgBit(oldp+107,(vlSelfRef.tb_core__DOT__core__DOT__reg_write_wb));
        bufp->chgBit(oldp+108,(vlSelfRef.tb_core__DOT__core__DOT__csr_write_wb));
        bufp->chgCData(oldp+109,(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb),3);
        bufp->chgIData(oldp+110,(vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb),32);
        bufp->chgBit(oldp+111,(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_wb));
        bufp->chgIData(oldp+112,(vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_wb),32);
        bufp->chgIData(oldp+113,(vlSelfRef.tb_core__DOT__core__DOT__csr_content_wb),32);
        bufp->chgIData(oldp+114,(((4U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                                   ? ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                                       ? vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb
                                       : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                                           ? vlSelfRef.tb_core__DOT__core__DOT__csr_content_wb
                                           : vlSelfRef.tb_core__DOT__core__DOT__pc_plus_4_wb))
                                   : ((2U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                                       ? ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                                           ? vlSelfRef.tb_core__DOT__core__DOT__imm_wb
                                           : vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb)
                                       : ((1U & (IData)(vlSelfRef.tb_core__DOT__core__DOT__wb_sel_wb))
                                           ? vlSelfRef.tb_core__DOT__core__DOT__r_data_wb
                                           : vlSelfRef.tb_core__DOT__core__DOT__alu_result_wb)))),32);
        bufp->chgIData(oldp+115,(vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__add_output),32);
        bufp->chgIData(oldp+116,(vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__sub_output),32);
        bufp->chgIData(oldp+117,((vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
                                  ^ vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex)),32);
        bufp->chgIData(oldp+118,((vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
                                  | vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex)),32);
        bufp->chgIData(oldp+119,((vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex 
                                  & vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex)),32);
        bufp->chgIData(oldp+120,(VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex, 
                                                (0x0000001fU 
                                                 & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))),32);
        bufp->chgIData(oldp+121,(VL_SHIFTL_III(32,32,32, vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex, 
                                               (0x0000001fU 
                                                & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))),32);
        bufp->chgIData(oldp+122,(VL_SHIFTR_III(32,32,32, vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex, 
                                               (0x0000001fU 
                                                & vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex))),32);
        bufp->chgIData(oldp+123,(vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__slt_output),32);
        bufp->chgIData(oldp+124,(vlSelfRef.tb_core__DOT__core__DOT__alu__DOT__sltu_output),32);
        bufp->chgIData(oldp+125,(((~ vlSelfRef.tb_core__DOT__core__DOT__alu_operand_b_ex) 
                                  & vlSelfRef.tb_core__DOT__core__DOT__csr_data_ex)),32);
        bufp->chgBit(oldp+126,((1U & (~ (IData)(vlSelfRef.tb_core__DOT__core__DOT__alu_zero_in_ex)))));
        bufp->chgIData(oldp+127,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__misa),32);
        bufp->chgIData(oldp+128,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mvendorid),32);
        bufp->chgIData(oldp+129,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mimpid),32);
        bufp->chgIData(oldp+130,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__marchid),32);
        bufp->chgIData(oldp+131,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mhartid),32);
        bufp->chgIData(oldp+132,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mie),32);
        bufp->chgIData(oldp+133,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mip),32);
        bufp->chgIData(oldp+134,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mstatus),32);
        bufp->chgIData(oldp+135,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mtvec),32);
        bufp->chgIData(oldp+136,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mepc),32);
        bufp->chgIData(oldp+137,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mcause),32);
        bufp->chgIData(oldp+138,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mscratch),32);
        bufp->chgIData(oldp+139,(vlSelfRef.tb_core__DOT__core__DOT__csr_file__DOT__mtval),32);
        bufp->chgIData(oldp+140,(vlSelfRef.tb_core__DOT__core__DOT__decoder__DOT__imm_I),32);
        bufp->chgIData(oldp+141,((((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                               >> 0x0000001fU))) 
                                   << 0x0000000bU) 
                                  | ((0x000007e0U & 
                                      (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                       >> 0x00000014U)) 
                                     | (0x0000001fU 
                                        & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                           >> 7U))))),32);
        bufp->chgIData(oldp+142,((((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                               >> 0x0000001fU))) 
                                   << 0x0000000cU) 
                                  | ((0x00000800U & 
                                      (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                       << 4U)) | ((0x000007e0U 
                                                   & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001eU 
                                                     & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                        >> 7U)))))),32);
        bufp->chgIData(oldp+143,((0xfffff000U & vlSelfRef.tb_core__DOT__core__DOT__instr_id)),32);
        bufp->chgIData(oldp+144,((((- (IData)((vlSelfRef.tb_core__DOT__core__DOT__instr_id 
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
                                           >> 0x00000014U))))),32);
        bufp->chgCData(oldp+145,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_ex),5);
        bufp->chgCData(oldp+146,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_mem),5);
        bufp->chgBit(oldp+147,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_ex));
        bufp->chgBit(oldp+148,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_mem));
        bufp->chgCData(oldp+149,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rd_wb),5);
        bufp->chgBit(oldp+150,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__rw_wb));
        bufp->chgSData(oldp+151,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_ex),12);
        bufp->chgSData(oldp+152,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_mem),12);
        bufp->chgBit(oldp+153,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_ex));
        bufp->chgBit(oldp+154,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_mem));
        bufp->chgSData(oldp+155,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_wb),12);
        bufp->chgBit(oldp+156,(vlSelfRef.tb_core__DOT__core__DOT__hazard_unit__DOT__csr_write_wb));
        bufp->chgIData(oldp+157,(VL_SHIFTR_III(32,32,32, 
                                               (vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem 
                                                - (IData)(0x00004000U)), 2U)),32);
        bufp->chgIData(oldp+158,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__shifted_mask),32);
        bufp->chgCData(oldp+159,((3U & vlSelfRef.tb_core__DOT__core__DOT__alu_result_mem)),2);
        bufp->chgBit(oldp+160,(vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__debug_jump));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgIData(oldp+161,(vlSelfRef.tb_core__DOT__core__DOT__pc_next),32);
        bufp->chgIData(oldp+162,(vlSelfRef.tb_core__DOT__core__DOT__rs1_data_id),32);
        bufp->chgIData(oldp+163,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw),32);
        bufp->chgIData(oldp+164,(vlSelfRef.tb_core__DOT__core__DOT__pc_controller__DOT__jalr_target_raw),32);
    }
    bufp->chgBit(oldp+165,(vlSelfRef.tb_core__DOT__clk));
    bufp->chgBit(oldp+166,(vlSelfRef.tb_core__DOT__rst_n));
    bufp->chgIData(oldp+167,(vlSelfRef.tb_core__DOT__y),32);
    bufp->chgIData(oldp+168,(vlSelfRef.tb_core__DOT__core__DOT__pc_if),32);
    bufp->chgIData(oldp+169,(((IData)(4U) + vlSelfRef.tb_core__DOT__core__DOT__pc_if)),32);
    bufp->chgIData(oldp+170,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__mem
                             [(0x0003ffffU & ((vlSelfRef.tb_core__DOT__core__DOT__pc_if 
                                               - (IData)(0x00004000U)) 
                                              >> 2U))]),32);
    bufp->chgBit(oldp+171,(vlSelfRef.tb_core__DOT__core__DOT__imem_en));
    bufp->chgIData(oldp+172,((vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs
                              [(0x0000001fU & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                               >> 0x00000014U))] 
                              & (- (IData)((0U != (0x0000001fU 
                                                   & (vlSelfRef.tb_core__DOT__core__DOT__instr_id 
                                                      >> 0x00000014U))))))),32);
    bufp->chgIData(oldp+173,(((IData)(vlSelfRef.tb_core__DOT__core__DOT__sign_extend_mem)
                               ? ((0x00008000U & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__shifted_mask)
                                   ? VL_EXTENDS_II(32,16, 
                                                   (0x0000ffffU 
                                                    & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw))
                                   : ((0x00000080U 
                                       & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__shifted_mask)
                                       ? VL_EXTENDS_II(32,8, 
                                                       (0x000000ffU 
                                                        & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw))
                                       : vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw))
                               : vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__dram_r_data_raw)),32);
    bufp->chgBit(oldp+174,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__write_toggle));
    bufp->chgBit(oldp+175,(vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__rst));
    bufp->chgIData(oldp+176,(((0x000000ffU & vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__mem
                               [(0x0003ffffU & ((vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_addr 
                                                 - (IData)(0x00004000U)) 
                                                >> 2U))]) 
                              >> (0x00000018U & (vlSelfRef.tb_core__DOT__core__DOT__main_mem__DOT__uart_addr 
                                                 << 3U)))),32);
    Vtb_core___024root__trace_chg_dtype____0(vlSelf, bufp, 177, vlSelfRef.tb_core__DOT__core__DOT__regfile__DOT__regs);
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
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
