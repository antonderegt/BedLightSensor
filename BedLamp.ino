/*
* Demo for RF remote switch receiver. 
* This example is for the new KaKu / Home Easy type of remotes!

* For details, see NewRemoteReceiver.h!
*
* This sketch shows the received signals on the serial port.
* Connect the receiver to digital pin 2.
*/

#include <NewRemoteReceiver.h>
const int relay = 7;
const int data = 2;

void setup() {
  Serial.begin(115200);
  
  // Initialize receiver on interrupt 0 (= digital pin 2), calls the callback "showCode"
  // after 2 identical codes have been received in a row. (thus, keep the button pressed
  // for a moment)
  //
  // See the interrupt-parameter of attachInterrupt for possible values (and pins)
  // to connect the receiver.
  NewRemoteReceiver::init(0, data, showCode);
  pinMode(relay, OUTPUT);
}

void loop() {
}

// Callback function is called only when a valid code is received.
void showCode(NewRemoteCode receivedCode) {
  // Note: interrupts are disabled. You can re-enable them if needed.
  if (receivedCode.address == 15986790 and receivedCode.unit == 0 and receivedCode.switchType == 0){
    //pin low
    digitalWrite(relay, HIGH);
  } else if (receivedCode.address == 15986790 and receivedCode.unit == 0 and receivedCode.switchType == 1){
    // pin high
    digitalWrite(relay, LOW);
  }
  
}


