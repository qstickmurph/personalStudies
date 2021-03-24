#include <math.h>
#include <stdio.h>

#include "QuinnMurpheyLab1methods.h"

#define NUM_BITS 32

void displayBits(unsigned int n){
	printf("%7u =", n);
	for(int i = 1; i <= NUM_BITS; i++){
		if(i%8 == 1){
			printf(" ");
		}
		if((int) (pow((double) 2, (double) (NUM_BITS - i))) <= n){
			n -= (int) (pow((double) 2, (double) (NUM_BITS - i)));
			printf("1");	
		}else{
			printf("0");
		}
	}
	printf("\n");
}

unsigned int setKthBit(unsigned int n, int k){
	if( (n >> (k-1)) % 2 == 0)
		n += pow(2,k-1);
	return n;
}

int isPowerOfTwo(unsigned int n){
	if(n==0)
		return 0;
	
	for(int i = 1; i <= NUM_BITS; i++){
		if(n % 2 == 1){
			if(n > 1)
				return 0;
			return 1;

		}
		
		n = n >> 1;
	}
	return 0;
}

int getNoBits(unsigned int a, unsigned int b){
	int result = 0;
	for(int i = 0; i < NUM_BITS; i++){
		if((a >> i) % 2 != (b >> i) % 2){
			result++;
		}
	}
	return result;
}

unsigned int computeXor(unsigned int n){
	unsigned int result = 1;
	for(int i = 2; i<= n; i++){
		result = result^i;
	}
	return result;
}
