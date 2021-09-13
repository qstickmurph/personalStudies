#include<stdio.h>
#include<stdlib.h>

#define NUM_BITS 16

typedef struct int_ll{ // Custom LL for holding ints in a dynamically allocated fashion
    int value;
    struct int_ll *next;
} int_ll;

void printAsBinary(int in);

int main(int argc, char *argv[]){
    int_ll *llHead = NULL;
    int_ll *llRoot = NULL;

    int temp;
    while( (scanf("%d", &temp)) ){ // Loop until the user enters a 0
        if(temp == 0){
            break;
        }

        int_ll *temp_ll = malloc(sizeof(int_ll)); // Create new linked list entry
        temp_ll->value = temp;

        if(llHead == NULL){ // Initialize ll if uninitialized
            llHead = temp_ll;
            llRoot = temp_ll;
        }else{ // Otherwise, append entry
            llRoot->next = temp_ll;
            llRoot = temp_ll;
        }
    }

    for(int_ll *curr = llHead; curr != NULL; ){ // Loop over ll and run printAsBinary on each value
        printAsBinary(curr->value);
        int_ll *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}

void flipBit(int *n){ // Self explanatory: 1 -> 0 and 0 -> 1
    if(*n == 1){
        *n = 0;
    }else{
        *n = 1;
    }
}

void printAsBinary(int in){
    if( in >= 1 << (NUM_BITS - 1) || in < -(1 << (NUM_BITS -1)) ){ // Test if number can be represented as an NUM_BITS bit number
        printf("ERR: Input number too large. Please enter only numbers between %d and %d\n", (1 << (NUM_BITS - 1)) - 1, -(1 << (NUM_BITS - 1)));
        return;
    }
    int outputBits[NUM_BITS];

    if(in > 0){ // Initialize outputBits to 0s when positive
        for(int i = 0; i < NUM_BITS; i++){
            outputBits[i] = 0;
        }
    }else{ // Initialize outputBits to 1s when positive
        for(int i = 0; i < NUM_BITS; i++){
            outputBits[i] = 1;
        }
        // Then map in onto its positive complement 
        in = -in - 1;
    }
    
    int index;
    for(index = 1; index < NUM_BITS; index++){
        int value = 1 << (NUM_BITS - 1 - index); // 2 ^ (NUM_BITS - 1 - index)
        if( in >= value ){ // Check each power of two decreasing
            in -= value;
            flipBit( outputBits + index ); // Flip the bit from 0 to 1 or vice versa. This allows for the usage of the same loop for both positive and negative
        }
    }
    
    for(int i = 0; i < NUM_BITS; i++){ // Print out the outputBits array formatted
        printf("%d", outputBits[i]);
        if( (i % 4) == 3 ){
            printf(" ");
        }
    }
    printf("\n");
}
