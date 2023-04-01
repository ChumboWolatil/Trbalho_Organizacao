####################################################################
# Exerc�cio 07a (varia��o do exemplo das pags. 72/73)
# Mostra a compila��o de uma chamada simples de procedimento que
# n�o usa a pilha
####################################################################
# Trecho em C:
# int leaf_example (int g, int h, int i, int j) {
#    int f;
#    
#    f = (g + h) - (i + j);
#    return f;

      .text   # segmento de c�digo (programa)
       jal   zero, main

leaf_example:
       add a0, a2, a3   # $v0 = g + h
       add a1, a4, a5   # $v1 = i + j
       sub a0, a0, a1   # f = $t0 - $t1
 	jalr zero, ra, 0       # retorna do procedimento

main:    
       addi a2, zero, 4   # inicializa 1� par�metro (g)
       addi a3, zero, 3   # inicializa 2� par�metro (h)
       addi a4, zero, 2   # inicializa 3� par�metro (i)
       addi a5, zero, 1   # inicializa 4� par�metro (j)

       jal leaf_example     # chama o procedimento
       nop                  # n�o faz nada. $v0 tem o resultado do procedimento
