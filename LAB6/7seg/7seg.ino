#include "Wire.h"
#include "LiquidCrystal_I2C.h"
const int A = 3; // Set 7-Seg pins
const int B = 4;
const int C = 5;
const int D = 6;
const int E = 7;
const int F = 9;
const int G = 8;
bool Bpress = false; // Set button1 signal as false
int UpPin = 10; // Set Button1(UpPin) pin
int CheckPin = 11; // Set Button2(CheckPin) pin
int num = 0; // Set variable int as initial value
int ButtonUp = 0;
int LastButtonUp = 0;
int ButtonCheck = 0;
int LastButtonCheck = 0;
// Set LCD I2C communication
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  Serial.begin(115200);
  Serial.println("Initializing I2C devices...");
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(UpPin, INPUT_PULLUP);
  pinMode(CheckPin, INPUT_PULLUP);


}
void loop()
{
  // Set ButtonUp
  ButtonUp = digitalRead(UpPin);
  // Set ButtonCheck
  ButtonCheck = digitalRead(CheckPin);
  Serial.print("ButtonUp:");
  Serial.println(ButtonUp);
  Serial.print("ButtonCheck:");
  Serial.println(ButtonCheck);
  Serial.print("NUM");
  Serial.println(num);
  delay(250);

  if (ButtonUp != LastButtonUp)
  {
    LastButtonUp = ButtonUp;
    if (ButtonUp == LOW) // If ButtonUp is Low
    {
      Bpress = true; // Set button1 signal as true
      num++; //Total number of button press
      if (num >= 3) // If total number >= 3
      {
        num = 0;
      }
      ChangeNum(num); // Function ChangeNum()
      delay(50);
    }
  }
  if (ButtonCheck == HIGH) // If ButtonCheck is High
  { // If confirmed, the specified name and value will be displayed
    if (num == 0) // If num=0，then LCD displays yaw
    {
      lcd.noBacklight(); // 關閉背光
      delay(250);
    }
    if (num == 1) // If num=1，then LCD displays pitch
    {
      lcd.backlight();
      delay(250);
    }
    if (num == 2) // If num=2，the LCD displays roll
    {
      lcd.backlight();
      delay(250);
      lcd.noBacklight(); // 關閉背光
      delay(250);
    }
  }
}
void ChangeNum(int button1) // Function ChangeNum()
{
  switch (button1)
  {
    case 0: // If button 1=0，7-Seg. Shows 0
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);

      break;
    case 1: // If button 1=1，7-Seg. Shows 1
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);

      break;
    case 2: // 當button 1=2，7-Seg. Shows 2
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);

      break;
  }
}
