// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_CORE__SYMS_H_
#define VERILATED_VTB_CORE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_core.h"

// INCLUDE MODULE CLASSES
#include "Vtb_core___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtb_core__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_core* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_core___024root             TOP;

    // CONSTRUCTORS
    Vtb_core__Syms(VerilatedContext* contextp, const char* namep, Vtb_core* modelp);
    ~Vtb_core__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
