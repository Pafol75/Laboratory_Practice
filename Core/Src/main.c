#include "../Inc/init.h"

uint8_t flag1 = 0;
uint8_t flag2 = 0;

int main(void)
{

    GPIO_Ini();
    while (1)
    {
        if ((READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_6) != 0))
        {
            flag1 = 1;
            flag2 = 0;
            SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS7);
            for (int i = 0; i < 500000; i++)
                ;
            SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR7);
        }
        if (READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_7) != 0)
        {
            flag1 = 0;
            flag2 = 1;
            SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS0);
            for (int i = 0; i < 500000; i++)
                ;
            SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR0);
        }
        if (flag1 == 1)
        {
            SET_BIT(GPIOC->MODER, GPIO_MODER_MODE12_0);
            SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS12);
        }
        if (flag2 == 1)
        {
            SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR12);
            // SET_BIT(GPIOC->MODER, GPIO_MODER_MODE12);
            if (READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_12) != 0)
            {
                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS14);
                for (int i = 0; i < 500000; i++)
                    ;
                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR14);
            }
        }
    }
}
