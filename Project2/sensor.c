#include "sensor.h"
#include "led_driver.h"

uint8_t check_repeat(uint8_t data_new, uint8_t *data_old)
{
	for(uint8_t i = 0; i< SENSOR_NUMBER;i++) if(data_old[i] == data_new)  return 0;
	return 1;
}

uint8_t Read_Sensor(uint8_t data_out[13])
{
	uint8_t sensor = 0;
	uint8_t sen_num = 0;
	if(bit_is_set(SENSOR1_PORT_IN,SENSOR1_IN))
	{
		sensor = 1;
		sen_num = 1;
		if(check_repeat(sen_num,data_out))
		{
			 data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
	}
	if(bit_is_set(SENSOR2_PORT_IN,SENSOR2_IN))
	{
		sen_num = 2;
		if(check_repeat(sen_num,data_out))
		{
			 data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;

	}
	if(bit_is_set(SENSOR3_PORT_IN,SENSOR3_IN))
	{
		sen_num = 3;
		if(check_repeat(sen_num,data_out)) 
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;

	}
	if(bit_is_clear(SENSOR4_PORT_IN,SENSOR4_IN))
	{
		sen_num = 4;
		if(check_repeat(sen_num,data_out)) 
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;
	}
	if(bit_is_set(SENSOR5_PORT_IN,SENSOR5_IN))
	{
		sen_num = 5;
		if(check_repeat(sen_num,data_out)) 
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;
	}

	if(bit_is_set(SENSOR6_PORT_IN,SENSOR6_IN))
	{	
		sen_num = 6; 
		if(check_repeat(sen_num,data_out)) 
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;
	}
	if(bit_is_set(SENSOR7_PORT_IN,SENSOR7_IN))
	{
		sen_num = 7;
		if(check_repeat(sen_num,data_out)) 
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;
	}
	if(bit_is_set(SENSOR8_PORT_IN,SENSOR8_IN))
	{
		sen_num = 8;
		
		if(check_repeat(sen_num,data_out))
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++; else count = 0;
		}
		sensor = 1;

	}
	if(bit_is_set(SENSOR9_PORT_IN,SENSOR9_IN))
	{
		sen_num = 9;
		if(check_repeat(sen_num,data_out))
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;
	}
	if(bit_is_set(SENSOR10_PORT_IN,SENSOR10_IN))
	{
		sen_num = 10;
		if(check_repeat(sen_num,data_out))
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		
		sensor = 1;
		while(bit_is_set(SENSOR10_PORT_IN,SENSOR10_IN));
	}
	if(bit_is_set(SENSOR11_PORT_IN,SENSOR11_IN))
	{
		sen_num = 11;
		if(check_repeat(sen_num,data_out))
		{
			data_out[count] = sen_num;
			if(count< SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;
		while(bit_is_set(SENSOR11_PORT_IN,SENSOR11_IN));
	}

	if(bit_is_set(SENSOR12_PORT_IN,SENSOR12_IN))
	{
		sen_num = 12;
		if(check_repeat(sen_num,data_out))
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;
		while(bit_is_set(SENSOR12_PORT_IN,SENSOR12_IN));
	}
	if(bit_is_set(SENSOR13_PORT_IN,SENSOR13_IN))
	{
		sen_num = 13;
		if(check_repeat(sen_num,data_out))
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;
		while(bit_is_set(SENSOR13_PORT_IN,SENSOR13_IN));
	}
	return sensor;
}
uint8_t Read_Current_Sensor(void)
{
	uint8_t sen = 0;

	if(bit_is_set(SENSOR1_PORT_IN,SENSOR1_IN)) sen = 1;
	if(bit_is_set(SENSOR2_PORT_IN,SENSOR2_IN)) sen = 2;
	if(bit_is_set(SENSOR3_PORT_IN,SENSOR3_IN)) sen = 3;
	if(bit_is_clear(SENSOR4_PORT_IN,SENSOR4_IN)) sen = 4;
	if(bit_is_set(SENSOR5_PORT_IN,SENSOR5_IN)) sen = 5;
	if(bit_is_set(SENSOR6_PORT_IN,SENSOR6_IN)) sen = 6;
	if(bit_is_set(SENSOR7_PORT_IN,SENSOR7_IN)) sen = 7;
	if(bit_is_set(SENSOR8_PORT_IN,SENSOR8_IN)) sen = 8;
	if(bit_is_set(SENSOR9_PORT_IN,SENSOR9_IN)) sen = 9;
	if(bit_is_set(SENSOR10_PORT_IN,SENSOR10_IN)) sen = 10;
	if(bit_is_set(SENSOR11_PORT_IN,SENSOR11_IN)) sen = 11;
	if(bit_is_set(SENSOR12_PORT_IN,SENSOR12_IN)) sen = 12;
	if(bit_is_set(SENSOR13_PORT_IN,SENSOR13_IN)) sen = 13;
  return sen;
}
void reset_sen_num(void)
{
	count = 0;
}
