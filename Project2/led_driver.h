#ifndef _LED_DRIVER_H_
#define _LED_DRIVER_H_
#include <avr/io.h>
#define set_bit(port,bit)     (port |= (1<<bit))
#define clr_bit(port,bit)     (port &=~(1<<bit))
#define LED_NUMBER    13
uint8_t RED = 1, GREEN = 0;
#define LED1_G      0
#define LED1_PORT_G PORTH
#define LED1_R      5
#define LED1_PORT_R PORTE
#define LED2_G      4
#define LED2_PORT_G PORTE
#define LED2_R      3
#define LED2_PORT_R PORTE
#define LED3_G      5
#define LED3_PORT_G PORTG
#define LED3_R      0
#define LED3_PORT_R PORTF
#define LED4_G      1       
#define LED4_PORT_G PORTF 
#define LED4_R      2
#define LED4_PORT_R PORTF 
#define LED5_G      3
#define LED5_PORT_G PORTF
#define LED5_R      4
#define LED5_PORT_R PORTF
#define LED6_G      5
#define LED6_PORT_G PORTF
#define LED6_R      6
#define LED6_PORT_R PORTF
#define LED7_G      7
#define LED7_PORT_G PORTF
#define LED7_R      0
#define LED7_PORT_R PORTK
#define LED8_G      1
#define LED8_PORT_G PORTK
#define LED8_R      2
#define LED8_PORT_R PORTK
#define LED9_G      3
#define LED9_PORT_G PORTK
#define LED9_R      4
#define LED9_PORT_R PORTK
#define LED10_G     5
#define LED10_PORT_G PORTK
#define LED10_R     6
#define LED10_PORT_R PORTK
#define LED11_G     7
#define LED11_PORT_G PORTK
#define LED11_R     0
#define LED11_PORT_R PORTA
#define LED12_G     1
#define LED12_PORT_G PORTA
#define LED12_R     2
#define LED12_PORT_R PORTA
#define LED13_G     3
#define LED13_PORT_G PORTA
#define LED13_R     4
#define LED13_PORT_R PORTA
void Led_Init(void);
void Turn_LED_Off(uint8_t LED_num,uint8_t LED_color);
void Turn_LED_On(volatile uint8_t LED_num,uint8_t LED_color);
void Turn_LED_Input(volatile uint8_t* data_in,uint8_t led_type);
void Turn_LED_Input_Off(volatile uint8_t* data_in,uint8_t led_type);
void Turn_All_LED_On(uint8_t LED_color);
void Turn_All_LED_Off(uint8_t LED_color);
void Turn_All_Led_On_Delay(volatile uint8_t* led_in,uint8_t led_color);
#endif