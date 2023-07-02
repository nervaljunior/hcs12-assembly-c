/** ###################################################################
**     Filename  : quest3mcp.c
**     Project   : quest3mcp
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 01/07/2023, 21:00
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE quest3mcp */
/*
UNIVERSIDADE FEDERAL DO MARANHÃO - UFMA
CENTRO DE CIÊNCIAS EXATAS E TECNOLOGIA - CCET
DISCIPLINA: ENGENHARIA ELÉTRICA


NERVAL DE JESUS SANTOS JUNIOR
Discente

DENIVALDO LOPES
Docente Responsável

RELATÓRIO DA UNIDADE II SOBRE HCS12

São Luís - MA
2023
*/

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PortaA.h"
#include "PortaB.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"


/*** End of Processor Expert internal initialization.                    ***/
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <math.h>
void main(void)
{
  /* Write your local variable definition here */
    /* put your own code here */
	  /* Write your local variable definition here */
  short valueA;
  short factorial = 1;
  int i;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  
    /*** End of Processor Expert internal initialization.                    ***/
    
    /* Write your code here */
    valueA = PortaA_GetVal(); // Ler o valor da porta A
    
    if (valueA < 0) {
        // Converter o valor em complemento de dois para valor positivo
        valueA = valueA & 0xFF; // Limpar os bits de sinal (mais significativo)
        valueA = -valueA; // Inverter o sinal
    }
    
    // Calcular o fatorial do valor
    for (i = 1; i <= valueA; i++) {
        factorial *= i;
    }
    PortaB_PutVal(factorial);
  
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END quest3mcp */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
