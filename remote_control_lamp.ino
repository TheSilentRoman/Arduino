#include <IRremote.h>

int active = 0;
int relayPin = 3;
int RECV = 11;
int LED = 12;
IRrecv irrecv(RECV);
decode_results results; 


void setup(){
  
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LED,OUTPUT);
  pinMode(relayPin,OUTPUT);
}
void loop() {
  if(irrecv.decode(&results)) {
    Serial.println(results.value,HEX);
    if(active == 0){
    delay(100);
    digitalWrite (relayPin,HIGH);
    active = 1;
    } else {
      delay(100);
      digitalWrite (relayPin,LOW);
      active = 0;
    }
    irrecv.resume();
  }
}
