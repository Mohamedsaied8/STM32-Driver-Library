#define Freq25
#include <timer.h>
#include <clk.h>
#include <gpio.h>

unsigned int res,res1;

void SystemInit(){
	
}


void TIM4_IRQHandler(  )  {
  if (timerStatusUpdate(TIM4))       { 
		resetTimerStatusUpdate(TIM4);
	  GPIOE->ODR = 0x00FF;
	}
  if (timerStatusChannel(TIM4,1))       { 
		resetTimerStatusChannel(TIM4,1);
		GPIOE->ODR = 0xFF00;
	}
}


int main ( ) {
  portInit(GPIOE,0xFFFF);
	portInitAlt(GPIOB,0x40);
	advancedTimerInit(TIM4,8000,INTERNAL,UP);
	initTimerOC(TIM4,1000,500,1);
	enableTimerInterrupt(TIM4,1,1);
	while(1){ 
	};
}	
