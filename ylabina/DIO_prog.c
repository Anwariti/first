/*
 * DIO_prog.c
 *
 *  Created on: Jan 27, 2016
 *      Author: Anwar
 */

#include "types.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_private.h"



/*comment!:read port value*/
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx,u8* Copy_u8PtrVal)
{
	u8 local_u8Error;

	switch(Copy_u8PortIdx){
case 0:
	local_u8Error=DIO_u8OK;
	*Copy_u8PtrVal=PINA;
	break;
case 1:
	local_u8Error=DIO_u8OK;
	*Copy_u8PtrVal=PINB;
	break;
case 2:
	local_u8Error=DIO_u8OK;
	*Copy_u8PtrVal=PINC;
	break;
case 3:
	local_u8Error=DIO_u8OK;
	*Copy_u8PtrVal=PIND;
	break;
default:
	local_u8Error=DIO_u8ERROR;
	break;
}

	return local_u8Error;
}


/*comment!:write to port*/
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx,u8 Copy_u8PortVal)
{
	u8 local_u8Error;

	switch(Copy_u8PortIdx){
case 0:
	local_u8Error=DIO_u8OK;
	PORTA=Copy_u8PortVal;
	break;
case 1:
	local_u8Error=DIO_u8OK;
	PORTB=Copy_u8PortVal;
	break;
case 2:
	local_u8Error=DIO_u8OK;
	PORTC=Copy_u8PortVal;
	break;
case 3:
	local_u8Error=DIO_u8OK;
	PORTD=Copy_u8PortVal;
	break;
default:
	local_u8Error=DIO_u8ERROR;
	break;
}

	return local_u8Error;
}




extern void DIO_voidInit(void)
{
	DDRA=DIO_u8PORTA_DIR;
	DDRB=DIO_u8PORTB_DIR;
	DDRC=DIO_u8PORTC_DIR;
	DDRD=DIO_u8PORTD_DIR;

	PORTA|=(DIO_u8PORTA_DIR&DIO_u8PORTA_VAL);  //zeroing must happen to output before oring
	PORTB|=(DIO_u8PORTB_DIR&DIO_u8PORTB_VAL);
	PORTC|=(DIO_u8PORTC_DIR&DIO_u8PORTC_VAL);
	PORTD|=(DIO_u8PORTD_DIR&DIO_u8PORTD_VAL);
}


extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx,u8 Copy_u8PinVal)
{
	u8 local_u8Error;
	u8 local_u8Portno=Copy_u8PinIdx/PIN_PER_PORT;
	u8 local_u8Pinno=Copy_u8PinIdx%PIN_PER_PORT;

	switch(local_u8Portno){
case 0:
	local_u8Error=DIO_u8OK;
PORTA=assignbit(PORTA,local_u8Pinno,Copy_u8PinVal);
	break;
case 1:
	local_u8Error=DIO_u8OK;
	PORTB=assignbit(PORTB,local_u8Pinno,Copy_u8PinVal);

	break;
case 2:
	local_u8Error=DIO_u8OK;
	PORTC=assignbit(PORTC,local_u8Pinno,Copy_u8PinVal);
	break;
case 3:
	local_u8Error=DIO_u8OK;
	PORTD=assignbit(PORTD,local_u8Pinno,Copy_u8PinVal);
	break;
default:
	local_u8Error=DIO_u8ERROR;
	break;
}

	return local_u8Error;
}


extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx,u8* Copy_u8PtrVal)
{
	u8 local_u8Error;
	u8 local_u8Portno=Copy_u8PinIdx/PIN_PER_PORT;
	u8 local_u8Pinno=Copy_u8PinIdx%PIN_PER_PORT;

	switch(local_u8Portno){
case 0:
	local_u8Error=DIO_u8OK;
	*Copy_u8PtrVal=getbit(PINA,local_u8Pinno);
	break;
case 1:
	local_u8Error=DIO_u8OK;
	*Copy_u8PtrVal=getbit(PINB,local_u8Pinno);
	break;
case 2:
	local_u8Error=DIO_u8OK;
	*Copy_u8PtrVal=getbit(PINC,local_u8Pinno);
	break;
case 3:
	local_u8Error=DIO_u8OK;
	*Copy_u8PtrVal=getbit(PIND,local_u8Pinno);
	break;
default:
	local_u8Error=DIO_u8ERROR;
	break;
}

	return local_u8Error;
}


/*comment!:write port direction*/
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx,u8 Copy_u8PortDir)
{
	u8 local_u8Error;
switch(Copy_u8PortIdx){
case 0:
	local_u8Error=DIO_u8OK;
	DDRA=Copy_u8PortDir;
	break;
case 1:
	local_u8Error=DIO_u8OK;
	DDRB=Copy_u8PortDir;
	break;
case 2:
	local_u8Error=DIO_u8OK;
	DDRC=Copy_u8PortDir;
	break;
case 3:
	local_u8Error=DIO_u8OK;
	DDRD=Copy_u8PortDir;
	break;
default:
	local_u8Error=DIO_u8ERROR;
	break;
}

	return local_u8Error;
}


extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx,u8* Copy_u8PortDir)
{
	u8 local_u8Error;
switch(Copy_u8PortIdx){
case 0:
	local_u8Error=DIO_u8OK;
	*Copy_u8PortDir=DDRA;
	break;
case 1:
	local_u8Error=DIO_u8OK;
	*Copy_u8PortDir=DDRB;
	break;
case 2:
	local_u8Error=DIO_u8OK;
	Copy_u8PortDir=DDRC;
	break;
case 3:
	local_u8Error=DIO_u8OK;
	*Copy_u8PortDir=DDRD;
	break;
default:
	local_u8Error=DIO_u8ERROR;
	break;
}

	return local_u8Error;
}


/*comment!:write pin direction*/
extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx,u8* Copy_u8PinDir)
{
	u8 local_u8Error;
	u8 local_u8Portno=Copy_u8PinIdx/PIN_PER_PORT;
	u8 local_u8Pinno=Copy_u8PinIdx%PIN_PER_PORT;

	switch(local_u8Portno){
case 0:
	local_u8Error=DIO_u8OK;
	*Copy_u8PinDir=getbit(DDRA,local_u8Pinno);
	break;
case 1:
	local_u8Error=DIO_u8OK;
	*Copy_u8PinDir=getbit(DDRB,local_u8Pinno);

	break;
case 2:
	local_u8Error=DIO_u8OK;
	*Copy_u8PinDir=getbit(DDRC,local_u8Pinno);
	break;
case 3:
	local_u8Error=DIO_u8OK;
	*Copy_u8PinDir=getbit(DDRD,local_u8Pinno);
	break;
default:
	local_u8Error=DIO_u8ERROR;
	break;
}

	return local_u8Error;
}








