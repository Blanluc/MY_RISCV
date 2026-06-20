// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_alu.h for the primary calling header

#ifndef VERILATED_VTB_ALU___024UNIT_H_
#define VERILATED_VTB_ALU___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_alu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_alu___024unit final {
  public:

    // INTERNAL VARIABLES
    Vtb_alu__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_alu___024unit();
    ~Vtb_alu___024unit();
    void ctor(Vtb_alu__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtb_alu___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
