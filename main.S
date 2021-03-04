/* TA-BOT:MAILTO your.email your.partner's.email */
/* Main program template for ARM Playground 3.2 */
/* Marquette University 2019, Department of Computer Science */

#include <arm.h>

/* Main program starts here. Put nothing before _main_:.  */
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
	
	//mov r0, #7
	//mov r1, #3
	//bl divide
	//mov r5, r1 // printnum can overide value, create backup in r5
	//bl printnum // print contents in r0
	//mov r0, r5  // move remainder to r0
	//bl printnum  // print remainder in r0
//---------------------------------------------------------

//Question 1
	/*
	bl getnum
	ldr r6, =6895
	ldr r7, =1000
	mul r5, r0, r6
	mov r0, r5
	mov r1, r7
	bl divide
	bl printnum
	*/
//---------------------------------------------------------

//Question 2
	bl getnum
	add r6, r0, r6
	bl getnum
	add r6, r0, r6
	bl getnum
	add r6, r0, r6
	bl getnum 
	add r6, r0, r6
	bl getnum
	add r6, r0, r6
	bl getnum
	add r6, r0, r6
	bl getnum
	add r6, r0, r6
	bl getnum
	add r6, r0, r6
	bl getnum
	add r6, r0, r6
	bl getnum
	add r6, r0, r6
	mov r0, r6
	bl printnum



//----------------------------------------------------------------



//---------------------------------------------------------
	//mov r0, #1
	//mov r3, #2
	//MOV r3, #0
	//b TEST

//LOOP: add r0, r0, r1
	//add r3, r3, #1
//TEST: cmp r3, #2
	//blt LOOP
	//bl printnum
        /* End of your program.         */
        /* Function epilogue.           */
        /* Restores the environment from the O/S. */
done:
        add	sp, sp, #32	/* Destroy stack frame.     */
        /* Pop O/S state from stack.*/
	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
        bx      lr              /* Return to O/S.           */
