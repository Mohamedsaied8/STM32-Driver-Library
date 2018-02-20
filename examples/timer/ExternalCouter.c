#define Freq25
#include <timer.h>
#include <clk.h>

unsigned int counts;

void SystemInit(){
	
}

int main ( ) {
	advancedTimerInit(TIM4,1,EXTERNAL,DOWN);
  setTimerCount(TIM4,5000);	
	while(1){
		counts=timerCount(TIM4);
	};
}	
