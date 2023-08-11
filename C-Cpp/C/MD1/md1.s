// md1.s - programmu asemblerā, kas aprēķina aritmētiskās progresijas summu.

    .text
    .align 2
    .global asum
    .type asum, %function

asum:
    cmp r0, #0          // n=r0
    movle r0, #0
    mov r1, #1
    mov r2, r0          // r2=n
    b test
    bx lr

loop:                   
    sub r2, r2, #1
    add r0, r0, r2

test:
    cmp r2, r1          // saskaita līdz r2 ir mazāks par r1
    bge loop
