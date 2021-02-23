#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursPass(char characters[], int depth, int *numChar, int *maxLength, char passStr[]){
	
	for(int i = 0;  i < depth; ++i){
		printf("%c", passStr[i]);
	}
	printf("\n");
	
	if(depth < *maxLength){
		for(int i = 0; i < *numChar; ++i){
			passStr[depth] = characters[i];
			recursPass(characters, depth + 1, numChar, maxLength, passStr);
		}
	}
}

int main(int argc, char *argv[]){
	
	printf("Setting numChar\n");
	int numChar = atoi(argv[1]);
	
	char characters[numChar];
	printf("Setting characters\n");
	for(int i = 0; i < numChar; ++i){
		characters[i] = *argv[2+i];
	}
	printf("Setting maxLength to ");
	int maxLength = atoi(argv[argc - 1]);
	printf("%d\n", maxLength);
	char passStr[maxLength];

	printf("Running recursPass\n");

	recursPass(characters, 0, &numChar, &maxLength, passStr);

	return 0;
}
