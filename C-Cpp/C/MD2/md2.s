@ md2.s - matrix multiplicaton

    .text
    .align 2
    .global matmul
    .type matmul, %function

matmul:

    @ STMFD sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}

    str fp, [sp, #-4]!
    add fp, sp, #0
    sub sp, sp, #32

    @ 1. Parameters

    str r0, [fp, #-8]           @ h1
    str r1, [fp, #-12]          @ w1
    str r2, [fp, #-16]          @ m1 address
    str r3, [fp, #-20]          @ h2

    @ ldr r4, [fp, #4]          @ w2
    @ ldr r5, [fp, #8]          @ m2 address
    @ ldr r6, [fp, #12]         @ m3 address

    
    cmp r1, r3                  @ compare w1=h2
    bne badend                  @ if not equal, send to bad end

    mov r2, r1                  @ w1/h2

    @ 2. matrix 3 dimensions    @ r0 <- h3, r1 <- w3
    ldr r1, [fp, #4]            @ w2 = w3 -> r1
    
    mov r4, #4

    mul r0, r4, r0              @ h3 * 4
    mul r1, r4, r1              @ w3 * 4
    mov r12, r1
    mul r2, r4, r2              @ w1/h2 * 4

    str r1, [fp, #-24]          @ w3 * 4
    str r2, [fp, #-28]          @ h2 * 4

    @ mov r2, r1                  @ for inner loop to be able to start from the beggining == w3 * 4

    @ 3. find m1, m2 and m3 starting points, put in registers to use
    ldr r3, [fp, #-16]          @ m1
    ldr r4, [fp, #8]            @ m2
    mov r9, r4                  @ to reset r4
    ldr r5, [fp, #12]           @ m3

    @ 4. multiply m1 and m2

    mov r8, #0
    mov r10, #0


    b loop

end:
    add sp, fp, #0
    ldr fp, [sp], #4
    @ LDMFD sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, pc}
    
    bx lr

goodend:
    mov r0, #0
    b end

badend:
    mov r0, #1
    b end

before:                     @ set matrix 1 next row and reset parameters
    add r3, r3, r2
    str r3, [fp, #-16]      @ change and store address of matrix 1 new row
    ldr r1, [fp, #-24]      @ w3 loop counter reset
    ldr r2, [fp, #-28]      @ w1/h2 loop counter reset
    ldr r4, [fp, #8]        @ resets matrix 2 to starting point
    ldr r9, [fp, #8]        @ helper parameter to help with r4 (matrix 2 to starting point)
                            @ to get matrix 2 columns properly

    mov r8, #0  
    mov r10, #0

    b loop

loop:                       @ h3 loop
    cmp r0, #0              @ if (h3 > 0)
    ble goodend             @ else
    
    sub r0, r0, #4

    b loop2

wr:                         @ Write and reset some parameters
    str r8, [r5, #0]        @ passed int stored in matrix 3
    add r5, r5, #4          @ move to next address

    add r9, r9, #4          @ next column starting point for matrix 2
    mov r4, r9

    mov r8, #0
    mov r10, #0

    ldr r2, [fp, #-28]

    sub r1, r1, #4
    b loop2


loop2:                      @ w3 loop
    ldr r3, [fp, #-16]      
    cmp r1, #0              @ if (w3 > 0)
    ble before              @ else

    b loop3

loop3:                      @ w1/h2 loop
    cmp r2, #0              @ if (w1/h2 > 0)
    ble wr                  @ else

    sub r2, r2, #4
    
    ldr r6, [r3, #0]        @ m1 element
    add r3, r3, #4
    ldr r7, [r4, #0]        @ m2 element
    add r4, r4, r12

    mul r10, r7, r6         @ m1 elem * m2 elem
    add r8, r8, r10         @ sum += m1 elem * m2 elem

    b loop3

