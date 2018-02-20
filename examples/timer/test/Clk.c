#include "Clk.h"
#include <stm32f10x_cl.h>
#define Freq25

#ifdef Freq25
#define CYCLETIME 40
#endif
#ifdef Freq50
#define CYCLETIME 20
#endif
#ifdef Freq8
#define CYCLETIME 125
#endif

void initClk(){
#ifdef Freq25
	RCC->CR |= 1<<HSE;	//HSE on
  while (RCC->CR & (1<<HSEON));	//wait until HSE ready
  RCC->CFGR = 0x00000001;	//select HSE as system clock
#endif
#ifdef Freq50
  FLASH->ACR = CLKUPTO72;  //for system clock between 48 and 72MHz
  RCC->CR |= 1<<HSE;  //HSE on  
  while (!(RCC->CR & (1<<HSEON)));  //wait until HSE ready 
  RCC->CFGR |= 2<<PLLMUL;  // mult by 9 --->72MHz  
  RCC->CFGR |= 1<<PLLSCR;  //APB1 = 36MHz. See bus clocks.  
  RCC->CFGR |= 1<<APP1BCLK;  //APB1 = 36MHz. See bus clocks.
  RCC->CR |= 1<<PLL;  //enable PLL  
  while (!(RCC->CR & (1<<PLLLOCKED)));  //wait until locked  
  RCC->CFGR |= 2;  //PLL as clock source  
		#endif
#ifdef Freq50
#endif
}
void delayus(unsigned long t){
	unsigned long l=(((t*1000)-(30*CYCLETIME))/(5*CYCLETIME));
	unsigned long i=0;
	while(i<l){	
			__nop();
		i++;
	}
}
void delayms(unsigned long t){
#ifdef Freq25
	unsigned long l=((t*5000)-6);
#endif
#ifdef Freq50
	unsigned long l=((t*10000)-6);
#endif
#ifdef Freq8
	unsigned long l=((t*1600)-6);
#endif
	unsigned long i=0;
	while(i<l){	
			__nop();
		i++;
	}
}

