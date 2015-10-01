#ifndef _MPU6050_H
#define _MPU6050_H

#include <Wire.h>

// Declaring an union for the registers and the axis values.
// The byte order does not match the byte order of 
// the compiler and AVR chip.
// The AVR chip (on the Arduino board) has the Low Byte 
// at the lower address.
// But the MPU-6050 has a different order: High Byte at
// lower address, so that has to be corrected.
// The register part "reg" is only used internally, 
// and are swapped in code.
union accel_t_gyro_union
{
  struct
  {
    uint8_t x_accel_h;
    uint8_t x_accel_l;
    uint8_t y_accel_h;
    uint8_t y_accel_l;
    uint8_t z_accel_h;
    uint8_t z_accel_l;
    uint8_t t_h;
    uint8_t t_l;
    uint8_t x_gyro_h;
    uint8_t x_gyro_l;
    uint8_t y_gyro_h;
    uint8_t y_gyro_l;
    uint8_t z_gyro_h;
    uint8_t z_gyro_l;
  } reg;
  struct 
  {
    int16_t x_accel;
    int16_t y_accel;
    int16_t z_accel;
    int16_t temperature;
    int16_t x_gyro;
    int16_t y_gyro;
    int16_t z_gyro;
  } value;
};

class Mpu6050Class {
	public:
		Mpu6050Class();
		void begin(void);
		void ReadRegisters(void);
		void ReadAvrRegisters(int count);
		int GetGyroX(void);
		int GetGyroY(void);
		int GetGyroZ(void);
		int GetAccelX(void);
		int GetAccelY(void);
		int GetAccelZ(void);
		
	private:
		int MPU6050_read(int start, uint8_t *buffer, int size);
		int MPU6050_write(int start, const uint8_t *pData, int size);
		int MPU6050_write_reg(int reg, uint8_t data);
		accel_t_gyro_union accel_t_gyro;
		unsigned char m_avrCount;
		double m_totalGyroX;
		double m_totalGyroY;
		double m_totalGyroZ;
		double m_totalAccelX;
		double m_totalAccelY;
		double m_totalAccelZ;
};

extern Mpu6050Class mpu6050;

#endif
