// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_REGFILE__SYMS_H_
#define VERILATED_VTB_REGFILE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_regfile.h"

// INCLUDE MODULE CLASSES
#include "Vtb_regfile___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtb_regfile__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_regfile* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_regfile___024root          TOP;

    // CONSTRUCTORS
    Vtb_regfile__Syms(VerilatedContext* contextp, const char* namep, Vtb_regfile* modelp);
    ~Vtb_regfile__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
