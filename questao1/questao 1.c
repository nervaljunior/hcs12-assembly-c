//Questão 1 Pede-se que seja feito um programa em assembly para HCS12 que corresponda ao programa em linguagem de alto nível a seguir: Programa em linguagem de alto nível 
void main(){  	
int X = readPortB(); 	 // X é uma variável que armazena valores inteiros lidos da PortaB   	
int Y = -3;  	
int Z = 7; 	  	
int W=0;  	
int R=0;  	
int T=0;  
	int K=0;  	
int S=0; 
R = 3*X + 2 * Y + Z; 
	T =   R +2*X - Z;   	K = 2*(X + Z); 
if(K  <= T){ 	 
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
 