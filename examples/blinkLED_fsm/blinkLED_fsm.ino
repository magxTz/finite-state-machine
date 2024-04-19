#include <magx_fsm.h>

//blink LED_BUILTIN by using magx_fsm library

//define state prototypes
void led_off_state(StateMachine &fsm);
void led_on_state(StateMachine &fsm);

 
//define state transition callback for on_state
void on_state_callback(StateMachine &fsm){
  fsm.setStateWithLogic("ON_STATE",led_on_state);
}

//define state transition callbacks for off_state
void off_state_callback(StateMachine &fsm){
  fsm.setStateWithLogic("OFF_STATE",led_off_state);
}


// Define states, in the context of this example, there are two states
// ON state and OFF state
void led_off_state(StateMachine &fsm){
  digitalWrite(LED_BUILTIN,LOW);
  uint32_t OFF_DURATION =1000;
  fsm.waitUntilElapsed(OFF_DURATION, on_state_callback, fsm);
}
void led_on_state(StateMachine &fsm){
  digitalWrite(LED_BUILTIN,HIGH);
  uint32_t ON_DURATION =1000;
  fsm.waitUntilElapsed(ON_DURATION, off_state_callback, fsm);
}


StateMachine fsm;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  fsm.setStateWithLogic("ON_STATE", led_on_state);
}

void loop() {
  // put your main code here, to run repeatedly:
  fsm.run();

}