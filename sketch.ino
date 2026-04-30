#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup() {
  // Initialize serial communication at 115200 baud
  Serial.begin(115200);
  while (!Serial) delay(10); 

  // Initialize MPU6050 sensor
  if (!mpu.begin()) {
    while (1) yield();
  }
}

void loop() {
  sensors_event_t a, g, temp;
  
  // Read sensor data
  mpu.getEvent(&a, &g, &temp);

  // Format output as CSV for data collection (Accel X, Y, Z)
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.println(a.acceleration.z);

  // Maintain 50Hz sampling rate
  delay(20); 
}
