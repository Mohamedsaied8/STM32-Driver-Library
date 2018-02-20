#define Freq8
#include <watchdog.h>
#include <clk.h>
#include <gpio.h>

void SystemInit(){
	
}


int main(){
	portInit(GPIOE,0xFFFF);
	initWatchDog(0xFFF,PRESCALE_4);
		PORTE = 0xFFFF;
		delayms(100);
		PORTE = 0;
		delayms(100);
	while(1){
		PORTE = 0xFFFF;
		delayms(100);
		resetWatchDog();
}
}
