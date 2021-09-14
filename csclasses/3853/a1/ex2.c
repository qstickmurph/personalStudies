#include<stdio.h>
#include<stdlib.h>

#define NUM_BITS 4

void readBinaryInput(int bin[]);
void printBinary(int bin[]);
void convertToBinary(int dec, int bin[]);
int convertToDecimal(int bin[]);
int add(int num1[], int num2[], int res[]);

int main(int argc, char *argv[]){
    char input;
    int num1Dec;
    int num2Dec;

    int num1Bin[NUM_BITS];
    int num2Bin[NUM_BITS];
    int result[NUM_BITS];

    printf("Would you like your inputs to be in (a) binary or (b) decimal?\n");
    scanf(" %c", &input);
    if( input == 'a' ){
        printf("num1 (bin) = ");
        readBinaryInput(num1Bin);
        num1Dec = convertToDecimal(num1Bin);
        printf("num1 (dec) = %d\n\n", num1Dec);

        printf("num2 (bin) = ");
        readBinaryInput(num2Bin);
        num2Dec = convertToDecimal(num2Bin);
        printf("num2 (dec) = %d\n\n", num2Dec);

    }else {
        printf("num1 (dec) = ");
        scanf("%d", &num1Dec);
        if( num1Dec >= 1 << (NUM_BITS - 1) || num1Dec < -(1 << (NUM_BITS -1)) ){
            printf("ERR: Input number too large. Please enter only numbers between %d and %d\n", (1 << (NUM_BITS - 1)) - 1, -(1 << (NUM_BITS - 1)));
            return 1;
        }else{
            convertToBinary(num1Dec, num1Bin);
            printf("num1 (bin) = ");
            printBinary(num1Bin);
            printf("\n");
        }

        printf("num2 (dec) = ");
        scanf("%d", &num2Dec);
        if( num2Dec >= 1 << (NUM_BITS - 1) || num2Dec < -(1 << (NUM_BITS -1)) ){
            printf("ERR: Input number too large. Please enter only numbers between %d and %d\n", (1 << (NUM_BITS - 1)) - 1, -(1 << (NUM_BITS - 1)));
            return 1;
        }else{
            convertToBinary(num2Dec, num2Bin);
            printf("num2 (bin) = ");
            printBinary(num2Bin);
            printf("\n");
        }
    }

    int overflow = add(num1Bin, num2Bin, result);

    printf("res  (bin) = ");
    printBinary(result);
    printf("res  (dec) = %d\n", convertToDecimal(result));
    printf("\n");
    
    printf("Overflowed? : ");
    if( overflow == 0 ){
        printf("No\n");
    }else{
        printf("Yes\n");
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

void readBinaryInput(int bin[]){
    char input;
    for(int i = 0; i < NUM_BITS; i++){
        scanf(" %c", &input);
        if(input == '0'){
            bin[i] = 0;
        }else if(input == '1'){
            bin[i] = 1;
        }else{
            printf("ERR: Only enter a 0s and 1s in binary entry mode\n");
            exit(1);
        }
    }
}

void printBinary(int bin[]){
    for(int i = 0; i < NUM_BITS; i++){
        printf("%d", bin[i]);
        if( (i % 4) == 3 ){
            printf(" ");
        }
    }
    printf("\n");
}

void convertToBinary(int dec, int bin[]){
    if(dec > 0){ // Initialize outputBits to 0s when positive
        for(int i = 0; i < NUM_BITS; i++){
            bin[i] = 0;
        }
    }else{ // Initialize outputBits to 1s when positive
        for(int i = 0; i < NUM_BITS; i++){
            bin[i] = 1;
        }
        // Then map in onto its positive complement 
        dec = -dec - 1;
    }
    
    int index;
    for(index = 1; index < NUM_BITS; index++){
        int value = 1 << (NUM_BITS - 1 - index); // 2 ^ (NUM_BITS - 1 - index)
        if( dec >= value ){ // Check each power of two decreasing
            dec -= value;
            flipBit( bin + index ); // Flip the bit from 0 to 1 or vice versa. This allows for the usage of the same loop for both positive and negative
        }
    }

    
}

int convertToDecimal(int bin[]){
    int sum;
    if(bin[0] == 1){
        sum = -(1 << (NUM_BITS - 1));
    }else{
        sum = 0;
    }

    for(int i = 1; i < NUM_BITS; i++){
        if( bin[i] == 1 ){
            sum += 1 << (NUM_BITS - 1 - i);
        }
    }

    return sum;
}

int add(int num1[], int num2[], int res[]){
    int carry = 0;
    for(int i = NUM_BITS - 1; i >= 0; i--){
        res[i] = num1[i] ^ num2[i];
        res[i] = res[i] ^ carry;
        if( num1[i] + num2[i] + carry > 1 ){
            carry = 1;
        }else{
            carry = 0;
        }
    }
    if( (num1[0] == 0) && (num2[0] == 0) && (res[0] == 1) ){
        return 1;
    }else if( (num1[0] == 1) && (num2[0] == 1) && (res[0] == 0) ){
        return 1;
    }else{
        return 0;
    }
}
