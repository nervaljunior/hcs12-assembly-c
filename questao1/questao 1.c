#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */


void MCU_init(void); /* Device initialization function declaration */
int funcA(int parA1, int parA2); /* Protótipo da função funcA */
int funcB(int parB1, int parB2); /* Protótipo da função funcB */
int funcC(int parC1, int parC2, int parC3); /* Protótipo da função funcC */

void main(void) {
  MCU_init(); /* call Device Initialization */
  /* put your own code here */
int X,Y,Z,W,R,T,K,S;  
X = PortB; 	 // X é uma variável que armazena valores inteiros lidos da PortaB   	
Y = -3;  	
Z = 7; 	  	
W=0;  	
R=0;  	
T=0;  
K=0;  	
S=0; 
R = 3*X + 2 * Y + Z; 
T =   R +2*X - Z;
K = 2*(X + Z); 
if(K <= T){ 	 
	 	S = 2 * Y + X; 
 	    W= funcA(S,R);  
	}else { 
	 	S = funcB(X,T); 
 	 	W = funcC(X,S,T); 
 	} 
}  

int funcA(int parA1, int parA2){  	 			
      return 3* parA1 + parA2; 
} 

int funcB(int parB1, int parB2){ 
		return parB1 +  parB2 + 3; 
} 
 
int funcC(int parC1, int parC2, int parC3){ 
 	 	return 2*parC1 + parC2 - parC3; 
} 
 



  for(;;) {
    /* _FEED_COP(); by default, COP is disabled with device init. When enabling, also reset the watchdog. */
  } /* loop forever */
  /* please make sure that you never leave main */





//aqui eu vou comparar o codigo que eu vou insirir 
//Questão 1 Pede-se que seja feito um programa em assembly para HCS12 que corresponda ao programa em linguagem de alto nível a seguir: Programa em linguagem de alto nível 
