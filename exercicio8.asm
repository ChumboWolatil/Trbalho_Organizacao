####################################################################
# Exercício 08 - Patterson pag. 74
# Mostra a compilação de um procedimento que chama outro, neste caso,
# o fatorial recursivo
####################################################################
# Trecho em C:
# int fact (int n) {
#    if (n<1)
#        return 1;
#    else
#        return (n * fact(n-1));
#
.text
j main

fat_rec:
	#coloca na pilha todos os valores antes
	#de começar a calcular
	addi sp, sp, -8 
	sw   ra, 0(sp)
	sw   a0, 4(sp)
	
	#verifica se vai retornar 1 ou n-1
	addi t0, t0, 1
	bge a0, t0, ret_n1
	
	#retorna 1
	addi a1, zero, 1
	jr ra

	#chama o fatorial de n-1
	ret_n1:
	addi a0, a0, -1
	jal fat_rec

	#desempilha até o final multiplicando os valores
	#de n que foram armazenados
	lw a0, 4(sp)
	lw ra, 0(sp)
	addi sp, sp, 8

	mul a1, a1, a0
	jr ra


main:

addi a0, zero, 5 #n=4
jal fat_rec      #fat(n)

addi a7, zero, 1
add a0, zero, a1
ecall
