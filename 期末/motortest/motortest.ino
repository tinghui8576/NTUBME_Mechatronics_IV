
//first mote
const int pwm1 = 3 ; //pwm
const int M1_1 = 2 ; //pin
const int M1_2 = 4 ; 

//second moter (RF)
const int pwm2 = 5 ; //pwm
const int M2_1 = 7 ; //pin
const int M2_2 = 8 ; 

void setup() {
  pinMode(pwm1,OUTPUT) ; //set motor1 PWM pin & Logic pins as output 
  pinMode(M1_1,OUTPUT) ; 
  pinMode(M1_2,OUTPUT) ;

  pinMode(pwm2,OUTPUT) ; //set motor2 PWM pin & Logic pins as output 
  pinMode(M2_1,OUTPUT) ; 
  pinMode(M2_2,OUTPUT) ;
}

void loop() {
  digitalWrite(M1_1, HIGH); 
  digitalWrite(M1_2, LOW);
  analogWrite(pwm1, 255);

  digitalWrite(M2_1, HIGH); 
  digitalWrite(M2_2, LOW); 
  //set speed to v out of 0-255
  analogWrite(pwm2, 255);
}

void Forward(int v){
  m1c(v);
  m2c(v);
  
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
