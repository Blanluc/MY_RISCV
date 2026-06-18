// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fetch.h for the primary calling header

#include "Vtb_fetch__pch.h"

void Vtb_fetch___024unit___ctor_var_reset(Vtb_fetch___024unit* vlSelf);

Vtb_fetch___024unit::Vtb_fetch___024unit() = default;
Vtb_fetch___024unit::~Vtb_fetch___024unit() = default;

void Vtb_fetch___024unit::ctor(Vtb_fetch__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtb_fetch___024unit___ctor_var_reset(this);
}

void Vtb_fetch___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtb_fetch___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
