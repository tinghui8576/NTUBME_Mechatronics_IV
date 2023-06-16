//#include "Wire.h"
//#include "LiquidCrystal_I2C.h"
//// Set LCD I2C communication
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
//
//void setup() {
//  // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光
//  lcd.begin(16, 2);
//
//  // 閃爍三次
//  for (int i = 0; i < 3; i++) {
//    lcd.backlight(); // 開啟背光
//    delay(250);
//    lcd.noBacklight(); // 關閉背光
//    delay(250);
//  }
//  lcd.backlight();
//
//  // 輸出初始化文字
//  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
//  lcd.print("ICshop&MakerPRO");
//  delay(1000);
//  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
//  lcd.print("Hello, Maker!");
//  delay(8000);
//  lcd.clear(); //顯示清除
//}
//void loop() {
//  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
//  lcd.print("ICshop&MakerPRO");
//  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
//  lcd.print(millis() / 1000);
//}
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();

  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Arduino");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("GetStarted.com"); // print message at (2, 1)
}

void loop()
{
}
