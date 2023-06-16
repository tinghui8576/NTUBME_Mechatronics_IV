#include <SoftwareSerial.h>
//bluetooth pin code
SoftwareSerial MyBlue(8, 9); // RX | TX
//the char bluetooth read
String val;
void setup() {
  //set bluetooth to get signal
  Serial.begin(9600);
  Serial.println("BT is ready!");
  MyBlue.begin(9600);
}

void loop() {
  
  if (MyBlue.available()) {
    Serial.write(MyBlue.read());
  }
  if (Serial.available()) {
    MyBlue.write(Serial.read());
  }
  /*
  if (Serial.available()) {
    val = Serial.read();
    MyBlue.print(val);
  }
 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (MyBlue.available()) {
    val = MyBlue.read();
    Serial.print(val);
  }
  */
}
