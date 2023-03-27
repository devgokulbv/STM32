#include "main.h"
#define RCC_BASE 0x40023800
#define GPIOA_BASE 0x40020000
void init_reg(void);
void init_reg()
{
	volatile long *RCC_CR =(volatile long *)(RCC_BASE +0x00);
	*RCC_CR |= (1 << 16);
	while(!(*RCC_CR &(1 << 17)));

	volatile long *RCC_CFGR =(volatile long *)(RCC_BASE + 0x08);
	*RCC_CFGR &= ~(0x3 << 21);
	*RCC_CFGR |= (1 << 0);


	volatile long *RCC_AHB1ENR =(volatile long *)(RCC_BASE + 0x30);
    *RCC_AHB1ENR |= (1 << 0);

    volatile long *GPIOA_MODER =(volatile long *)(GPIOA_BASE + 0x00);
    *GPIOA_MODER &= ~(0x3 << 16);
    *GPIOA_MODER |= (0x2 << 16) | (1 << 0);

    volatile long *GPIOA_AFR =(volatile long *)(GPIOA_BASE + 0x24);
    *GPIOA_AFR &= ~(0xF<< 0);

    volatile long *GPIOA_ODR =(volatile long *)(GPIOA_BASE + 0x14);
    *GPIOA_ODR = 0x1UL;
}


int main(void)
{


  init_reg();
  while (1)
  {

  }

}

