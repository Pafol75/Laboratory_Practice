#include "init.h"
#define DELAY_BUTTON_FILTER 100

extern volatile uint8_t Button1Type, Button2Type, Button3Type;
extern volatile uint32_t initTime, pastTime1, pastTime2, pastTime3;

void SysTick_Handler(void);
void EXTI9_5_IRQHandler(void);

