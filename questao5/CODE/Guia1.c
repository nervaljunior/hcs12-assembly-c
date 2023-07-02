/** ###################################################################
**     Filename  : tanque.c
**     Project   : tanque
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 19/04/2023, 14:13
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE tanque */

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
#include "I.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "E.h"
#include "Erro.h"
#include "S.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

int valueE;
int valueS;
int error;
void main(void)
{
  /* Write your local variable definition here */
  int SYSTEM;
  int valueSensorA;
  int valueSensorB;
  int valueSensorC;
  int valueSensorD;
  
   
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  while(1)
  {
    SYSTEM = I_GetVal();
    valueSensorA = A_GetVal();
    valueSensorB = B_GetVal();
    valueSensorC = C_GetVal();
    valueSensorD = D_GetVal();
    
    if(!SYSTEM){
    if ((((!valueSensorA && !valueSensorB && !valueSensorD) || (!valueSensorA && valueSensorC && !valueSensorD))) != 0)
    {
      E_ClrVal();
    }
    else
    {
      E_SetVal();
    }
   
    if ((valueSensorB && valueSensorC && !valueSensorD) != 0)
    {
      S_ClrVal();
    }
    else
    {
      S_SetVal();
    }
   
    if ((valueSensorD || (valueSensorB && !valueSensorC) || (valueSensorA && !valueSensorB)) != 0)
    {
      Erro_ClrVal();
    }
    else
    {
      Erro_SetVal();
    }
  }
  }
   
    

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
}
