#ifndef MAGX_FSM_H
#define MAGX_FSM_H

/*
* Author : Alex Gabriel Malisa
* Email  : alexgabrielmalisa@gmail.com
*/

#include <Arduino.h>

// Forward declaration of StateMachine class
class StateMachine;

// Base state class
class State {
protected:
    const char* stateName;

public:
    State(const char* name);
    virtual void handleState(StateMachine& fsm) = 0;
    virtual ~State(); // Making the base class destructor virtual
};

// Concrete state class with custom state logic
template<typename Func>
class ConcreteState : public State {
private:
    Func stateLogic; // Function pointer for custom state logic

public:
    ConcreteState(const char* name, Func logic);

    // Implement handleState method using custom state logic
    void handleState(StateMachine& fsm) override;
};

// StateMachine class
class StateMachine {
private:
    State* currentState; // Pointer to the current state
    String currentStateName;

public:
    StateMachine();

    // Factory method to create instances of concrete state classes with custom state logic
    template<typename Func>
    void setStateWithLogic(const char* stateName, Func stateLogic);

    String getCurrentStateName() const;

    void run();
    void waitUntilElapsed(unsigned long duration, void (*callback)(StateMachine &), StateMachine &fsm);
};

#endif // MAGX_FSM_H
