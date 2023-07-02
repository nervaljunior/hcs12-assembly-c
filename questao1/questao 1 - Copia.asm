ORG $4000   ; Endereço de início do programa

   ; Declaração das variáveis
   X     EQU $0000
   Y     EQU $0002
   Z     EQU $0004
   W     EQU $0006
   R     EQU $0008
   T     EQU $000A
   K     EQU $000C
   S     EQU $000E

   ; Código principal
   START:
      LDX     #PORTB     ; Endereço da PortaB
      LDAA    0,X        ; Lê valor da PortaB em A
      STAA    X          ; Armazena o valor lido em X

      LDD     #-3
      STD     Y          ; Atribui -3 a Y

      LDD     #7
      STD     Z          ; Atribui 7 a Z

      LDD     X
      LSLD
      ADDD    X
      ADDD    X
      ADDD    Y
      ADDD    Z
      STD     R          ; R = 3*X + 2*Y + Z

      LDD     R
      LSLD
      ADDD    X
      ADDD    X
      SUBD    Z
      STD     T          ; T = R + 2*X - Z

      LDD     X
      ADDD    Z
      LSLD
      STD     K          ; K = 2*(X + Z)

      LDD     K
      CMPD    T
      BGT     ELSE       ; Se K > T, pula para a parte ELSE

      LDD     Y
      LSLD
      ADDD    X
      STD     S          ; S = 2*Y + X

      LDD     S
      LDD     R
      STD     2,SP       ; Empilha R
      STD     4,SP       ; Empilha S
      JSR     FUNC_A     ; Chama a função FUNC_A
      STD     W          ; Armazena o resultado em W
      BRA     ENDIF

   ELSE:
      LDD     X
      LDD     T
      STD     2,SP       ; Empilha T
      JSR     FUNC_B     ; Chama a função FUNC_B
      STD     S          ; Armazena o resultado em S

      LDD     X
      LDD     S
      LDD     T
      STD     2,SP       ; Empilha T
      STD     4,SP       ; Empilha S
      JSR     FUNC_C     ; Chama a função FUNC_C
      STD     W          ; Armazena o resultado em W

   ENDIF:
      ; Finaliza o programa

   ; Função FUNC_A
   FUNC_A:
      PSHX               ; Salva o registrador X na pilha
      PSHA               ; Salva o registrador A na pilha

      LDD     3,SP       ; Carrega o primeiro parâmetro (parA1)
      LSLD
      ADDD    3,SP       ; Carrega o segundo parâmetro (parA2)
      ADDD    3,SP
      ADDD    3,SP
      STD     4,SP       ; Empilha o resultado intermediário

      LDD     4,SP
      LSLD
      ADDD    3,SP
      ADDD    3,SP
      ADDD    3,SP
      STD     2,SP       ; Empilha o resultado final

      PULA               ; Recupera o registrador A da pilha
      PULX               ; Recupera o registrador X da pilha
      RTS                ; Retorna da função FUNC_A

   ; Função FUNC_B
   FUNC_B:
      PSHX               ; Salva o registrador X na pilha
      PSHA               ; Salva o registrador A na pilha

      LDD     3,SP       ; Carrega o primeiro parâmetro (parB1)
      ADDD    3,SP       ; Carrega o segundo parâmetro (parB2)
      ADDD    #3         ; Adiciona 3 ao resultado intermediário
      STD     2,SP       ; Empilha o resultado final

      PULA               ; Recupera o registrador A da pilha
      PULX               ; Recupera o registrador X da pilha
      RTS                ; Retorna da função FUNC_B

   ; Função FUNC_C
   FUNC_C:
      PSHX               ; Salva o registrador X na pilha
      PSHA               ; Salva o registrador A na pilha

      LDD     3,SP       ; Carrega o primeiro parâmetro (parC1)
      ADDD    3,SP       ; Carrega o segundo parâmetro (parC2)
      ADDD    #0         ; Carrega o terceiro parâmetro (parC3)
      SUBD    3,SP
      ADDD    3,SP
      ADDD    3,SP
      STD     2,SP       ; Empilha o resultado final

      PULA               ; Recupera o registrador A da pilha
      PULX               ; Recupera o registrador X da pilha
      RTS                ; Retorna da função FUNC_C

   ; Tabela de interrupções
   ORG $FFFE
   DW START            ; Endereço de início do programa

   ; Área de variáveis
   ORG $2000

   PORTB  DS.W 1        ; Variável para armazenar o valor da PortaB

   END                 ; Fim do programa
