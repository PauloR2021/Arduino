#include <Servo.h>
#define SERVO 6

Servo s
int pos


void setup() {
  pinMode(7, OUTPUT);
  s.attach(Servo);
  Serial.begin(9600);
  s.write(0);

}

void loop() {
  for(pos = 0; pos <180; pos++){
    s.write(pos);
    pinMode(7, HIGH);
    delay(4);
    }
    delay(2000);
  for(pos=180; pos >0; pos--){
    s.write(pos);
    piMode(7, LOW);
    delay(4);
    }
    delay(2000);
}
