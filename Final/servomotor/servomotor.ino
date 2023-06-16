#include <Servo.h>
Servo myservo;
void setup() { 
  myservo.attach(10); //伺服馬達的訊號線接Pin9
} 
void loop() {
  for(int i = 0; i <= 180; i=i+1){
    myservo.write(i);
    delay(10);
  }
  for(int i = 180; i >= 0; i=i-1){
    myservo.write(i);
    delay(10);
  }
}
