.section .rodata
.INSIRA:
	.word 0x69736e49
	.word 0x35206172
	.word 0x6d756e20
	.word 0x736f7265
	.word 0x0000203a
.SOMA:
	.word 0x6f732041
	.word 0x6420616d
	.word 0x6e20736f
	.word 0x72656d75
	.word 0xe920736f
	.word 0x0000203a
.MAIOR:
	.word 0x616d204f
	.word 0x20726f69
	.word 0x656d756e
	.word 0xe9206f72
	.word 0x0000203a
.MENOR:
	.word 0x656d204f
	.word 0x20726f6e
	.word 0x656d756e
	.word 0xe9206f72
	.word 0x0000203a

.section .text
menor:
   addi a0, zero, 0
   addi t3, zero, 1
   addi t2, zero, 4
   addi t4, sp, -20
   
   # Menor sempre vai ser a0
   addi t4, t4, 4
   lw a0, t4, -4
   
   
   lmin:
   	addi t4, t4, 4
   	lw a1,t4,-4
   	blt a0, a1, fimmin
   	add a0, zero, a1
   	fimmin:
   	SUB t2, t2, t3
	BLT zero, t2, lmin
   ret
       
maior:
   addi a0, zero, 0
   addi t3, zero, 1
   addi t2, zero, 4
   addi t4, sp, -20
   
   # Menor sempre vai ser a0
   addi t4, t4, 4
   lw a0, t4, -4
   
   
   lmax:
   	addi t4, t4, 4
   	lw a1,t4,-4
   	blt a1, a0, fimmax
   	add a0, zero, a1
   	fimmax:
   	SUB t2, t2, t3
	BLT zero, t2, lmax
   ret
	
somatorio:
   addi a0, zero, 0
   addi t3, zero, 1	
   addi t2, zero, 5
   addi t4, sp, -20
   loops:
   	addi t4, t4, 4
   	lw a1,t4,-4
   	add a0, a0, a1
   	SUB t2, t2, t3
	BLT zero, t2, loops

   ret

main:
	# Printa inserir 5 nums
	addi t0, zero, 3
	lui a0, %hi(.INSIRA)
	addi a0, a0, %lo(.INSIRA)
	addi a1, zero, 19
	ecall
	
	# Guardar os 5 valores
	addi t3, zero, 1	
	addi t2, zero, 5
	addi t4, sp, -20
	
	addi t0, zero, 4
	guardar:
	    addi t4, t4, 4
	    ecall
	    sw a0,t4,-4
	    
	    SUB t2, t2, t3
	    BLT zero, t2, guardar
	    
	# Texto soma dos numeros
	addi t0, zero, 3
	lui a0, %hi(.SOMA)
	addi a0, a0, %lo(.SOMA)
	addi a1, zero, 23
	ecall
	
	call somatorio
	addi t0, zero, 1
	ecall
	
	# Texto menor
	addi t0, zero, 3
	lui a0, %hi(.MENOR)
	addi a0, a0, %lo(.MENOR)
	addi a1, zero, 19
	ecall
	
	addi t0,zero,1
	call menor
	ecall
	
	# Texto maior
	addi t0, zero, 3
	lui a0, %hi(.MAIOR)
	addi a0, a0, %lo(.MAIOR)
	addi a1, zero, 19
	ecall
	
	addi t0,zero,1
	call maior
	ecall
	
	
	

