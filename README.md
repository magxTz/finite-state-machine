# **MagX Finite State Machine (FSM) Library**

### Introduction
MAGX_FSM is a lightweight and versatile Finite State Machine library designed for Arduino and ESP32 platforms. It provides an intuitive way to manage complex control flows by dividing them into discrete states and transitions. With MAGX_FSM, developers can streamline their code, enhance readability, and facilitate maintainability.

### Features
- **Modular Design**: MAGX_FSM implements a modular design, allowing developers to define custom states and logic tailored to their application requirements.
  
- **Flexible State Handling**: The library offers a flexible mechanism for defining state transitions and executing custom logic associated with each state.

- **Minimal Resource Consumption**: MAGX_FSM is designed to minimize resource consumption, making it suitable for resource-constrained environments like Arduino and ESP32 platforms.

- **Reduced Compile Time Dependency**: By using forward declaration and template classes, MAGX_FSM reduces compile time dependencies and breaks circular dependencies, resulting in faster compilation times.

### Limitation (Under Development)
- **Sequential State Transitions**: Currently, MAGX_FSM initiates state transitions based on the current state. This limitation can affect scenarios where a user wants to suspend a specific task/state, as all subsequent states will not execute. However, ongoing development aims to address this limitation by introducing more flexible transition mechanisms.

### How to Use
1. **Include the Library**: Include the `magx_fsm.h` header file in your Arduino or ESP32 sketch.

2. **Define States and Logic**: Define custom states by extending the `State` class and implementing the `handleState` method. Optionally, create concrete state classes with custom state logic using the `ConcreteState` template class.

3. **Instantiate StateMachine**: Instantiate a `StateMachine` object in your sketch.

4. **Set Initial State**: Set the initial state of the StateMachine using the `setStateWithLogic` method, providing the state name and corresponding state logic.

5. **Run the StateMachine**: Call the `run` method within the main loop of your sketch to execute the current state's logic.

6. **Handle State Transitions**: Implement state transitions and associated logic within the state handling methods.

### Example
```cpp
#include "magx_fsm.h"

// Define custom state logic
void stateA_logic(StateMachine &fsm) {
    // Custom logic for State A
}

void stateB_logic(StateMachine &fsm) {
    // Custom logic for State B
}

void setup() {
    // Instantiate StateMachine
    StateMachine fsm;

    // Set initial state and logic
    fsm.setStateWithLogic("StateA", stateA_logic);

    // Additional setup code
}

void loop() {
    // Run StateMachine
    fsm.run();

    // Additional loop code
}
```

### Importance
- **Code Organization**: MAGX_FSM promotes a structured approach to code organization by encapsulating state logic within discrete state objects.
  
- **Enhanced Readability**: By abstracting state transitions and logic, MagX FSM enhances code readability, making it easier to understand and maintain.

- **Scalability**: MAGX_FSM facilitates the scalability of Arduino and ESP32 projects by providing a scalable mechanism for managing increasingly complex control flows.

- **Resource Optimization**: With minimal resource overhead, MAGX_FSM allows developers to maximize the efficiency of their code, ensuring optimal performance on resource-constrained platforms.

### Conclusion
MAGX_FSM offers a powerful yet lightweight solution for managing control flows in Arduino and ESP32 projects. By leveraging the library's modular design and flexible state handling capabilities, developers can simplify code complexity, improve code organization, and enhance overall project maintainability.
