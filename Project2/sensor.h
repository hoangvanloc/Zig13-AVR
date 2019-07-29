#ifndef _SENSOR_H_
#define _SENSOR_H_
#include <stdint.h>
#include <avr/io.h>
#define SENSOR_NUMBER 13
#define bit_is_clear(sfr,bit) (!(_SFR_BYTE(sfr) & _BV(bit)))
#define bit_is_set(sfr,bit)   (_SFR_BYTE(sfr) & _BV(bit))
#define SENSOR1_IN 6
#define SENSOR2_IN 5
#define SENSOR3_IN 4
#define SENSOR4_IN 3
#define SENSOR5_IN 2
#define SENSOR6_IN 1
#define SENSOR7_IN 0
#define SENSOR8_IN 6
#define SENSOR9_IN 5
#define SENSOR10_IN 4
#define SENSOR11_IN 2
#define SENSOR12_IN 3
#define SENSOR13_IN 1
#define SENSOR1_PORT_IN PINB
#define SENSOR2_PORT_IN PINB
#define SENSOR3_PORT_IN PINB
#define SENSOR4_PORT_IN PINB
#define SENSOR5_PORT_IN PINB
#define SENSOR6_PORT_IN PINB
#define SENSOR7_PORT_IN PINB
#define SENSOR8_PORT_IN PINH
#define SENSOR9_PORT_IN PINH
#define SENSOR10_PORT_IN PINH
#define SENSOR11_PORT_IN PINH
#define SENSOR12_PORT_IN PINH
#define SENSOR13_PORT_IN PINH
uint8_t count = 0;
uint8_t Read_Sensor(uint8_t *data_out);
#endif