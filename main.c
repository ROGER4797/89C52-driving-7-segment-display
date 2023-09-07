/**********************************
89C52   or  89S52
11.059 MHz

**********************************/
#include <reg52.h>
#define uchar unsigned char
#define uint  unsigned int
	
uchar disp_num[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};// 7 seg display codes 0-9 

#define LED P0 //  7 segment LED data codes applied to P0

sbit ENLED1 = P1^3 ; // Digit 1 enable for board NH5100
sbit ENLED2 = P1^4 ; // Digit 2 enable
sbit ENLED3 = P1^5 ; // Digit 3 enable
sbit ENLED4 = P1^6 ; // Digit 4 enable

unsigned char dig1,dig2,dig3,dig4;   // assign variables in RAM


// locate 4 variables at the end of internal RAM is for assembler version
/*
dig1	EQU	07Ch
dig2	EQU	07Dh
dig3	EQU	07Eh
dig4	EQU	07Fh
*/






//
void Timer2() interrupt 5	  //
{
 static uint t;
	
 TF2=0;  // RESET TIMER 2 overflow flag
	
 t++;
	
	
	switch (t) 
		{
		case 1:
			
		{	
			ENLED4 = 1; //Turn off previous digit
			P0 = dig1;	// set data for digit 1
			ENLED1 = 0; // Turn on digit 1
		}
		break;
		
		case 2:
			ENLED1 = 1; //Turn off previous digit
			P0 = dig2;  // set data for digit 2
		  	ENLED2 = 0; // Turn on digit 2
		break;
		
		case 3:
			ENLED2 = 1; //Turn off previous digit
		    P0 = dig3;   //set data for digit 3
			ENLED3 = 0; // Turn on digit 3
		break;
		
		case 4:
			 t=0;   // reset 4 states counter
		  
			ENLED3 = 1; //Turn off previous digit
			P0 = dig4;  //set data for digit 4
			ENLED4 = 0; // Turn on digit 4
		}
}
//
void Init_timer2(void)
{
	RCAP2H = 225;	   //  30  gives  30 Hz  or 33.33 ms  and tubes are now flickering
	
	RCAP2H = 237;	  //   18  gives   50 Hz  or 20 ms  tubes rock solid
	
	RCAP2L = 255;   // 
	
 TR2=1;	    //Start/Stop control for Timer 2. TR2 = 1 starts the timer.
 ET2=1;		 // Timer 2 interrupt enable bit.
 EA=1;		 // If  EA = 1, each interrupt source is individually enabled or disabled
           // by setting or clearing its enable bit.
}
//
void main(void)
{  
	dig1 = 0x92;  // application to place the 7 segment code into RAM
	dig2 = 0x82;
	dig3 = 0xf8;
	dig4 = 0x80;
	
 Init_timer2();//
 while(1);//  this is only a demonstration version - nothing else to do
}
