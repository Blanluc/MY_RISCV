// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_ALU__SYMS_H_
#define VERILATED_VTB_ALU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_alu.h"

// INCLUDE MODULE CLASSES
#include "Vtb_alu___024root.h"
#include "Vtb_alu___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtb_alu__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_alu* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_alu___024root              TOP;

    // CONSTRUCTORS
    Vtb_alu__Syms(VerilatedContext* contextp, const char* namep, Vtb_alu* modelp);
    ~Vtb_alu__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
