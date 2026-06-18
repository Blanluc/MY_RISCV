// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_FETCH__SYMS_H_
#define VERILATED_VTB_FETCH__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_fetch.h"

// INCLUDE MODULE CLASSES
#include "Vtb_fetch___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtb_fetch__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_fetch* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_fetch___024root            TOP;

    // CONSTRUCTORS
    Vtb_fetch__Syms(VerilatedContext* contextp, const char* namep, Vtb_fetch* modelp);
    ~Vtb_fetch__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
