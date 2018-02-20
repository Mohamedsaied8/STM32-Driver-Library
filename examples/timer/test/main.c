#include "Clk.c"

void  GPIO_Init(){
 RCC->APB2ENR |= 1 << 6;  /* Enable GPIOE clock */ 
 GPIOE->CRH = 0x33333333;  /* Configure the GPIO for LEDs */ 
} 
void SystemInit(){
   initClk();
}

int main(){
 GPIO_Init();
    for (;;) {  /* Loop forever */  
       GPIOE->ODR ^= 0xFF00; 
       delayms(50);  
      } 

}