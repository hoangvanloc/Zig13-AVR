/*
 * Project.c
 *
       START               RUN          OK    or   ERROR   
 OK      0                  1           0            1
 S_Err   1                  1           1            0
 J_Not   0 or 1             1           1            0
 
 * Created: 4/14/2019 2:48:46 PM
 * Author : ABCD
 */ 
#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/delay.h>
#include <stdbool.h>
#include <avr/wdt.h>
#include <string.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "main.h"
#include "sensor.c"
#include "led_driver.c"
#define ON  1
#define OFF 0
#define F_CPU 16000000UL
#define USE_TEST 1

#define SPEAKER_OFF            clr_bit(SPEAKER_PORT_OUT,SPEAKER_PIN)
#define SPEAKER_ON             set_bit(SPEAKER_PORT_OUT,SPEAKER_PIN)
#define SPEAKER_TOGLE          SPEAKER_PORT_OUT ^=(1<< SPEAKER_PIN)
#define PRESSURE_ERROR         bit_is_set(PRESSURE_ERROR_PORT_IN,PRESSURE_ERROR_PIN)
#define VALVE_ON               set_bit(VALVE_PORT_OUT,VALVE_PIN)
#define VALVE_OFF              clr_bit(VALVE_PORT_OUT,VALVE_PIN)           
#define ENABLE_SCREW           clr_bit(SCREW_CONTROL_PORT,SCREW_CONTROL_PIN)
#define DISABLE_SCREW          set_bit(SCREW_CONTROL_PORT,SCREW_CONTROL_PIN)
//#define SCREW_FREE             bit_is_set(SCREW_DONE_PORT_IN,SCREW_DONE_PIN)
#define SCREW_RUN              bit_is_set(SCREW_OK_PORT_IN,SCREW_OK_PIN)
#define SCREW_OK               bit_is_clear(SCREW_OK_PORT_IN,SCREW_OK_PIN)
#define SCREW_NOT_COM          bit_is_clear(SCREW_NOT_COMPLETE_PORT_IN,SCREW_NOT_COMPLETE_PIN)
#define SCREW_ERROR            bit_is_clear(SCREW_ERROR_PORT_IN,SCREW_ERROR_PIN)
#define NEXT_LED               bit_is_clear(BUTTON_NEXT_PORT_IN,BUTTON_NEXT_PIN)
volatile uint8_t EEMEM train_data_eeprom[SENSOR_NUMBER] = {9,2,11,13,7,4,10,1,8,3,12,6,5};  
 uint8_t  temp_data[SENSOR_NUMBER]; 	
 uint8_t train_data[SENSOR_NUMBER];
 uint8_t sensor_data[SENSOR_NUMBER];
uint8_t step = 0;
uint8_t read_test = 0;

void Start(void);
uint8_t Trainning_Process(uint8_t *data_out);
void check_pressure(void);
void BipBip(void);

void Trainning_Update_Data(volatile uint8_t *data_update)
{
	uint8_t i;
	for (i = 0; i<SENSOR_NUMBER;i++)
	{
		eeprom_write_byte(i,data_update[i]);
		_delay_ms(10);
	}
}
void Trainning_Data_Read(volatile uint8_t *data_read)
{
	uint8_t i;
	for(i = 0;i<SENSOR_NUMBER;i++)
	{
		_delay_ms(10);
		data_read[i] = eeprom_read_byte(i);
	}
}
/*
void  soft_reset()   
{
	do
	{
		wdt_enable(WDTO_15MS);
		for(;;)
		{
		}
	} while(0);
}    
*/
void Reset_Button()
{
	uint8_t count = 0;
	for(uint8_t i = 0; i < 20; i++)
	{
		if(bit_is_clear(RESET_PORT_IN,RESET_PIN)) count++;
		_delay_ms(1);
	}
	if (count > 19) soft_reset();
}

uint8_t Check_Data(uint8_t *data)
{
	uint8_t num = 0;
	for (uint8_t i = 0; i < SENSOR_NUMBER; i++)
	{
		if(data[i] > 0) num++;
	}
	return num;
}

uint8_t Trainning_Process(uint8_t *data_out)
{
	uint8_t number = 0;
	while(number < SENSOR_NUMBER)
	{
		_delay_ms(1);
		Read_Sensor(data_out);
		Turn_LED_Input(data_out,GREEN);
		Turn_LED_Input_Off(data_out,RED);
		number = Check_Data(data_out);
	}
	return 1;
}

//Wait to train in 20s
uint8_t Entry_Trainning(void)
{
	uint16_t time_count = 0;
	uint8_t data_train_temp[SENSOR_NUMBER];
	while(time_count < 10000 && bit_is_set(NAP_OPEN_PORT_IN,NAP_OPEN_PIN))
	{
		Turn_All_LED_Off(RED);
		for(uint8_t  i = 0; i <SENSOR_NUMBER;i++) data_train_temp[i] = 0;
		if(Read_Sensor(data_train_temp))
		{
			Turn_LED_Input(data_train_temp,RED);
			if(Check_Data(data_train_temp) == 2) return 1;
		}
		time_count ++;
		_delay_ms(1);
	}
	return 0;
}
void Program_Start(void)
{
	for(uint8_t i=0 ; i< SENSOR_NUMBER; i++) sensor_data[i] = 0;
	
	if (Entry_Trainning())
	{
		Turn_All_LED_On(RED);
		_delay_ms(2000);
		count = 0;
		if(Trainning_Process(sensor_data))
		{
			Turn_All_Led_On_Delay(sensor_data,RED);
			Trainning_Update_Data(sensor_data); //Save data to EPPROM
		}
	}
	Trainning_Data_Read(train_data);  //Read data from EPPROM
	Turn_All_LED_Off(RED);
	Turn_All_LED_Off(GREEN);
}

