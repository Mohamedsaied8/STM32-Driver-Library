#define Freq25
#include <timer.h>
#include <clk.h>
#include <gpio.h>

void SystemInit(){
	
}

void timerdelayms(int t){
	reinitTimer(TIM4);
	while(timerCount(TIM4)<t);
}

int main(){
	portInit(GPIOE,0xFFFF);
	timerInit(TIM4,8000);
	while(1){
		PORTE ^= 0xFF00;
		timerdelayms(1000);
}
}
