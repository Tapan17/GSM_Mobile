//Git-HUB
#include"89C51.h"
#include"LCD.h"

#define r0 P1_0
#define r1 P1_1
#define r2 P1_2
#define r3 P1_3
#define c0 P1_4
#define c1 P1_5
#define c2 P1_6
#define c3 P1_7

 unsigned int r,c;
 unsigned char key[4][4]=
 						{   
							{"54D6"},
                                                        {"21E3"},
							{"0*C#"},
							{"87U9"},
						 };
unsigned int pressed_key = 0;

unsigned char key_detect()	 
{
	int count=0;
 do {
 	  count++;
 }while(P1 == 0x0F);	
 pressed_key = P1 & 0x0f;
 c0=1;
 c1=1;
 c2=1; 
 c3=1;
 
 switch(pressed_key)
 {	 
	case 0x0E:
  	{
  		r0=0;
  		if(c0==0) { r=0; c=0;	delay(1000); break;  }
		if(c1==0) { r=0; c=1;   delay(1000); break;  }
	        if(c2==0) { r=0; c=2;	delay(1000); break;  }
		if(c3==0) { r=0; c=3;	delay(1000); break;  }		
	}	
	case 0x0D:
	{
	   r1=0;
	   if(c0==0)  { r=1; c=0;   delay(1000); break;  }
	   if(c1==0)  {	r=1; c=1;   delay(1000); break;  }
	   if(c2==0)  { r=1; c=2;   delay(1000); break;  }
	   if(c3==0)  { r=1; c=3;   delay(1000); break;  }
	}
	case 0x0B:
	{
	    r2=0;
		if(c0==0) { r=2; c=0;  delay(1000);	 break;  }
		if(c1==0) {	r=2; c=1;  delay(1000);	 break;  }
		if(c2==0) {	r=2; c=2;  delay(1000);	 break;  }
		if(c3==0) {	r=2; c=3;  delay(1000);	 break;	 }
	}
	case 0x07:
	{
		r3=0;
		if(c0==0) {	r=3; c=0;  delay(1000);	 break;  }
		if(c1==0) { r=3; c=1;  delay(1000);	 break;  }
		if(c2==0) { r=3; c=2;  delay(1000);	 break;  }
		if(c3==0) { r=3; c=3;  delay(1000);	 break;  }
	 }
	 
   }
   P1 = 0x0F;
   delay(5000); 
   return(key[c][r]);	 
}	  
void main()
{
	int flag = 0;
	 unsigned char x;
	 SetLCD();
	 //WriteData('t');  
	 while(1) 
	 {
	  	x=key_detect();
		if(flag ==0 && x == '5')
		{
			flag =1;
			x = key_detect();
		}
	  	WriteData(x);
	  	delay(40000);
	 }
}	