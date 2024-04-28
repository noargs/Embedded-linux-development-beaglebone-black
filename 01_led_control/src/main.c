/*
 ============================================================================
 Name        : 01_led_control.c
 Author      : Ibn <asim.ibn.asghar@gmail.com>
 Version     : 1.0
 Copyright   : 
 Description : Controls the BBB user LED 3 trigger and brightness values
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int write_brightness_values(uint8_t led_no, int value);
int write_trigger_values(uint8_t led_no, char* value);
void process_brightness_values(int value);
void process_trigger_values(char* value);

/* This is the path corresonds to USER LEDs in the 'sys' directory */
#define SYS_FS_LEDS_PATH "/sys/class/leds"

/* this is the path corresponds to USER LED in the 'sys' directory */
//#define SYS_FS_ "/sys/class/leds/beaglebone:green:usr3"

#define USER_LED_NUMBER     3
#define SOME_BYTES               100

/*
 * argv[0] = Application name
 * argv[1] = control_option
 * argv[2] = value
 */

int main(int argc, char* argv[])
{
  printf("This application controls the USER LED3\n");

  if (argc != 3) /* argc should be 3 for correct execution */
  {
	printf("usage: %s <control_option> <value>\n", argv[0]);
	printf("valid control_options: brightness, trigger\n");
	printf("valid 'brightness' values: 0,1\n");
	printf("valid 'trigger' values: heartbeat, timer, none, oneshot, default-on\n");
  }
  else
  {
	/* argc is valid, lets check argv */
	if (strcmp(argv[1], "trigger") == 0)
	{
	  process_trigger_values(argv[2]);
	}
	else if (strcmp(argv[1], "brightness") == 0 )
	{
	  /* converting argv[2] which is a brightness value in to integer */
	  int value = atoi(argv[2]);
//	  printf("value received %d", value);
	  process_brightness_values(value);
	}
	else
	{
	  printf("Invalid control option \n");
	  printf("valid control_options: brightness, trigger\n");
	}
  }
  return 0;
}

/* compare and process the trigger values given by the user */
void process_trigger_values(char* value)
{
  if (!(strcmp(value, "timer") && strcmp(value, "heartbeat") && \
	  strcmp(value, "none") && strcmp(value, "oneshot") && \
	  strcmp(value, "default-on")))
  {
	write_trigger_values(USER_LED_NUMBER, value);
  }
  else  /* default: */
  {
	printf("Invalid value\n");
	printf("valid trigger values: heartbeat, timer, none, oneshot, default-on");
  }
}

/* process the brightness values given by the user */
void process_brightness_values(int value)
{
  switch(value)
  {
  case 0:
  case 1:
	write_brightness_values(USER_LED_NUMBER, value);
	break;
//  case 1:
//	write_brightness_values(USER_LED_NUMBER, value);
//	break;
  default:
	printf("Invalid value\n");
	printf("Valid brightness values: 0, 1\n");
  }
}

/*
 * writes the `trigger` values for the given 'led_no'
 * return 0 on success, else -1
 */
int write_trigger_values(uint8_t led_no, char* value)
{
  int fd, ret = 0;
  char buf[SOME_BYTES];

  /* concatenate 2 strings and storing that into 'buf' */
  snprintf(buf, sizeof(buf), SYS_FS_LEDS_PATH "/beaglebone:green:usr%d/trigger", led_no);

  /* open the file in write mode */
  /*
   * returns the file descriptor for the new file. the file descriptor returned is always the smallest integer
   * greater than zero that
   */
  fd = open(buf, O_WRONLY);
  if (fd <= 0)
  {
	perror("write trigger error\n");
	return -1;
  }

  /* write the 'value' in to the file designated by 'fd' */
  /*
   * Returns the number of bytes that were written
   * if value is negative, then the system call returned an error
   */
  ret = write(fd, (void*)value, strlen(value));
  if (ret <= 0)
  {
	printf("trigger value write error\n");
	return -1;
  }
  return 0;
}

/*
 * function writes the brightness values from the given `led_no`
 * returns 0 if success, else -1
 */
int write_brightness_values(uint8_t led_no, int value)
{
  int fd, ret = 0;
  char buf[SOME_BYTES];

  /* we are concating 2 strings and storing that in to `buf` */
  snprintf(buf, sizeof(buf), SYS_FS_LEDS_PATH "/beaglebone:green:usr%d/brightness", led_no);

  /* open the file in write mode */
  /*
   * returns the file descriptor for the new file. The file descriptor returned is always the smallest integer greater than
   * zero that is still available, if a
   */
  fd = open(buf, O_WRONLY);
  if (fd < 0)
  {
	perror(" write trigger error \n");
	return -1;
  }

  /* write the 'value' in to the file designated by 'fd' */
  /*
   * return the number of bytes that were written
   * if value is negative, then the system call returned an error
   *
   * https://stackoverflow.com/questions/58259818/how-to-write-integers-with-write-function-in-c
   */
//  ret = write(fd, (void*)&value, sizeof(value));
  char buffer[2];
  sprintf(buffer, "%d", value);
  ret = write (fd, (void*)buffer, sizeof(buffer));

  if (ret <= 0)
  {
	printf("trigger value write error\n");
	return -1;
  }
  return 0;
}
