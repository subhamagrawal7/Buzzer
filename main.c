/*
 *
 * Created: 28-07-2016 16:54:27
 *  Author: Drishti
 * 
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>
#include "USART_128.h"

#define total_s 4

volatile int seq_index,cur_index;
volatile int sequence[total_s+1],flag[total_s+1];

void Reset(void)
{	PORTD |= (1<<PD1) | (1<<PD2);
	PORTE |= (1<<PE4) |(1<<PE5) |(1<<PE6) |(1<<PE7);
	
	int i;
	for(i=0;i<=total_s;i++)
	{	sequence[i]=0;
		flag[i]=1;
	}
	seq_index=1;
	cur_index=0;
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
	EICRA |= (1<<ISC11) | (1<<ISC21);
	EICRB |= (1<<ISC41) | (1<<ISC51) | (1<<ISC61) | (1<<ISC71);
	EIMSK |= (1<<INT1) | (1<<INT2) | (1<<INT4) | (1<<INT5) | (1<<INT6) | (1<<INT7);
	
	DDRG=0xFF;
	PORTG=0x00;
	
	USART_Init(12,0);
	sei();
	
    while (1) 
    {	if(sequence[cur_index]==0)
			USART_TransmitNumber(0,0);
			//PORTB=0x00;
		else if(sequence[cur_index]==1)
			USART_TransmitNumber(1,0);
			//PORTB=0x02;
		else if(sequence[cur_index]==2)
			USART_TransmitNumber(2,0);
			//PORTB=0x04;
		else if(sequence[cur_index]==3)
			USART_TransmitNumber(3,0);
			//PORTB=0x08;
		else if(sequence[cur_index]==4)
			USART_TransmitNumber(4,0);
			//PORTB=0x10;
		
    }
}


ISR(INT1_vect) {
	Reset();
}

ISR(INT2_vect) {
	cur_index=increment(cur_index);
}

ISR(INT4_vect) {
	if(flag[1]==1)
	{sequence[seq_index]=1;
	 seq_index=increment(seq_index);
	 flag[1]=0;
	}
}


ISR(INT5_vect) {
	if(flag[2]==1)
	{sequence[seq_index]=2;
     seq_index=increment(seq_index);
	 flag[2]=0;
	}
}

ISR(INT6_vect) {
	if(flag[3]==1)
	{sequence[seq_index]=3;
	 seq_index=increment(seq_index);
   	 flag[3]=0;
	}
}


ISR(INT7_vect) {
	if(flag[4]==1)
	{sequence[seq_index]=4;
	 seq_index=increment(seq_index);
	 flag[4]=0;
	}
}
