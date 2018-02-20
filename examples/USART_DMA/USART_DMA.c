#define Freq25
#include "clk.h"
#include "dma.h"
#include "usart.h"
#include "nvic.h"

char tx[10] = "Artonix\r\n";
int tx_len = 10;
char rx[3] ;
int rx_len = 6;
volatile int i;
volatile int transfered = 0;
volatile int received = 0;

void SystemInit(){
	initClk();
	
}

int main(){
	CLOCK_BUS_HIGH=DMACLOCK_ENABLE;
	usartInit(USART1,9600);

	
 	nvic_set_priority(NVIC_DMA1_CHANNEL4_IRQ, 0);
  nvic_enable_irq(NVIC_DMA1_CHANNEL4_IRQ);

	nvic_set_priority(NVIC_DMA1_CHANNEL5_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL5_IRQ);
	
	portInit(GPIOE,0xffff);
	transfered = 0;
	received = 0;
			
	/* Blink the LED (PE15) on the board with every transmitted byte. */
	while (1) {

			portWrite(GPIOE,!(1<<15));
			
			PORTE|=(1<<15);
		
			 dma_write_usart1("MOHAMED ABDALLAH ROCKS\n",25);
		
			for(i=0;i<500000;i++){}

//Send_String(USART1,"HELLO NO ERROR");
	}
	return 0;
}

void DMA1_Channel5_IRQHandler(void)
{
	if((DMA1_ISR &DMA_ISR_TCIF5) != 0)  {
		DMA1_IFCR |= DMA_IFCR_CTCIF5;
	
		received = 1;
	}

	dma_disable_transfer_complete_interrupt(DMA1, DMA_CHANNEL5);

	dma_disable_channel(DMA1, DMA_CHANNEL5);
}



void DMA1_Channel4_IRQHandler(void)
{
	if ((DMA1_ISR &DMA_ISR_TCIF4) != 0) {
		DMA1_IFCR |= DMA_IFCR_CTCIF4;
		
			SendChar(USART1,'\n');

		transfered = 1;
	
	}

	dma_disable_transfer_complete_interrupt(DMA1, DMA_CHANNEL4);
	//usart_disable_tx_dma
	dma_disable_channel(DMA1, DMA_CHANNEL4);
}

