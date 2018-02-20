#define Freq25
#include <timer.h>
#include <clk.h>


unsigned int res,res1;


void SystemInit(){
	
}

int main ( ) {
  timerInit(TIM5,8000);
  initTimerIC(TIM5,2,RISING);
  while(1){ 
    res = readCapture(TIM5,2);
    res1 = readCapture(TIM5,2)-res; 
  }
}
