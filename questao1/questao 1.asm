 //Solução do problema em Assembly 
 ;Include derivative-specific definitions

INCLUDE 'derivative.inc' 
XREF MCU_init 
;export symbols 
XDEF Entry, _Startup, main 
;we use export 'Entry' as symbol. This allows us to 
;reference 'Entry' either in the linker .prm file 
;or from C/C++ later on 
XREF __SEG_END_SSTACK ; symbol defined by the linker for the end of the stack 
;variable/data section 
MY_EXTENDED_RAM: SECTION 
;Insert here your data definition. 
varX ds.W 1 
vary ds.W 1 
varZ ds.W 1 
varW ds.W 1 
varR ds.W 1 
varT ds.W 1 
varK ds.W 1 
varS ds.W 1 
aux1 ds.W 1 
aux2 ds.W 1 
;code section 
MyCode: SECTION 
main: 
_Startup: 
Entry: 
LDS #__SEG_END_SSTACK ; initialize the stack pointer 
; Call generated Device Initizalization function 
CLI ; enable interrupts 
CALL MCU_init

INICIO: MOVW #$08,varX ; move 0x08 para varX 
MOVW #$02,varY ; move 0x02 para varY 
MOVW #$06,varZ ; move 0x06 para varZ 
MOVW #$00,varW ; move 0x00 para varW 
MOVW #$00,varR ; move 0x00 para varR 
MOVW #$00,varT ; move 0x00 para varT 
MOVW #$00,varK ; move 0x00 para varK 
MOVW #$00,varS ; move 0x00 para varS 
; R = 3*X + 2*Y - Z 
LDY #$03 ; carrega 0x03 em Y 
LDD varX ; carrega varX em D 
EMULS ; multiplica valor de D(varX) com Y 
STD varR ; move D que contém resultado para varR 
LDY #$02 ; carrega 0x02 em Y 
LDD varY ; carrega varY em D 
EMULS ; D <= multiplica valor de D(varY) com Y 
ADDD varR ; D <= adiciona varR com o valor de D 
STD varR ; move D que contém resultado para varR 
SUBD varZ ; D <= D(varR)- varZ 
STD varR ; move D que contém resultado para varR 
; T = Z + 5*R 
LDY #$05 ; carrega 0x05 em Y 
LDD varR ; carrega varR em D 
EMULS ; D <= multiplica valor de D(varR) com Y 
STD varT ; move D que contém resultado para varT 
LDD varZ ; carrega D de varZ 
ADDD varT ; D <= D(varZ)+ varT 
STD varT ; move D que contém resultado para varT 
; K = 6*X + 2* Z 
LDY #$06 ; carrega 0x06 em Y

LDD varX ; carrega varX em D 
EMULS ; multiplica valor de D(varX) com Y 
STD varK ; move D que contém resultado para varK 
LDY #$02 ; carrega 0x02 em Y 
LDD varZ ; carrega varZ em D 
EMULS ; D <= multiplica valor de D(varZ) com Y 
ADDD varK ; D <= adiciona varK com o valor de D 
STD varK ; move D que contém resultado para varK 
; Compara K < T 
LDD varT ; carrega varT em D 
CPD varK 
BGT then1 
else1: 
; S = 2*T + 4 
LDY #$02 ; carrega 0x02 em Y 
LDD varT ; carrega varT em D 
EMULS ; D <= multiplica valor de D(varT) com Y 
STD varS ; move D que contém resultado para varS 
LDD #$04 ; carrega D com #$04 
ADDD varS ; D <= D(#$04)+ varS 
STD varS ; move D que contém resultado para varS 
;FuncB 
MOVW varS, aux1 ; aux1 <- VarS; 
MOVW varT, aux2 ; aux2 <- VarT; 
CALL funcB 
LDD aux1 ; D <= aux1(resposta da funcao) 
STD varW ; varW<= D 
BRA fim1 then1: 
; S = 3*T + Y

LDY #$03 ; carrega 0x03 em Y 
LDD varT ; carrega varT em D 
EMULS ; D <= multiplica valor de D(varT) com Y 
STD varS ; move D que contém resultado para varS 
LDD varY ; carrega D de varY 
ADDD varS ; D <= D(varY)+ varS STD varS ; move D que contém resultado para varS ;FuncA 
MOVW varS, aux1 ; aux1 <- VarS; 
MOVW varR, aux2 ; aux2 <- VarR; 
CALL funcA 
LDD aux1 ; D <= aux1(resposta da funcao) 
STD varW ; varW<= D 
BRA fim1 
funcA: 
LDY #$08 ; carrega 0x08 em Y 
LDD aux2 ; carrega aux2 em D 
EMULS ; D <= multiplica valor de D(aux2) com Y 
ADDD aux1 ; D <= D+ aux1 
STD aux1 ; move D que contém resultado para aux1 
RTC 
NOP 
funcB: 
LDD aux1 ; D <= aux1 
SUBD aux2 ; D <= D(aux1)-aux2; 
STD aux1 ; move D que contém resultado para aux1 
RTC 
NOP fim1: 
NOP 
BRA fim1