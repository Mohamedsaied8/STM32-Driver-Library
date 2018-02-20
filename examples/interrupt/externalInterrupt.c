#define Freq25
#include <extint.h>
#include <clk.h>
#include <gpio.h>


void SystemInit(){
	
}

void EXTI0_IRQHandler(  )  {
  PORTE ^= 0xFF00;
	resetExternalInterrupt(EXTI0);
}

int main ( ) {  
 portInit(GPIOE,0xFFFF);
	EXTInterruptEnable(EXTI0,TRUE,FALSE); 
	EXTInterruptPinEnable(EXTI0,PE);
	while(1){ 
		
	};
}	
