#define Freq25
#include <timer.h>
#include <clk.h>
#include <gpio.h>

unsigned int res,res1;

void SystemInit(){
	
}

void TIM5_IRQHandler(  )  {
	 if (timerStatusChannel(TIM5,2))       { //output compare?
      resetTimerStatusChannel(TIM5,2);  
      PORTE ^= 0xFF00;
	}
}

int main ( ) {
	portInit(GPIOE,0xFFFF);
  timerInit(TIM5,8000);
	initTimerIC(TIM5,2,RISING);  
	enableTimerInterrupt(TIM5,1,2);
	while(1){ 
		
	}
}	
