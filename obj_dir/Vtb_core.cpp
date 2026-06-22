// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_core__pch.h"

//============================================================
// Constructors

Vtb_core::Vtb_core(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_core__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_core::Vtb_core(const char* _vcname__)
    : Vtb_core(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_core::~Vtb_core() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_core___024root___eval_debug_assertions(Vtb_core___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_core___024root___eval_static(Vtb_core___024root* vlSelf);
void Vtb_core___024root___eval_initial(Vtb_core___024root* vlSelf);
void Vtb_core___024root___eval_settle(Vtb_core___024root* vlSelf);
void Vtb_core___024root___eval(Vtb_core___024root* vlSelf);

void Vtb_core::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_core::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_core___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_core___024root___eval_static(&(vlSymsp->TOP));
        Vtb_core___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_core___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_core___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_core::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_core::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_core::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_core___024root___eval_final(Vtb_core___024root* vlSelf);

VL_ATTR_COLD void Vtb_core::final() {
    contextp()->executingFinal(true);
    Vtb_core___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_core::hierName() const { return vlSymsp->name(); }
const char* Vtb_core::modelName() const { return "Vtb_core"; }
unsigned Vtb_core::threads() const { return 1; }
void Vtb_core::prepareClone() const { contextp()->prepareClone(); }
void Vtb_core::atClone() const {
    contextp()->threadPoolpOnClone();
}
