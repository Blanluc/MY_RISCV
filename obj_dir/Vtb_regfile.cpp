// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_regfile__pch.h"

//============================================================
// Constructors

Vtb_regfile::Vtb_regfile(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_regfile__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_regfile::Vtb_regfile(const char* _vcname__)
    : Vtb_regfile(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_regfile::~Vtb_regfile() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_regfile___024root___eval_debug_assertions(Vtb_regfile___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_regfile___024root___eval_static(Vtb_regfile___024root* vlSelf);
void Vtb_regfile___024root___eval_initial(Vtb_regfile___024root* vlSelf);
void Vtb_regfile___024root___eval_settle(Vtb_regfile___024root* vlSelf);
void Vtb_regfile___024root___eval(Vtb_regfile___024root* vlSelf);

void Vtb_regfile::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_regfile::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_regfile___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_regfile___024root___eval_static(&(vlSymsp->TOP));
        Vtb_regfile___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_regfile___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_regfile___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_regfile::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_regfile::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_regfile::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_regfile___024root___eval_final(Vtb_regfile___024root* vlSelf);

VL_ATTR_COLD void Vtb_regfile::final() {
    contextp()->executingFinal(true);
    Vtb_regfile___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_regfile::hierName() const { return vlSymsp->name(); }
const char* Vtb_regfile::modelName() const { return "Vtb_regfile"; }
unsigned Vtb_regfile::threads() const { return 1; }
void Vtb_regfile::prepareClone() const { contextp()->prepareClone(); }
void Vtb_regfile::atClone() const {
    contextp()->threadPoolpOnClone();
}
