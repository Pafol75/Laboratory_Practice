#include "C:/Users/dedla/Documents/Labstm/Laboratory_Practice/CMSIS/Devices/Inc/stm32f4xx.h"

extern volatile uint8_t mode;
extern volatile uint8_t currentLED;
extern volatile uint8_t blinkFrequency;
extern volatile uint8_t blinkFrequencies[6];
extern int freq1[3];
extern int freq2[3];
extern int CountMode[6];

void GPIO_Ini(void);
void ITR_init(void);
void SysTick_Init(void);
void mode1_control(void);
void mode2_control(void);