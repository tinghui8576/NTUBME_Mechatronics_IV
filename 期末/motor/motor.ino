#include <SoftwareSerial.h>
//bluetooth pin code
SoftwareSerial MyBlue(2, 3); // RX | TX
//the char bluetooth read
char blget;

//first moter (LF)
const int pwm1 = 3 ; //pwm
const int M1_1 = 2 ; //pin
const int M1_2 = 4 ; 

//second moter (RF)
const int pwm2 = 5 ; //pwm
const int M2_1 = 7 ; //pin
const int M2_2 = 8 ; 

//third moter (LB)
const int pwm3 = 6 ; //pwm
const int M3_1 = 9 ; //pin
const int M3_2 = 10 ;

//forth moter (RB)
const int pwm4 = 11 ; //pwm
const int M4_1 = 12 ; //pin
const int M4_2 = 13 ;

void setup() {
  //set bluetooth to get signal
  MyBlue.begin(9600);
  
  pinMode(pwm1,OUTPUT) ; //set motor1 PWM pin & Logic pins as output 
  pinMode(M1_1,OUTPUT) ; 
  pinMode(M1_2,OUTPUT) ;

  pinMode(pwm2,OUTPUT) ; //set motor2 PWM pin & Logic pins as output 
  pinMode(M2_1,OUTPUT) ; 
  pinMode(M2_2,OUTPUT) ;
  
  pinMode(pwm3,OUTPUT) ; //set motor1 PWM pin & Logic pins as output 
  pinMode(M3_1,OUTPUT) ; 
  pinMode(M3_2,OUTPUT) ;

  pinMode(pwm4,OUTPUT) ; //set motor2 PWM pin & Logic pins as output 
  pinMode(M4_1,OUTPUT) ; 
  pinMode(M4_2,OUTPUT) ;
}

void loop() {
  if (MyBlue.available()) 
    blget = MyBlue.read(); 
  if (blget == 'F') { 
    Forward(220);
  } 
  else if (blget == 'B') { 
    Backward(220);
  } 
  else if (blget == 'B') { 
    Left(220);
  } 
  else if (blget == 'B') { 
    Right(220);
  } 
  else { 
    Stop();
  } 
}

void Forward(int v){
  m1c(v);
  m2c(v);
  m3c(v);
  m4c(v);
}
void Backward(int v){
  m1cc(v);
  m2cc(v);
  m3cc(v);
  m4cc(v);
}
void Left(int v){
  m1cc(v);
  m2c(v);
  m3c(v);
  m4c(v);
}
void Right(int v){
  m1c(v);
  m2cc(v);
  m3c(v);
  m4c(v);
}
void Stop(){
  digitalWrite(M1_1, LOW); 
  digitalWrite(M1_2, LOW); 
  digitalWrite(M2_1, LOW); 
  digitalWrite(M2_2, LOW);
  digitalWrite(M3_1, LOW); 
  digitalWrite(M3_2, LOW);
  digitalWrite(M4_1, LOW); 
  digitalWrite(M4_2, LOW);
}
// For the first motor to move clockwise/counter clockwise
void m1c(int v){
  digitalWrite(M1_1, HIGH); 
  digitalWrite(M1_2, LOW); 
  //set speed to v out of 0-255
  analogWrite(pwm1, v);
}
void m1cc(int v){
  digitalWrite(M1_1, LOW); 
  digitalWrite(M1_2, HIGH);
  //set speed to v out of 0-255
  analogWrite(pwm1, v);
}

// For the second motor to move clockwise/counter clockwise
void m2c(int v){
  digitalWrite(M2_1, HIGH); 
  digitalWrite(M2_2, LOW); 
  //set speed to v out of 0-255
  analogWrite(pwm2, v);
}
void m2cc(int v){
  digitalWrite(M2_1, LOW); 
  digitalWrite(M2_2, HIGH);
  //set speed to v out of 0-255
  analogWrite(pwm2, v);
}

// For the third motor to move clockwise/counter clockwise
void m3c(int v){
  digitalWrite(M3_1, HIGH); 
  digitalWrite(M3_2, LOW); 
  //set speed to v out of 0-255
  analogWrite(pwm3, v);
}
void m3cc(int v){
  digitalWrite(M3_1, LOW); 
  digitalWrite(M3_2, HIGH);
  //set speed to v out of 0-255
  analogWrite(pwm3, v);
}

// For the forth motor to move clockwise/counter clockwise
void m4c(int v){
  digitalWrite(M4_1, HIGH); 
  digitalWrite(M4_2, LOW); 
  //set speed to v out of 0-255
  analogWrite(pwm4, v);
}
void m4cc(int v){
  digitalWrite(M4_1, LOW); 
  digitalWrite(M4_2, HIGH);
  //set speed to v out of 0-255
  analogWrite(pwm4, v);
}
