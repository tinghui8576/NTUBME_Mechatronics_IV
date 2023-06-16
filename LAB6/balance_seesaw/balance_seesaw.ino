#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include <Servo.h>
MPU6050 accelgyro(0x68);
Servo servo;
int16_t ax, ay, az;
int16_t gx, gy, gz;
double ax_offset, ay_offset, az_offset, gx_offset , gy_offset, gz_offset;
const double accel_factor = 4096, gyro_factor = 32.8;
double Pitch_angle, Roll_angle, Pitch_accel, Roll_accel, Yaw_angle;
const double RAD_TO_DAG = 180.0 / 3.14159265359;
long lastime;
double previous = 90;
long previousTime;
void setup() {
  Serial.begin(115200);
  Wire.begin();
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();
  servo.attach(12);
  servo.write(90);
  Serial.println("Testing device connections...");
  previousTime = millis();
}
double errorI = 0;
void loop() {
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  long nowTime = millis();
  double Time = (nowTime - previousTime) / 1000.0;
  previousTime = nowTime;
  double errorP = map(ay, -17000, 17000, -10, 10);
  errorI += ay * Time;
  double totalError = errorP + errorI * 0.000001;
  previous = previous + totalError;
  if (previous > 180) {
    previous = 180;
  }
  else if (previous < 0) {
    previous = 0;
  }
  servo.write(previous);
  SensorFusion();
  // Function SensorFusion();
  Serial.print("Yaw = ");
  Serial.print(Yaw_angle);
  Serial.print(", ");
  Serial.print("Pitch = ");
  Serial.print(Pitch_angle);
  Serial.print(", ");
  Serial.print("Roll = ");
  Serial.println(Roll_angle);
  delay(50);
}
void SensorFusion()// Calculate angle(yaw, pitch, roll)
{ double accx = ax - ax_offset, accy = ay - ay_offset, accz = az - az_offset ;
  int g_total = accx * accx + accy * accy + accz * accz;
  /* Exceeding 4096*4096*2 = 2G means that the accelerometer is inaccurate and its reading value is not displayed*/
  if (abs(g_total) < 33554432) {
    Pitch_accel = atan2(accx, sqrt(accy * accy + accz * accz)) * RAD_TO_DAG; Roll_accel = atan2(accy, accz) * RAD_TO_DAG;
  }
  // Calculate the angle without filter
  double dt = (millis() - lastime) / 1000.0;
  lastime = millis();
  Pitch_angle += (-(gy - gy_offset) / gyro_factor) * dt;
  Roll_angle += ((gx - gx_offset) / gyro_factor) * dt;
  Yaw_angle += (-(gz - gz_offset) / gyro_factor) * dt;
  // Calculate the angle with the Complimentary filter
  Pitch_angle = 0.9 * Pitch_angle + 0.1 * Pitch_accel;
  Roll_angle = 0.9 * Roll_angle + 0.1 * Roll_accel;
}
