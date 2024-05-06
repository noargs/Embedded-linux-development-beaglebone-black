#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

/* mpu6050 resgiter addresses */
#define MPU6050_REG_POWER             0x6B
#define MPU6050_REG_ACCEL_CONFIG      0x1C
#define MPU6050_REG_GYRO_CONFIG       0x1B

/*
 * addresses of mpu6050 from which you will fetch accelerometer, x, y, z high and low value
 * [mpu-6000 Register map page: 29], each register 8-bit wide, hence 16 bit value divided into
 * high, low registers
 */
#define MPU6050_REG_GYRO_X_HIGH       0x43
#define MPU6050_REG_GYRO_X_LOW        0x44
#define MPU6050_REG_GYRO_Y_HIGH       0x45
#define MPU6050_REG_GYRO_Y_LOW        0x46
#define MPU6050_REG_GYRO_Z_HIGH       0x47
#define MPU6050_REG_GYRO_Z_LOW        0x48

/*
 * different Full-Scale Ranges for Accelerometer and Gyroscope
 * refer to the table 6.2 and 6.3 in the document mpu6000 and mpu6050
 * [Product Specification Revision 3.4]
 */
#define ACC_FS_SENSITIVITY_0          16384
#define ACC_FS_SENSITIVITY_1          8192
#define ACC_FS_SENSITIVITY_2          4096
#define ACC_FS_SENSITIVITY_3          2048

#define GYR_FS_SENSITIVITY_0          131
#define GYR_FS_SENSITIVITY_1          65.5
#define GYR_FS_SENSITIVITY_2          32.8
#define GYR_FS_SENSITIVITY_3          16.4

/* I2C slave address of mpu6050 sensor */
#define MPU6050_SLAVE_ADDR            0x68

#define MAX_VALUE                     50

/* linux OS device file for the I2C2 controller of the SOC */
#define I2C_DEVICE_FILE               "/dev/i2c-2"

int fd;

