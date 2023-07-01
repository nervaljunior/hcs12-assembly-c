/** ###################################################################
**     Filename  : HelloWorld_C.c
**     Project   : HelloWorld_C
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 30/06/2023, 18:30
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE HelloWorld_C */
//meu nome é Nerval Junior

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"


/* User includes (#include below this line is not maintained by Processor Expert) */
#include <math.h>
float x1, x2,delta;
float a,b,c;
float x1Imag, x2Imag;

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  x1=0;
  x2=0;
  delta=0;
  x1Imag=0;
  x2Imag=0;
  a=PORTA;
  b=PORTB;
  c=PTT;
  
  // função do delta da equação do segundo grau
  delta=b*b - 4*a*c;
  if(delta ==0){
  // raizes reais iguais
      x1=((float)-b)/(2.0*a);
      x2=x1;
  }else if(delta > 0){
      x1= (-b +  sqrtf(delta))/(2.0f*a);
      x2= (-b -  sqrtf(delta))/(2.0f*a);
  
  }else{
      x1= (-b)/(2.0f*a);
      x2= (-b)/(2.0f*a);
      x1Imag= -(sqrtf(delta))/(2.0f*a);
      x2Imag= (sqrtf(delta))/(2.0f*a);
  
  
  }
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
  } /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END HelloWorld_C */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/

