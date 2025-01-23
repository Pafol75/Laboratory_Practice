#include "../Inc/init.h"

extern uint8_t flag1, flag2, flag3, flag4, flag5, flag6, LedState;
extern uint8_t flag1ON, flag2ON, flag3ON, flag4ON, flag5ON, flag6ON;
volatile uint8_t BtnCount1, BtnCount2, BtnCount3;
extern uint16_t ledTime1, ledTime2, ledTime3, ledTime4, ledTime5, ledTime6;
extern uint16_t GlobalTickCount;
extern uint16_t dtime, cycleTime;


int freq1[3] = {2400, 1300, 600};
int freq2[3] = {1500, 900, 200};
int CountMode[6];
int main(void)
{

    RCC_Init();
    ITR_init();
    SysTick_Init();
    GPIO_Ini();

    while (1)
    {
        
    }
}
