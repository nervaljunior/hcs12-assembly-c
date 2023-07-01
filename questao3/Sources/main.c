#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Cpu.h"
#include "Events.h"
#include "A.h"
#include "B.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"


void main(void) {
  /* put your own code here */
	    /* Write your local variable definition here */
    short valueA;
    short factorial = 1;
    
    /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
    PE_low_level_init();
    /*** End of Processor Expert internal initialization.                    ***/
    
    /* Write your code here */
    valueA = A_GetVal(); // Ler o valor da porta A
    
    if (valueA < 0) {
        // Converter o valor em complemento de dois para valor positivo
        valueA = valueA & 0xFF; // Limpar os bits de sinal (mais significativo)
        valueA = -valueA; // Inverter o sinal
    }
    
    // Calcular o fatorial do valor
    for (int i = 1; i <= valueA; i++) {
        factorial *= i;
    }
    
    B_PutVal(factorial); // Enviar o valor do fatorial para a porta B
    
    /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/

  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

