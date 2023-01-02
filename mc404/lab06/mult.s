.section .text

main:
	# le t1
    	addi t0,zero,4
    	ecall
    	add t1,zero,a0
    	
    	# le t2
    	ecall
    	add t2,zero,a0
    	
	addi t3,zero,1	# valor menos 1
	addi a0,zero,0
	
loop:
	add a0,a0, t1
	SUB t2, t2, t3
	BLT zero, t2, loop
	
	# end loop
exit:
	addi t0,zero,1  # impressao de inteiro - t0=1 e a0 o inteiro

	ecall   # chamada de rotina de sistema

	jr ra
