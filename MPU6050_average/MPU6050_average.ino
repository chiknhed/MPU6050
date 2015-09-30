#include <Wire.h>
#include <MPU6050.h>

void setup() {
  Serial.begin(9600);
 
  mpu6050.begin();
}

void loop() {
  unsigned long start_time, finish_time;
  
  while (1) {
    start_time = millis();
    mpu6050.ReadAvrRegisters(10);
    
    Serial.print(F("GetGyroX"));
    Serial.print(mpu6050.GetGyroX(), DEC);

    Serial.print(F("\nGetGyroY"));
    Serial.print(mpu6050.GetGyroY(), DEC);

    Serial.print(F("\nGetGyroZ"));
    Serial.print(mpu6050.GetGyroZ(), DEC);

    Serial.print(F("\nGetAccelX"));
    Serial.print(mpu6050.GetAccelX(), DEC);

    Serial.print(F("\nGetAccelY"));
    Serial.print(mpu6050.GetAccelY(), DEC);

    Serial.print(F("\nGetAccelZ"));
    Serial.print(mpu6050.GetAccelZ(), DEC);
    Serial.println("");
    
    finish_time = millis();

    Serial.println(finish_time - start_time);

    Serial.print(F("\n\n"));

    delay(1000);
  }
}

