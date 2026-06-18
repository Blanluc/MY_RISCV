// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_fetch__pch.h"

//============================================================
// Constructors

Vtb_fetch::Vtb_fetch(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_fetch__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_fetch::Vtb_fetch(const char* _vcname__)
    : Vtb_fetch(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_fetch::~Vtb_fetch() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_fetch___024root___eval_debug_assertions(Vtb_fetch___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_fetch___024root___eval_static(Vtb_fetch___024root* vlSelf);
void Vtb_fetch___024root___eval_initial(Vtb_fetch___024root* vlSelf);
void Vtb_fetch___024root___eval_settle(Vtb_fetch___024root* vlSelf);
void Vtb_fetch___024root___eval(Vtb_fetch___024root* vlSelf);

void Vtb_fetch::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_fetch::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_fetch___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_fetch___024root___eval_static(&(vlSymsp->TOP));
        Vtb_fetch___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_fetch___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_fetch___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_fetch::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_fetch::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_fetch::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_fetch___024root___eval_final(Vtb_fetch___024root* vlSelf);

VL_ATTR_COLD void Vtb_fetch::final() {
    contextp()->executingFinal(true);
    Vtb_fetch___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_fetch::hierName() const { return vlSymsp->name(); }
const char* Vtb_fetch::modelName() const { return "Vtb_fetch"; }
unsigned Vtb_fetch::threads() const { return 1; }
void Vtb_fetch::prepareClone() const { contextp()->prepareClone(); }
void Vtb_fetch::atClone() const {
    contextp()->threadPoolpOnClone();
}
