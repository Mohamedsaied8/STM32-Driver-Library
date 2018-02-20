#define Freq25
#include <timer.h>
#include <clk.h>
#include <gpio.h>

unsigned int res,res1;

void SystemInit(){
	
}


int main ( ) {
	timerInit(TIM3,8000);
	portInitAlt(GPIOB,3);
	initTimerOC(TIM3,1000,500,3);
	initTimerOC(TIM3,1000,250,4);
	while(1){ 
	};
}	
