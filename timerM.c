#include "tm4c123gh6pm11.h"
#include "timerM.h"

// You can use this timer only if you learn how it works
void Timer2_Init(float period){ 
  unsigned long volatile delay;
  SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate timer2
  delay = SYSCTL_RCGCTIMER_R;
  //TimerCount = 0;
  //Semaphore = 0;
  TIMER2_CTL_R = 0x00000000;    // 1) disable timer2A during setup
  TIMER2_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER2_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER2_TAILR_R = (period*16000000)-1;    // 4) reload value
  TIMER2_TAPR_R = 0;            // 5) bus clock resolution
  TIMER2_ICR_R = 0x00000001;    // 6) clear timer2A timeout flag
  TIMER2_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x80000000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 39, interrupt number 23
  NVIC_EN0_R = 1<<23;           // 9) enable IRQ 23 in NVIC
  TIMER2_CTL_R = 0x00000001;    // 10) enable timer2A
}

void Timer1_Init(float period){ 
  unsigned long volatile delay;
  SYSCTL_RCGCTIMER_R |= 0x02;   // 0) activate timer2
  delay = SYSCTL_RCGCTIMER_R;
  //TimerCount = 0;
  //Semaphore = 0;
  TIMER1_CTL_R = 0x00000000;    // 1) disable timer1A during setup
  TIMER1_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER1_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER1_TAILR_R = (period*16000000)-1;    // 4) reload value
  TIMER1_TAPR_R = 0;            // 5) bus clock resolution
  TIMER1_ICR_R = 0x00000001;    // 6) clear timer2A timeout flag
  TIMER1_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x80000000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 39, interrupt number 23
  NVIC_EN0_R = 1<<21;           // 9) enable IRQ 23 in NVIC
  TIMER1_CTL_R = 0x00000001;    // 10) enable timer2A
}

void Timer0_Init(float period){ 
  unsigned long volatile delay;
  SYSCTL_RCGCTIMER_R |= 0x01;   // 0) activate timer2
  delay = SYSCTL_RCGCTIMER_R;
  //TimerCount = 0;
  //Semaphore = 0;
  TIMER0_CTL_R = 0x00000000;    // 1) disable timer2A during setup
  TIMER0_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER0_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER0_TAILR_R = (period*16000000)-1;    // 4) reload value
  TIMER0_TAPR_R = 0;            // 5) bus clock resolution
  TIMER0_ICR_R = 0x00000001;    // 6) clear timer2A timeout flag
  TIMER0_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x80000000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 39, interrupt number 23
  NVIC_EN0_R = 1<<19;           // 9) enable IRQ 23 in NVIC
  TIMER0_CTL_R = 0x00000001;    // 10) enable timer2A
}

void Timer2_disable(){ 
  
  TIMER2_CTL_R = 0x00000000;    // 10) enable timer2A
  
}

void Timer1_disable(){ 
  
  TIMER1_CTL_R = 0x00000000;    // 10) enable timer2A
  
}

void Timer0_disable(){ 
  
  TIMER0_CTL_R = 0x00000000;    // 1) disable timer1A during setup
  
}

