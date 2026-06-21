// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_decoder__pch.h"

//============================================================
// Constructors

Vtb_decoder::Vtb_decoder(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_decoder__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_decoder::Vtb_decoder(const char* _vcname__)
    : Vtb_decoder(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_decoder::~Vtb_decoder() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_decoder___024root___eval_debug_assertions(Vtb_decoder___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_decoder___024root___eval_static(Vtb_decoder___024root* vlSelf);
void Vtb_decoder___024root___eval_initial(Vtb_decoder___024root* vlSelf);
void Vtb_decoder___024root___eval_settle(Vtb_decoder___024root* vlSelf);
void Vtb_decoder___024root___eval(Vtb_decoder___024root* vlSelf);

void Vtb_decoder::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_decoder::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_decoder___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_decoder___024root___eval_static(&(vlSymsp->TOP));
        Vtb_decoder___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_decoder___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_decoder___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_decoder::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_decoder::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_decoder::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_decoder___024root___eval_final(Vtb_decoder___024root* vlSelf);

VL_ATTR_COLD void Vtb_decoder::final() {
    contextp()->executingFinal(true);
    Vtb_decoder___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_decoder::hierName() const { return vlSymsp->name(); }
const char* Vtb_decoder::modelName() const { return "Vtb_decoder"; }
unsigned Vtb_decoder::threads() const { return 1; }
void Vtb_decoder::prepareClone() const { contextp()->prepareClone(); }
void Vtb_decoder::atClone() const {
    contextp()->threadPoolpOnClone();
}
