/* TA-BOT:MAILTO your.email@marquette.edu your.partners.email@marquette.edu */
/* Main program template, including getInt, for ARM Playground 3.2 */
/* Marquette University 2019, Department of Computer Science */

#include <arm.h>

/* Main program starts here.  Put nothing before _main_:.  */
.section .text
.globl _main_
_main_:
        /* Function prolog.                                  */
        /* Sets up environment for user program to execute.  */
                                /* Push O/S state on Stack.  */
	push	{r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
        sub	sp, sp, #32	/* Make stack frame.  */
        /* Function prolog ends. */
        /* Start your program.   */



	ldr r0, =userPrompt
	bl kprintf
label:	bl getInt
	cmp r0, #0
	blt toosmall
	beq done

	mov r7, r0
	cmp r7, #255
	bgt next
	b label2

next:	ldr r0, =toobig
	bl kprintf
	b label	




label2:		bl toBinary
		mov r8, r0
		mov r1, r8
		ldr r0, =label1
		mov r9, r7
		mov r2, r9
		mov r3, r9
		bl kprintf
		b label
		



toosmall:
 
	ldr r0, =tooSmall
	bl kprintf
	b label 

	/* For demonstration only: print values defined in   */
	/* the .data section at the bottom of this file.     */
/*	ldr	r0, =hello
	bl	kprintf
	ldr	r0, =goodbye
	bl	kprintf */

        
	/* End of your program.         */
        /* Function epilogue.           */
        /* Restores the environment from the O/S. */
done:
        add	sp, sp, #32	/* Destroy stack frame.     */
                                /* Pop O/S state from stack.*/
	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
        bx      lr              /* Return to O/S.           */


#define MASK   r6
#define RESULT r5
#define REM    r4

toBinary:
	push    {r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}

	mov     MASK, #0x80
	mov     r3, #0xFF
	and     REM, r0, r3
	mov     RESULT, #0
toblp:  cmp     MASK, #0
	ble     tobdone

	mov     r3, #10
	mul     RESULT, RESULT, r3
	and     r0, REM, MASK
	cmp     r0, #0
	beq     tblp2
	add     RESULT, RESULT, #1
tblp2:  lsr     MASK, MASK, #1
	b       toblp

tobdone:
	mov     r0, RESULT
	pop     {r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	bx      lr


/* getInt function returns positive and negative integers */
/*  read in as ASCII characters representing base-10 values.  */
/*  Returns:    */
/*      r0 = integer */
/*      r1 = End Of File (EOF) flag, 1 (true) or 0 (false). */
#define TOTAL   r4
#define DIGIT   r5
#define SIGN    r6
#define SAW_EOF r7

getInt:
        push    {r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}

        mov     r0, #'?'        /* Print a friendly "? " prompt. */
        bl      putchar
        mov     r0, #' '
        bl      putchar
        mov     TOTAL, #0       /* Initialize variables         */
        mov     SIGN, #0
        mov     SAW_EOF, #0

        bl      getchar         /* Get first character          */
        cmp     r0, #'-'        /* IF it is a minus sign,       */
        bne     gi2             /*  THEN set SIGN = 1,          */
        mov     SIGN, #1        /*  ELSE jump into main loop.   */
        bl      putchar         /* Echo minus sign.             */

giloop:
        bl      getchar         /* Get first possible digit.    */
gi2:    cmp     r0, #4          /* If EOF, exit on special case */
				/* Note: 4 is the ASCII value   */
				/* for End of Transmission,	*/
				/* signaled by ctrl+D.		*/
        beq     gieof
        cmp     r0, #'\n'       /* If newline, then done        */
        beq     gidone          /*  reading digits.             */
        cmp     r0, #'0'        /* Check for digits between '0' */
        blt     giloop          /*  and '9'.                    */
        cmp     r0, #'9'
        bgt     giloop          /* Otherwise, ignore character  */
        mov     DIGIT, r0
        bl      putchar         /* Echo digit                   */

        sub     r0, DIGIT, #'0' /* Horner's Method to calculate */
        mov     r1, #10         /*  value of number             */
        mul     TOTAL, TOTAL, r1
        add     TOTAL, TOTAL, r0
        b       giloop

gieof:  mov     SAW_EOF, #1     /* Special case EOF flag = true */
gidone: 
        cmp     SIGN, #1        /* IF sign = 1, subtract total  */
        bne     gid2            /*  from zero to get negative   */
        mov     r1, #0
        sub     TOTAL, r1, TOTAL
gid2:
        mov     r0, #'\r'       /* Echo newline and carriage return */
        bl      putchar
        mov     r0, #'\n'
        bl      putchar
        mov     r0, TOTAL       /* Stage return values          */
        mov     r1, SAW_EOF

        pop     {r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
        bx      lr              /* Return to caller             */


/* .data section is for non-code entities, like format strings. */
/* Use .asciz, which tells the assembler to terminate the       */
/* string with a null character (zero in ASCII)                 */
.section .data
hello:			.asciz "Hello, friend!\r\n"
goodbye:		.asciz "Goodbye, friend!\r\n"
toobig:			.asciz "Try again, enter a number between 0 amd 255\r\n"
tooSmall:		.asciz "Try again, enter a number between 0 and 255\r\n"
label1:			.asciz "0b%08d, %2X, %c \r\n"
userPrompt:		.asciz "Enter a positive integer between 0 and 255\r\n"
