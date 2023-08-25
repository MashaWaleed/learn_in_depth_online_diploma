#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define GPIOA_BASE   0x40010800
#define GPIOA_CRH    *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL    *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR    *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA13      (1UL<<13)
#define GPIOA0       (1UL<<0)

#define RCC_BASE     0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_IOPAEN   (1<<2)
#define RCC_AFIOEN   (1<<0)

//AFIO
#define AFIO_BASE    0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_BASE + 0x08)

//EXTI
#define EXTI_BASE    0x40010400
#define EXTI_IMR     *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR    *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR      *(volatile uint32_t *)(EXTI_BASE + 0x14) //WRITE 1

//NVIC
#define NVIC_BASE    0xE000E100
#define NVIC_ISER0   *(volatile uint32_t *)(NVIC_BASE + 0x00)
#define NVIC_IRQ6    (1UL<<6)


void GPIO_init(void)
{
    //configure pinA13 as output
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;

    //configure pinA0 as floating input and alternative function
    GPIOA_CRL |= (0b01<<2);
    AFIO_EXTICR1 = 0;


}

void Clock_init(void)
{
    RCC_APB2ENR |= RCC_IOPAEN;
    RCC_APB2ENR |= RCC_AFIOEN;
}
void Interrupt_init(void)
{
    EXTI_IMR   |= (1<<0);
    EXTI_RTSR  |= (1<<0);

    NVIC_ISER0 |= NVIC_IRQ6;

}

int main(void)
{
    Clock_init();
    GPIO_init ();
    Interrupt_init();

    while(1);
}

void EXTI0_IRQHandler(void)
{
    GPIOA_ODR ^= GPIOA13;
    EXTI_PR  |= (1<<0);
}
