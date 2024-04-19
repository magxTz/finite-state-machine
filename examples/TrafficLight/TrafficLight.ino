#include <magx_fsm.h>

// Define pin numbers for LEDs
const int RED_PIN = 13;
const int GREEN_PIN = 12;
const int YELLOW_PIN = 11;

// Define durations for each state in milliseconds
const int RED_DURATION = 7000;   // 7 seconds
const int GREEN_DURATION = 5000; // 5 seconds
const int YELLOW_DURATION = 3000; // 3 seconds



// Function pointers for state logic
void redStateLogic(StateMachine &fsm);
void greenStateLogic(StateMachine &fsm);
void yellowStateLogic(StateMachine &fsm);

// State transition functions
void greenStateCallback(StateMachine &fsm) {
  fsm.setStateWithLogic("GREEN_STATE", greenStateLogic);
}
void yellowStateCallback(StateMachine &fsm) {
  fsm.setStateWithLogic("YELLOW_STATE", yellowStateLogic);
}
void redStateCallback(StateMachine &fsm) {
  fsm.setStateWithLogic("RED_STATE", redStateLogic);
}


void redStateLogic(StateMachine &fsm) {
  // Set red light ON, green and yellow OFF
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  fsm.waitUntilElapsed(RED_DURATION, greenStateCallback, fsm);
}

void greenStateLogic(StateMachine &fsm) {
  // Set green light ON, red and yellow OFF
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);

  // Wait in this state for some time
  fsm.waitUntilElapsed(GREEN_DURATION, yellowStateCallback, fsm);
}

void yellowStateLogic(StateMachine &fsm) {
  // Set yellow light ON, red and green OFF
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);

  // Wait in this state for some time
  fsm.waitUntilElapsed(YELLOW_DURATION, redStateCallback, fsm);
}

StateMachine fsm;

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);

  // Start with RedState
  fsm.setStateWithLogic("RED_STATE", redStateLogic);
}

void loop() {

  fsm.run(); // Start traffic light operation
}
