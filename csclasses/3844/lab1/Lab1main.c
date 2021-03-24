#include <stdio.h>
#include "QuinnMurpheyLab1methods.h"

int main()
{
	unsigned int x = 0;
	unsigned int y = 0;
	int i;

	printf("Test 1:\n");
	displayBits(x);
	
	printf("Test 2:\n");
	x = setKthBit(x,10);
	displayBits(x);
	y = setKthBit(y,20);
	displayBits(y);
	
	printf("Test 3:\n");
	printf("%7u power of 2? %d\n",x,isPowerOfTwo(x));
	printf("%7u power of 2? %d\n",y,isPowerOfTwo(y));
	
	printf("Test 4:\n");
	x = setKthBit(x,5);
	y = setKthBit(y,5);
	displayBits(x);	
	displayBits(y);
	printf("%7u power of 2? %d\n",x,isPowerOfTwo(x));
	printf("%7u power of 2? %d\n",y,isPowerOfTwo(y));
	
	printf("Test 5:\n");
	x = setKthBit(x,1);
	y = setKthBit(y,4);
	x = setKthBit(x,3);
	y = setKthBit(y,1);
	displayBits(x);
	displayBits(y);
	printf("%7d bits convert %u to %u\n",getNoBits(x,y),x,y);
	
	printf("Test 6: XOR of all numbers 1..5\n");
	x = computeXor(5);
	displayBits(x);
	
	printf("Test 7: XOR of all numbers 1..33\n");
	x = computeXor(33);
	displayBits(x);
	
	printf("Test 8:\n");
	x = 122;
	y = 60;
	displayBits(x);
	displayBits(y);
	printf("%7d bits convert %u to %u\n",getNoBits(x,y),x,y);
	
	printf("Test 9:\n");
	printf("%7u power of 2? %d\n",0,isPowerOfTwo(0));
	
	printf("Test 10:\n");
	x=0;
	for (i=1; i<=16;i++)
	  x = setKthBit(x,i);
	displayBits(x);
}


