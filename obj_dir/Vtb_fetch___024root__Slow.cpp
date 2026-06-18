// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fetch.h for the primary calling header

#include "Vtb_fetch__pch.h"

void Vtb_fetch___024root___ctor_var_reset(Vtb_fetch___024root* vlSelf);

Vtb_fetch___024root::Vtb_fetch___024root(Vtb_fetch__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_fetch___024root___ctor_var_reset(this);
}

void Vtb_fetch___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_fetch___024root::~Vtb_fetch___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
