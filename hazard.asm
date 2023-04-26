#hazard01: código com conflito de dados ao considerar execução em pipeline

.data
	vetor: .word 0,0,0,0,0,0,0,0
.text
	la 		s0, vetor
	addi	s8, s8, 8 # tamanho vetor = 8
	addi	t0, zero, 0 # i=0
for:
	beq		t0, s8, fim_for
	slli 	t1, t0, 2 #4*i
	add 	t1, t1, s0 #4*i + endereço base
	sw 		t0, 0(t1) #vetor[i]=i
	addi	t0, t0, 1
	jal 	zero, for

fim_for:
	addi 	a7, zero, 10
	ecall	