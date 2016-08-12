/*
 * CFile1.c
 *
 * Created: 04-08-2016 17:09:42
 *  Author: BhaviK
 */ 



#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>
#include <stdbool.h>
#include "USART_128.h"

#define total_s 4

volatile int seq_index,cur_index;
volatile int sequence[total_s+1],flag[total_s+1];
char received;

void Reset(void)
{	DDRD =0x00;
	PORTD |= (1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3);
	int i;
	for(i=1;i<=total_s;i++)
	{	sequence[i]=0;
		flag[i]=1;
	}
	seq_index=1;
	cur_index=1;
}

int increment(int x)
{	if(x<(total_s))
		x+=1;
	else
		x=0;
	
	return x;
}

int main(void)
{	Reset();
	
	// interrupt , falling edge
	EICRA |= (1<<ISC01) | (1<<ISC11) | (1<<ISC21) | (1<<ISC31);
	EIMSK |= (1<<INT0) | (1<<INT1) | (1<<INT2) | (1<<INT3);
	
	USART_Init(12,0);
	USART_InterruptEnable(0);
	sei();
	int i;
    while (1) 
    {	
    }
}

ISR(INT0_vect) {
	if(flag[1]==1)
	{
		flag[1]=0;
		flag[2] = 0;
		flag[3] = 0;
		flag[4] = 0;
		USART_TransmitNumber(1,0);	
	}
}


ISR(INT1_vect) {
	if(flag[2]==1)
	{	
		flag[1]=0;
		flag[2] = 0;
		flag[3] = 0;
		flag[4] = 0;
		USART_TransmitNumber(2,0);
	}
}

ISR(INT2_vect) {
	if(flag[3]==1)
	{
   		flag[1]=0;
   		flag[2] = 0;
   		flag[3] = 0;
   		flag[4] = 0;
        USART_TransmitNumber(3,0);	
	}
}


ISR(INT3_vect) {
	if(flag[4]==1)
	{
		flag[1]=0;
		flag[2] = 0;
		flag[3] = 0;
		flag[4] = 0;
		USART_TransmitNumber(4,0);
	}
}

ISR(USART0_RX_vect)
{
	received=USART_Receive(0);
	if(received=='r')
	{
		Reset();
	}
}