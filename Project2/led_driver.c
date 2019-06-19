#include "led_driver.h"

#define bit_is_clear(sfr,bit) (!(_SFR_BYTE(sfr) & _BV(bit)))
#define bit_is_set(sfr,bit)   (_SFR_BYTE(sfr) & _BV(bit))
void Led_Init(void)
{
	DDRH |= (1<<LED1_G);
	DDRE |= (1<<LED1_R)|(1<<LED2_G)|(1<<LED2_R);
	DDRG |= (1<<LED3_G);
	DDRF |= (1<<LED3_R)|(1<<LED4_G)|(1<<LED4_R)|(1<<LED5_G)|(1<<LED5_R)|(1<<LED6_G)|(LED6_R)|(1<<LED7_G);
	DDRK |= (1<<LED7_R)|(1<<LED8_G)|(1<<LED8_R)|(1<<LED9_G)|(1<<LED9_R)|(1<<LED10_G)|(1<<LED10_R)|(1<<LED11_G);
	DDRA |= (1<<LED11_R)|(1<<LED12_G)|(1<<LED12_R)|(1<<LED13_G)|(1<<LED13_R);
}
void Turn_LED_Off(uint8_t LED_num,uint8_t LED_color)
{
	if(LED_num == 1)
	{
		if(LED_color == RED) clr_bit(LED1_PORT_R,LED1_R); else	clr_bit(LED1_PORT_G,LED1_G);
	}
	if(LED_num ==2)
	{
		if(LED_color == RED) clr_bit(LED2_PORT_R,LED2_R); else clr_bit(LED2_PORT_G,LED2_G);
	}
	if(LED_num == 3)
	{
		if(LED_color == RED)clr_bit(LED3_PORT_R,LED3_R);else clr_bit(LED3_PORT_G,LED3_G);
	}
	if(LED_num == 4)
	{
		if(LED_color == RED)	clr_bit(LED4_PORT_R,LED4_R); else	clr_bit(LED4_PORT_G,LED4_G);
	}
	if(LED_num == 5)
		{
			if(LED_color == RED)
			{
				clr_bit(LED5_PORT_R,LED5_R);
			}else
			{
				clr_bit(LED5_PORT_G,LED5_G);
			}
		}
if(LED_num == 6)
		{
			if (LED_color == RED)
			{
				clr_bit(LED6_PORT_R,LED6_R);
			}else
			{
				clr_bit(LED6_PORT_G,LED6_G);
			}
		}
if(LED_num == 7)
		{
			if (LED_color == RED)
			{
				clr_bit(LED7_PORT_R,LED7_R);
			}else
			{
				clr_bit(LED7_PORT_G,LED7_G);
			}
		}
if(LED_num == 8)
		{
			if (LED_color == RED)
			{
				clr_bit(LED8_PORT_R,LED8_R);
			}else
			{
				clr_bit(LED8_PORT_G,LED8_G);
			}
			}
if(LED_num == 9)
		{
			if (LED_color == RED)
			{
				clr_bit(LED9_PORT_R,LED9_R);
			}else
			{
				clr_bit(LED9_PORT_G,LED9_G);

			}
		}
if(LED_num == 10)
		{
			if (LED_color == RED)
			{
				clr_bit(LED10_PORT_R,LED10_R);
			}else
			{
				clr_bit(LED10_PORT_G,LED10_G);
			}
		}
if(LED_num == 11)
		{
			if (LED_color == RED)
			{
				clr_bit(LED11_PORT_R,LED11_R);
			}else
			{
				clr_bit(LED11_PORT_G,LED11_G);
			}
		}
if(LED_num == 12)
		{
			if (LED_color == RED)
			{
				clr_bit(LED12_PORT_R,LED12_R);
			}else
			{
				clr_bit(LED12_PORT_G,LED12_G);
			}
		}
if(LED_num == 13)
		{
			if (LED_color == RED)
			{
				clr_bit(LED13_PORT_R,LED13_R);
			}else
			{
				clr_bit(LED13_PORT_G,LED13_G);
			}
		}
	
}
//Turn LED_num ex: 1,2.. LED_color:RED Or GREEN
void Turn_LED_On(volatile uint8_t LED_num,uint8_t LED_color)
{
	if(LED_num == 1)
	{
			if(LED_color == RED)
			{
				set_bit(LED1_PORT_R,LED1_R);
				
			}else
			{
				set_bit(LED1_PORT_G,LED1_G);
			}
	}
	if(LED_num == 2)
		{
			if(LED_color == RED)
			{
				set_bit(LED2_PORT_R,LED2_R);
			}else
			{
				set_bit(LED2_PORT_G,LED2_G);
			}
		}
if(LED_num == 3)
		{
			if(LED_color == RED)
			{
				set_bit(LED3_PORT_R,LED3_R);
			}else
			{
				set_bit(LED3_PORT_G,LED3_G);
			}
		}
if(LED_num == 4)
		{
			if(LED_color == RED)
			{
				set_bit(LED4_PORT_R,LED4_R);
			}else
			{
				set_bit(LED4_PORT_G,LED4_G);
			}
		}
if(LED_num == 5)
		{
			if(LED_color == RED)
			{
				set_bit(LED5_PORT_R,LED5_R);
			}else
			{
				set_bit(LED5_PORT_G,LED5_G);
			}
		}
if(LED_num == 6)
		{
			if (LED_color == RED)
			{
				set_bit(LED6_PORT_R,LED6_R);
			}else
			{
				set_bit(LED6_PORT_G,LED6_G);
			}
		}
if(LED_num == 7)
		{
			if (LED_color == RED)
			{
				set_bit(LED7_PORT_R,LED7_R);
			}else
			{
				set_bit(LED7_PORT_G,LED7_G);
			}
		}
if(LED_num == 8)
		{
			if (LED_color == RED)
			{
				set_bit(LED8_PORT_R,LED8_R);
			}else
			{
				set_bit(LED8_PORT_G,LED8_G);
			}
		}
if(LED_num == 9)
		{
			if (LED_color == RED)
			{
				set_bit(LED9_PORT_R,LED9_R);
			}else
			{
				set_bit(LED9_PORT_G,LED9_G);
			}
		}
if(LED_num == 10)
		{
			if (LED_color == RED)
			{
				set_bit(LED10_PORT_R,LED10_R);
			}else
			{
				set_bit(LED10_PORT_G,LED10_G);
			}
		}
if(LED_num == 11)
		{
			if (LED_color == RED)
			{
				set_bit(LED11_PORT_R,LED11_R);
			}else
			{
				set_bit(LED11_PORT_G,LED11_G);
			}
		}
if(LED_num == 12)
		{
			if (LED_color == RED)
			{
				set_bit(LED12_PORT_R,LED12_R);
			}else
			{
				set_bit(LED12_PORT_G,LED12_G);
			}
		}
if(LED_num == 13)
		{
			if (LED_color == RED)
			{
				set_bit(LED13_PORT_R,LED13_R);
			}else
			{
				set_bit(LED13_PORT_G,LED13_G);
			}
		}
	
}
//Turn on any LED 
void Turn_LED_Input(volatile uint8_t* data_in,uint8_t led_type)
{
	for(uint8_t i = 0; i< LED_NUMBER;i++)
	if(led_type == RED) Turn_LED_On(data_in[i],RED); else Turn_LED_On(data_in[i],GREEN);
}
void Turn_LED_Input_Off(volatile uint8_t* data_in,uint8_t led_type)
{
	for(uint8_t i = 0; i< LED_NUMBER;i++)
	if(led_type == RED) Turn_LED_Off(data_in[i],RED); else Turn_LED_Off(data_in[i],GREEN);
}
void Turn_All_LED_On(uint8_t LED_color)
{
	for(uint8_t i = 1; i<= LED_NUMBER;i++)
	{
		Turn_LED_On(i,LED_color);
	}
}
void Turn_All_LED_Off(uint8_t LED_color)
{
	for(uint8_t i = 1; i<= LED_NUMBER;i++)
	{
		Turn_LED_Off(i,LED_color);
	}
}
void Turn_All_Led_On_Delay(volatile uint8_t* led_in,uint8_t led_color)
{
	for(uint8_t i = 0; i< LED_NUMBER;i++)
	{
		Turn_LED_On(led_in[i],led_color);
		_delay_ms(500);
	}
}