#include "magx_fsm.h"

template void StateMachine::setStateWithLogic(const char* stateName, void (*)(StateMachine&));
// Base state class
State::State(const char* name) : stateName(name) {}

State::~State() {}

// Concrete state class with custom state logic
template<typename Func>
ConcreteState<Func>::ConcreteState(const char* name, Func logic) : State(name), stateLogic(logic) {}

template<typename Func>
void ConcreteState<Func>::handleState(StateMachine& fsm) {
    stateLogic(fsm);
}

// StateMachine class
StateMachine::StateMachine() : currentState(nullptr), currentStateName("") {}

// Factory method to create instances of concrete state classes with custom state logic
template<typename Func>
void StateMachine::setStateWithLogic(const char* stateName, Func stateLogic) {
    if (currentState)
        delete currentState; // Free the previous state
    currentStateName = stateName;
    currentState = new ConcreteState<Func>(stateName, stateLogic);
}

String StateMachine::getCurrentStateName() const {
    return currentStateName;
}

void StateMachine::run() {
    static unsigned long lastRunTime = 0;
    const unsigned long runInterval = 100; // Adjust the interval as needed

    if (millis() - lastRunTime >= runInterval) {
        lastRunTime = millis();

        if (currentState)
            currentState->handleState(*this); // Handle the current state
    }
}

void StateMachine::waitUntilElapsed(unsigned long duration, void (*callback)(StateMachine &), StateMachine &fsm) {
    static unsigned long previousMillis = 0; // Static variable to maintain state across function calls
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= duration) {
        // If the duration has elapsed, call the callback function
        callback(fsm);
        // Reset the timer for the next duration
        previousMillis = currentMillis;
    }
}
