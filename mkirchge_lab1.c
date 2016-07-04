#include <stdio.h>
#include <ctype.h>

/*
	ICS 51, Lab #1
	
	-----------------------------------------------------------------

	PART I: 

	Given a 32-bit integer, swap all odd bits with even bits. 
	For example, if the given number is 23 (00010111), it should be 
	converted to 43 (00101011). Every even position bit is swapped 
	with adjacent bit on right side, and every odd position bit is 
	swapped with adjacent on left side.

	Implementation details:
	The input integer is stored in registers ebx. You need to store the 
	answer into register eax.

	Hint: 
	You only need a half-dozen instructions to do this. 
	Think about "clearing" odd (even) bits and using shift (shl, shr) 
	instructions.
	
	If we have an 8-bit number 00010111, the expected output is 00101011.
	Clearing (zeroing) odd bits (7, 5, 3, 1) of 00010111 would make it 
	00010101. Now if we shift it to the left by one bit, it becomes 
	00101010. The odd bits of 00101010 are equal to the odd bits of the 
	expected output. They are "0 1 1 1".

	Using the same technique, generate the even bits of the expected 
	output and then figure out a way for combining generated odd and 
	even bits. 

	-----------------------------------------------------------------

	PART II: 
	
	You are given three integers. You need to add the smallest 
	number to the largest number and multiply that sum by two. You 
	cannot use mul/imul instructions.

	Implementation details:
	The three integers are stored in registers eax, ebx, and ecx. You 
	need to store the answer into register eax.

	Hint:
	One way of finding minimum and maximum number is to sort the numbers.

	-----------------------------------------------------------------

	IMPORTATNT NOTES:
	
	- To test your code see the "testcode" function in lab1-testing.c
	
	- Write your assembly code only in the marked blocks.
	
	- Do NOT change anything outside the marked blocks.
	
	- For part II, you are NOT allowed to use any version of the 
      MULTIPLY instruction!
	
	- Remember to fill in your name, student ID below.

	- This lab has to be done individually.
	
	- Submit ONLY lab1.c file for grading.

*/

char *yourName = " Maximillian Kirchgesner ";
char *yourStudentID = " 27238431 ";

/* Implement the body of this function for part I*/
int swapBits(int x)
{
	int result;

	__asm 
	{
		push ebx
		push edi
		push esi

		mov ebx, x

// YOUR CODE STARTS HERE

mov edx, ebx
and ebx, 0xAAAAAAAA
shr ebx, 1
and edx, 0x55555555
shl edx, 1
xor ebx, edx
mov eax, ebx

	
// YOUR CODE ENDS HERE
 
        mov result, eax

        pop esi
		pop edi
		pop ebx
	}
	return result;

}

/* Implement the body of this function for part II*/
void doubleMax(int a, int b, int c, int *result)
{
	__asm 
	{
		push ebx
		push edi
		push esi

		mov esi, result

		mov eax, a
		mov ebx, b
		mov ecx, c

// YOUR CODE STARTS HERE

mov edx, eax // store a into another variable
cmp ebx, edx // compare a and b for max
jl IF // if a>b
mov edx, ebx // otherwise store b in edx
IF:        // compare (a or b) and c for max
cmp ecx, edx
jl ELSEIF
mov edx, ecx
ELSEIF:       // compare a and b for min
cmp ebx, eax
jg ELSEIFTWO
mov eax, ebx
ELSEIFTWO:        // compare (a or b) and c for min
cmp ecx, eax
jg ELSEIFTHREE
mov eax, ecx
ELSEIFTHREE:
add eax, edx // add the min and max together
add eax, eax // then double the answer
	
// YOUR CODE ENDS HERE

		mov [esi][0], eax

        pop esi
		pop edi
		pop ebx
	}

	return;
}