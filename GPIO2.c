
#include "tm4c123gh6pm11.h"

char delays;

void PortF_Init(void){                                               
	//configue PF0, PF4 as Input PINS and high level sensing 
  SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
  delays = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R = 0x13;           // allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x02;          // 5) PF4,PF0, PF1 as input   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_DEN_R = 0x13;          // 7) enable digital pins PF5,PF0       
	GPIO_PORTF_PUR_R |= 0x11;         // enable pullup resistors on PF0,PF4       
  GPIO_PORTF_IS_R |= 0x11;        	//EDGE SENSE
  //GPIO_PORTF_IBE_R &= ~0x11;       	//SINGLE EDGE
  GPIO_PORTF_IEV_R |= 0x11;        //FAILING EDGE for PF0, PF4
  GPIO_PORTF_ICR_R = 0x11;          // CLEAR FLAGS ON PF0,PF4
  GPIO_PORTF_IM_R |= 0x11;    		 	// ARM INTERRUPT PF0,PF4
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000;  //PRIORITY 5
  NVIC_EN0_R = 0x40000000;          //ENABLE INTERRUPT 30
}

void PortB_init()
{
	SYSCTL_RCGC2_R |= 0x00000002; //portB clock
	delays = SYSCTL_RCGC2_R;           // delay   
	GPIO_PORTB_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTB_CR_R = 0x0E;           // allow changes to PF4-0     
	
	GPIO_PORTB_DIR_R |= (1<<1);
	GPIO_PORTB_DIR_R |= (1<<2);
	GPIO_PORTB_DIR_R |= (1<<3);
	
	GPIO_PORTB_DEN_R |= (1<<1);
	GPIO_PORTB_DEN_R |= (1<<2);
	GPIO_PORTB_DEN_R |= (1<<3);
	
	GPIO_PORTB_AMSEL_R &= ~(1<<1);
	GPIO_PORTB_AMSEL_R &= ~(1<<2);
	GPIO_PORTB_AMSEL_R &= ~(1<<3);
}
