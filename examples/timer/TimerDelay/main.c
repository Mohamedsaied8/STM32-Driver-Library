#define Freq25
#include <clk.h>
#include <timer.h>
#include <gpio.h>

int clk;
void SystemInit(){
	
	initClk();
}

void timerdelayms(int t){
	reinitTimer(TIM4);
	while(timerCount(TIM4)<t);
}

int main(){
	clk=__clk;
	portInit(GPIOE,0xFFFF);
	timerInit(TIM4,8000);
	while(1){
		PORTE ^= 0xFF00;
		delayus(50000);
}
}
