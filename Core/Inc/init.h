#include "C:/Users/dedla/Documents/Labstm/Laboratory_Practice/CMSIS/Devices/Inc/stm32f4xx.h"
#include "C:/Users/dedla/Documents/Labstm/Laboratory_Practice/CMSIS/Devices/Inc/stm32f429xx.h"
#include <stdint.h>

#define GPIOC_MODER (*(uint32_t*)(0x40020800UL + 0x00UL))
#define GPIOC_OTYPER (*(uint32_t*)(0x40020800UL + 0x04UL))
#define GPIOC_OSPEEDR (*(uint32_t*)(0x40020800UL + 0x08UL))
#define GPIOC_PUPDR (*(uint32_t*)(0x40020800UL + 0x0CUL))
#define GPIOC_BSRR (*(uint32_t*)(0x40020800UL + 0x18UL))
#define GPIOC_MODE_OUT_PIN6 0x001000UL
#define GPIOC_TYPE_PP_PIN6 0x000000UL
#define GPIOC_SPEED_M_PIN6 0x00400UL
#define GPIOC_PUPDR_NPUPD_PIN6 0x000000UL
#define GPIOC_PIN6_S 0x000040UL
#define GPIOC_PIN6_R 0x800000UL

void RCC_Init(void);
void ITR_init(void);
void SysTick_Init(void);
void GPIO_Ini(void);

// #define RCC_GPIO_EN (*(uint32_t*)(0x40023800UL + 0x30UL))
// #define RCC_GPIOB_EN 0x02UL
// #define RCC_GPIOC_EN 0x04UL
// #define GPIOB_MODER (*(uint32_t*)(0x40020400UL + 0x00UL))
// #define GPIOB_OTYPER (*(uint32_t*)(0x40020400UL + 0x04UL))
// #define GPIOB_OSPEEDR (*(uint32_t*)(0x40020400UL + 0x08UL))
// #define GPIOB_PUPDR (*(uint32_t*)(0x40020400UL + 0x0CUL)) 
// #define GPIOB_BSRR (*(uint32_t*)(0x40020400UL + 0x18UL))
// #define GPIOC_IDR (*(uint32_t*)(0x40020800UL + 0x10UL))
// #define GPIOC_IDR_PIN13 0x002000UL
// #define GPIOB_MODE_PIN7_OUT 0x004000UL
// #define GPIOB_OTYPE_PIN7_PP 0x000000UL
// #define GPIOB_OSPEED_PIN7_MID 0x004000UL
// #define GPIOB_PUPDR_PIN7_NOPUPD 0x000000UL
// #define GPIOB_BSRR_PIN7_SET 0x000080UL
// #define GPIOB_BSRR_PIN7_RESET 0x800000UL
// #define READ_BIT(REG, BIT) (REG & BIT)
// #define SET_BIT(REG, BIT) (REG |= BIT)