void BipBip(void)
{
	SPEAKER_ON;
	_delay_us(1);
	SPEAKER_OFF;
	_delay_us(5);
}
int main(void)
{
	DDRA &=~ (1<<NAP_OPEN_PIN);
	//PORTA |= (1<<NAP_OPEN_PIN);
	DDRC &=~(1<<PRESSURE_ERROR_PIN);  //PINC3 I34
	DDRC &=~ (1<<BUTTON_NEXT_PIN);	
	//DDRL &=~ (1<<SCREW_DONE_PIN);
	DDRL &=~ (1<<SCREW_OK_PIN);       //PINL1 //I48 OK
	DDRL &=~ (1<<SCREW_NOT_COMPLETE_PIN); // PINL0 //I49 Join Not complete
	DDRC &=~ (1<<SCREW_ERROR_PIN);        //PINC0 //I37
	DDRL |= (1<<SCREW_CONTROL_PIN); 
	//DDRG |= (1<<SPEAKER_PIN);	    //Speaker	I41 PG0
	DDRL |= (1<<SPEAKER_PIN);       //Speaker	O44 PL5
	DDRD |= (1<<VALVE_PIN);
	DDRD &=~ (1<<XI_LANH_PIN);


    Led_Init();
	
    SPEAKER_OFF;
	ENABLE_SCREW;
	for(uint8_t i=0 ; i< SENSOR_NUMBER; i++) sensor_data[i] = 0;
	Turn_All_LED_Off(RED);
	Turn_All_LED_Off(GREEN);
	check_pressure();
	/*if (Entry_Trainning())
	{
		Turn_All_LED_On(RED);
		_delay_ms(2000);
		count = 0;
		if(Trainning_Process(sensor_data))
		{
			Turn_All_Led_On_Delay(sensor_data,RED);
			Trainning_Update_Data(sensor_data); //Save data to EPPROM
		}
	}*/
	Trainning_Data_Read(train_data);  //Read data from EPPROM
	Turn_All_LED_Off(RED);
	Turn_All_LED_Off(GREEN);
	check_pressure();
	while (1)
	{
	  check_pressure();
	  Start();
	}
}
void Run_Normal(void)
{
    uint16_t has_sensor_count = 0;
	uint16_t right_sensor_count = 0;
	step = 0;
	//Turn on Current LED data
	Turn_LED_On(train_data[step],RED);
	while(step < SENSOR_NUMBER )
	{
		check_pressure();
		//Change LED to Next Hole
		if(NEXT_LED)
		{
			Turn_LED_Off(train_data[step],RED);
			Turn_LED_On(train_data[step],GREEN);
			step++;
			_delay_ms(200);
			while(NEXT_LED){};
		}
		ENABLE_SCREW;
		if(Read_Current_Sensor() != 0)
		{
			if(Read_Current_Sensor() == train_data[step]) //right hole
			{
				uint8_t Next_Hole = 0;
				uint8_t count = 0;
				uint8_t screw_is_run = 0;
				ENABLE_SCREW;
				while(1)
				{
					if(SCREW_RUN) screw_is_run = 1; //Check if SCREW is run?
					if(SCREW_ERROR)                //If run error
					{
						BipBip();
						count = 0;                 //Reset count
					}else
					{
						SPEAKER_OFF;
						if(SCREW_OK && screw_is_run)
						{
							count++;  //If SCREW_OK and Not Any error
						}
					}
					if(count > 50) 
					{
						count = 0;
						Next_Hole = 1;
						break;
					}
					if(SCREW_NOT_COM ) count = 0; 
					if(Read_Current_Sensor() == 0) break;  
				}
				if(Next_Hole == 1)
				{
					Next_Hole = 0;
					Turn_LED_Off(train_data[step],RED);
					Turn_LED_On(train_data[step],GREEN);
					step++;
					Turn_LED_On(train_data[step],RED);
				}
				while(Read_Current_Sensor()){};
			}else //Wrong hole
			{
				BipBip();
				DISABLE_SCREW;
			}
		}
	}
	_delay_ms(300);
	Turn_All_LED_Off(RED);
	Turn_All_LED_Off(GREEN);
	VALVE_OFF;
}
void check_pressure(void)
{
	while(PRESSURE_ERROR)
	{
		BipBip();
	}
	SPEAKER_OFF;
}
void Start(void)
{
	uint16_t time_out = 0;
	while(bit_is_set(NAP_OPEN_PORT_IN,NAP_OPEN_PIN))    //Cho nap mo
	{
		check_pressure();
		_delay_ms(1);
	}
	_delay_ms(500);
	check_pressure();
	while(bit_is_clear(NAP_OPEN_PORT_IN,NAP_OPEN_PIN)) //Cho nap dong
	{
		check_pressure();
		_delay_ms(1);
	}
	_delay_ms(200);
	VALVE_ON;
	time_out = 1000;
	while(bit_is_set(XI_LANH_PORT_IN,XI_LANH_PIN) && time_out > 0)
	{
		time_out--;
		_delay_ms(1);
		check_pressure();
	}
	check_pressure();
	if(time_out < 1) //If Xilanh not run
	{
		BipBip();
		VALVE_OFF;
		while(1){};
	}else
	{
		Run_Normal();
	}
}
