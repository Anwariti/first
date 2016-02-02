/*
 * main.c
 *
 *  Created on: Feb 2, 2016
 *      Author: Anwar
 */
#include"types.h"
#include"DIO_interface.h"
#include"Delay.h"


void blink1();
void blink2();
void blink3();
void blink4();
void blink5();
void blink6();

int main() {
	while (1) {
		//DIO_u8WritePortDir(DIO_u8PORT1, DIO_u8PORTOUTPUT);
		//DIO_u8WritePortVal(DIO_u8PORT1, 0xFF);

//blink2();
//blink1();
//blink3();
//blink4();
//blink5();
blink6();

	}
	return 0;
}

void blink1(){
	DIO_u8WritePortDir(DIO_u8PORT1, DIO_u8PORTOUTPUT);
	DIO_u8WritePortVal(DIO_u8PORT1, 0xAA);
	Delay(70);
	DIO_u8WritePortVal(DIO_u8PORT1, 0x55);
	Delay(70);
}

void blink2(){
	DIO_u8WritePortDir(DIO_u8PORT1, DIO_u8PORTOUTPUT);
	DIO_u8WritePortVal(DIO_u8PORT1, 0x00);
	Delay(70);
	DIO_u8WritePortVal(DIO_u8PORT1, 0xFF);
	Delay(70);
}



void blink3(){
	DIO_u8WritePortDir(DIO_u8PORT1, DIO_u8PORTOUTPUT);
	DIO_u8WritePortVal(DIO_u8PORT1, 0x0F);
	Delay(70);
	DIO_u8WritePortVal(DIO_u8PORT1, 0xF0);
	Delay(70);
}

void blink4(){
u8 x=1;
u8 y=128;
DIO_u8WritePortDir(DIO_u8PORT1, DIO_u8PORTOUTPUT);

for(u8 i=0;i<8;i++)
{
	DIO_u8WritePortVal(DIO_u8PORT1, x);
	x=x<<1;
	Delay(20);
}

for(u8 i=0;i<8;i++)
{
DIO_u8WritePortVal(DIO_u8PORT1, y);
	Delay(20);
	y=y>>1;
}
}

void blink5(){
u8 old_x=0;

DIO_u8WritePortDir(DIO_u8PORT1, DIO_u8PORTOUTPUT);

for(u8 i=0;i<8;i++)
{
	old_x=old_x*2+1;
	DIO_u8WritePortVal(DIO_u8PORT1, old_x);
	Delay(20);
}
}


void blink6(){
u8 old_x=0;
u8 old_x2=128;

DIO_u8WritePortDir(DIO_u8PORT1, DIO_u8PORTOUTPUT);

for(u8 i=0;i<4;i++)
{
	old_x=old_x*2+1;
	DIO_u8WritePortVal(DIO_u8PORT1, old_x2|old_x);
	old_x2|=(old_x2/2);
	Delay(20);
}
}




//DIO_voidInit();
/*
DIO_u8WritePortDir(DIO_u8PORT1, DIO_u8PORTOUTPUT);

DIO_u8WritePortVal(DIO_u8PORT1, 0xAA);
Delay(100);

DIO_u8WritePortVal(DIO_u8PORT1, 0x55);
Delay(100);
*/
/*
DIO_u8WritePinDir(8,1);
 DIO_u8WritePinDir(10,1);

 DIO_u8WritePinVal(8,1);
 DIO_u8WritePinVal(10,0);
 Delay(100);
 DIO_u8WritePinVal(8,0);
		 DIO_u8WritePinVal(10,1);
		 Delay(100);
*/


//DIO_u8WritePinDir(16,0);
//DIO_u8WritePinDir(17,0);
/*
DIO_u8WritePinDir(8,1);
DIO_u8WritePinDir(10,1);
DIO_u8WritePortDir(2,0xFF);
DIO_u8WritePortVal(DIO_u8PORT2, 0xFF);
  u8 check_1=0;
  u8 check_2=0;
  DIO_u8ReadPinVal(16,&check_1);
  DIO_u8ReadPinVal(17,&check_2);
  DIO_u8WritePinVal(10,check_1);
  */
