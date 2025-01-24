#include "../Inc/init.h"
#include "../Inc/main.h"

volatile uint8_t mode = 0; // Режим работы гирлянды
volatile uint8_t currentLED = 0; // Текущий светодиод для настройки частоты мерцания
volatile uint8_t blinkFrequency = 0; // Частота мерцания
volatile uint8_t blinkFrequencies[6] = {0};
extern volatile uint32_t initTime;
volatile uint32_t interval;
int freq1[3] = {2400, 1300, 600};
int freq2[3] = {1500, 900, 200};
int CountMode[6] = {0};

void mode1_control(void)
{
    static uint8_t ledIndex = 0;
    static uint32_t lastTime = 0;
    uint32_t currentTime = initTime;

    switch (blinkFrequency) {
        case 0:
            interval = freq1[0]; // 0.6 Гц
            break;
        case 1:
            interval = freq1[1]; // 1.3 Гц
            break;
        case 2:
            interval = freq1[2]; // 2.4 Гц
            break;
    }

    if (currentTime - lastTime >= interval) {
        switch (ledIndex) {
            case 0:
                GPIOB->ODR ^= GPIO_ODR_OD0;
                break;
            case 1:
                GPIOB->ODR ^= GPIO_ODR_OD7;
                break;
            case 2:
                GPIOB->ODR ^= GPIO_ODR_OD14;
                break;
            case 3:
                GPIOB->ODR ^= GPIO_ODR_OD15;
                break;
            case 4:
                GPIOD->ODR ^= GPIO_ODR_OD6;
                break;
            case 5:
                GPIOD->ODR ^= GPIO_ODR_OD7;
                break;
        }
        ledIndex = (ledIndex + 1) % 6;
        lastTime = currentTime;
    }
}

void mode2_control(void)
{
    static uint32_t lastTimes[6] = {0, 0, 0, 0, 0, 0};
    uint32_t currentTime = initTime;

    for (uint8_t i = 0; i < 6; i++) {
        uint32_t interval = 0;
        switch (blinkFrequencies[i]) {
            case 0:
                interval = freq2[0]; // 0.2 Гц
                break;
            case 1:
                interval = freq2[1]; // 0.9 Гц
                break;
            case 2:
                interval = freq2[2]; // 1.5 Гц
                break;
        }

        if (currentTime - lastTimes[i] >= interval) {
            switch (i) {
                case 0:
                    GPIOB->ODR ^= GPIO_ODR_OD0;
                    break;
                case 1:
                    GPIOB->ODR ^= GPIO_ODR_OD7;
                    break;
                case 2:
                    GPIOB->ODR ^= GPIO_ODR_OD14;
                    break;
                case 3:
                    GPIOB->ODR ^= GPIO_ODR_OD15;
                    break;
                case 4:
                    GPIOD->ODR ^= GPIO_ODR_OD6;
                    break;
                case 5:
                    GPIOD->ODR ^= GPIO_ODR_OD7;
                    break;
            }
            lastTimes[i] = currentTime;
        }
    }
}

int main(void)
{

    RCC_Init();
    ITR_init();
    SysTick_Init();
    GPIO_Ini();
    interval = 0;
    while (1)
    {
         if (mode == 0) {
            mode1_control();
        } else {
            mode2_control();
        }
    }
}
