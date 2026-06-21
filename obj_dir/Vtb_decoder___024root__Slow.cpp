// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_decoder.h for the primary calling header

#include "Vtb_decoder__pch.h"

void Vtb_decoder___024root___ctor_var_reset(Vtb_decoder___024root* vlSelf);

Vtb_decoder___024root::Vtb_decoder___024root(Vtb_decoder__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_decoder___024root___ctor_var_reset(this);
}

void Vtb_decoder___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_decoder___024root::~Vtb_decoder___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
