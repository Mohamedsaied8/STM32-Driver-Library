/*
Dual CAN (connectivity line only) 
CAN1: Master bxCAN for managing the communication between a Slave bxCAN and the 512-byte SRAM memory 
CAN2: Slave bxCAN, with no direct access to the SRAM memory. 
The two bxCAN cells share the 512-byte SRAM memory
*/
#define Freq25
#include "clk.h"
#include "can.h"
#include "usart.h"
#include "nvic.h"


#define Id0 0xffffffff
#define Id1 0xA1Cafe
#define Id2 0xABC11
#define Id3 0x123

extern CAN_msg  CAN_TxMsg, CAN_RxMsg;

volatile int i,p=0;

void SystemInit( )   //called by start up code
{
	 initClk();
}

int main( )
{	unsigned char m1[8] = "Hello \n";
	unsigned char m2[8] = "ARTRONI";
	unsigned char m3[8] = "X ComP";
	unsigned char m4[8] = "any \n";
	
	 canInit(CAN1,POLLING);  
   canInit(CAN2,POLLING);
	usartInit(USART1,250000);
  nvic_enable_irq(NVIC_USB_LP_CAN_RX0_IRQ);
 Send_String(USART1,"Start\n");
	//delayms(1100);
  while (1) {
	
	 	 GPIOE->ODR = (1<<15);
		filtersInit(CAN1,Id0);
		//CAN1 or CAN2 ,Identifier , extended id or standard id , data frame or remote frame , message , mailbox index
		canTransmit(CAN2,Id0,EXTENDED_FORMAT,DATA_FRAME,m1,0);
				for(i=0;i<50000;i++){}
		canRead(CAN1,&CAN_RxMsg,0);
		Send_String(USART1,CAN_RxMsg.data);
		CAN1_ReceiveFIFO=RELEASE;
	  	filtersInit(CAN1,Id1);
		canTransmit(CAN2,Id1,EXTENDED_FORMAT,DATA_FRAME,m2,1);
		for(i=0;i<50000;i++){}
		canRead(CAN1,&CAN_RxMsg,0);
		Send_String(USART1,CAN_RxMsg.data);
		CAN1_ReceiveFIFO=RELEASE;
			
		filtersInit(CAN1,Id2);
		canTransmit(CAN2,Id2,EXTENDED_FORMAT,DATA_FRAME,m3,2);
		for(i=0;i<50000;i++){}
		canRead(CAN1,&CAN_RxMsg,0);
		Send_String(USART1,CAN_RxMsg.data);
		CAN1_ReceiveFIFO=RELEASE;
			
		filtersInit(CAN1,Id3);
		canTransmit(CAN2,Id2,EXTENDED_FORMAT,DATA_FRAME,m4,0);
		for(i=0;i<50000;i++){}
		canRead(CAN1,&CAN_RxMsg,0);
		Send_String(USART1,CAN_RxMsg.data);
		CAN1_ReceiveFIFO=RELEASE;
			
	  GPIOE->ODR = 1<<9;   //LED ON for observation on MSO 
		
	}			

}