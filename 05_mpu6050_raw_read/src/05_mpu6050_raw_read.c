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

void mpu6050_init(void);
void mpu6050_read_accelerometer(short int* buffer);
void mpu6050_read_gyroscope(short* buffer);
int mpu6050_write(uint8_t base_addr, uint8_t data);
int mpu6050_read(uint8_t base_addr, char* buffer, uint32_t len);

/* mpu6050 resgiter addresses */
#define MPU6050_REG_POWER             0x6B
#define MPU6050_REG_ACCEL_CONFIG      0x1C
#define MPU6050_REG_GYRO_CONFIG       0x1B                // [4.4 Register 27 - Gyroscope Configuration page: 14]

/*
 * addresses of mpu6050 from which you will fetch accelerometer, x, y, z high and low value
 * [mpu-6000 Register map page: 29], each register 8-bit wide, hence 16 bit value divided into
 * high, low registers
 */
#define MPU6050_REG_ACC_X_HIGH        0x3B
#define MPU6050_REG_ACC_X_LOW         0x3C
#define MPU6050_REG_ACC_Y_HIGH        0x3D
#define MPU6050_REG_ACC_Y_LOW         0x3E
#define MPU6050_REG_ACC_Z_HIGH        0x3F
#define MPU6050_REG_ACC_Z_LOW         0x40

/* addresses of mpu6050 from which you will fetch x, y, z high and low values */
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

int main(void)
{
  short acc_value[3], gyro_value[3];
  double accx, accy, accz, gyrox, gyroy, gyroz;

  /* first open the I2C device file */
  if ((fd = open(I2C_DEVICE_FILE, O_RDWR)) < 0)
  {
	perror("Failed to set I2C slave address.\n");
	close(fd);
	return -1;
  }

  /* set I2C slave address using `ioctl`'s I2C_SLAVE command */
  if (ioctl(fd, I2C_SLAVE, MPU6050_SLAVE_ADDR) < 0)
  {
	perror("Failed to set I2C slave address.\n");
	close(fd);
	return -1;
  }

  mpu6050_init();

  while (1)
  {
	mpu6050_read_accelerometer(acc_value);
	mpu6050_read_gyroscope(gyro_value);

	/* convert Accelerometer values into 'g' values */
	accx = acc_value[0]/ACC_FS_SENSITIVITY_3;
	accy = acc_value[1]/ACC_FS_SENSITIVITY_3;
	accz = acc_value[2]/ACC_FS_SENSITIVITY_3;

	/* convert Gyroscope raw values into '/s' (degree/seconds) */
	gyrox = gyro_value[0]/GYR_FS_SENSITIVITY_3;
	gyroy = gyro_value[1]/GYR_FS_SENSITIVITY_3;
	gyroz = gyro_value[2]/GYR_FS_SENSITIVITY_3;

	/* print the raw values read */
	printf("Accelerometer(raw) => X:%d Y:%d Z:%d Gyroscope(raw) => X:%d Y:%d Z:%d \n", \
		acc_value[0], acc_value[1], acc_value[2], gyro_value[0], \
		gyro_value[1], gyro_value[2]);

	/* print the 'g' and '/s' values */
	printf("Accelerometer(g) => X:%d Y:%d Z:%d Gyroscope(g) => X:%d Y:%d Z:%d \n", \
			accx, accy, accz, gyrox, \
			gyroy, gyroz);

	/* wait for 250000 microseconds, thats 250ms before going for another round */
	usleep(250*1000);
  }
}


/*
 * by default mpu6050 will be in sleep mode, so disable its sleep mode
 * and also configure the Full-Scale ranges for gyro and acc
 */
void mpu6050_init(void)
{
  // 1. disable sleep mode
  mpu6050_write(MPU6050_REG_POWER, 0x00);
  usleep(500);

  // adjust Full-Scale values for Gryoscope and Accelerometer
  mpu6050_write(MPU6050_REG_ACCEL_CONFIG, 0x18);
  usleep(500);
  mpu6050_write(MPU6050_REG_GYRO_CONFIG, 0x18);             // Maximum Full-Scale range FS_SEL=3 +/- 2000 degree/sec; 3 => 0xb11 => 0001 1000 => 0x18
  usleep(500);
}

/* read accelerometer values of x, y, z into the buffer */
void mpu6050_read_accelerometer(short int* buffer)
{
  // each axis value is of 16-bit (2bytes), hence we need a buffer of 6 bytes
  char acc_buffer[6];

  // start reading from the base address of accelerometer values i.e. MPU6050_REG_ACC_X_HIGH
  mpu6050_read(MPU6050_REG_ACC_X_HIGH, acc_buffer, 6);

  buffer[0] = (int) ((acc_buffer[0] << 8) | acc_buffer[1]); // acc x-axis value
  buffer[1] = (int) ((acc_buffer[2] << 8) | acc_buffer[3]); // acc y-axis value
  buffer[2] = (int) ((acc_buffer[4] << 8) | acc_buffer[5]); // acc z-axis value
}

void mpu6050_read_gyroscope(short* buffer)
{
  char gyro_buffer[6];

  // start reading from the base address of gyro values, i.e. MPU6050_REG_GYRO_X_HIGH
  mpu6050_read(MPU6050_REG_GYRO_X_HIGH, gyro_buffer, 6);

  buffer[0] = ((gyro_buffer[0] << 8) + gyro_buffer[1]);     // gyro x-axis value
  buffer[1] = ((gyro_buffer[2] << 8) + gyro_buffer[3]);     // gyro y-axis value
  buffer[2] = ((gyro_buffer[4] << 8) + gyro_buffer[5]);     // gyro z-axis value
}

/* write a 8-bit 'data' to the sensor at the address indicated by 'addr' */
int mpu6050_write(uint8_t base_addr, uint8_t data)
{
  int ret;
  char buf[2];
  buf[0] = base_addr;
  buf[1] = data;
  ret = write(fd, buf, 2);

  if (ret <= 0)
  {
	perror("write failed\n");
	return -1;
  }
  return 0;
}

/* read 'len' many bytes from 'addr' of the sensor into the address indicated by 'buffer' */
int mpu6050_read(uint8_t base_addr, char* buffer, uint32_t len)
{
  int ret;
  char buf[2];
  buf[0] = base_addr;
  ret = write(fd, buf, 1);

  if (ret <= 0)
  {
	perror("write address failed\n");
	return -1;
  }

  ret = read(fd, buffer, len);
  if (ret <= 0)
  {
	perror("read failed\n");
	return -1;
  }
  return 0;
}








































