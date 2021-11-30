#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pslibrary.h"

#define BUFFER_SIZE 100
#define MAX(x,y) (((x)>(y))?(x):(y))

int countChars(char str[], char ch);

int main(int argc, char* argv[]){
    if (argc != 8){
        printf("Usage: %s q x1 y1 z1 x2 y2 z2\n", argv[0]);
        return 1;
    }
    // Set all variables with atoi()
    int q = atoi(argv[1]);
    int x1 = atoi(argv[2]);
    int y1 = atoi(argv[3]);
    int z1 = atoi(argv[4]);
    int x2 = atoi(argv[5]);
    int y2 = atoi(argv[6]);
    int z2 = atoi(argv[7]);
    
    int ready1;
    int ready2;
    double waitingTime;
    double utilization;
    
    printf("CS 3424 Assignment 2 program was written by Quinn Murphey\n");
    printf("%d %d %d %d %d %d %d\n", q, x1, y1, z1, x2, y2, z2);

    char* process1Chart = malloc(sizeof(char) * BUFFER_SIZE);
    char* process2Chart = malloc(sizeof(char) * BUFFER_SIZE);
    
    // FCFS
    fcfs(process1Chart, process2Chart, x1, y1, z1, x2, y2, z2);
    ready1 = countChars(process1Chart, 'r');
    ready2 = countChars(process2Chart, 'r');
    waitingTime = (double)(ready1 + ready2) / 2.0;
    utilization = (double)(countChars(process1Chart, 'R') + countChars(process2Chart, 'R')) / (double) MAX(strlen(process1Chart), strlen(process2Chart));
    printf("\nFIRST COME FIRST SERVE (fcfs):\n");
    printf("%s\n", process1Chart);
    printf("%s\n", process2Chart);
    printf("%d %d %lf %lf\n", ready1, ready2, waitingTime, utilization);

    // SJF
    sjf(process1Chart, process2Chart, x1, y1, z1, x2, y2, z2);
    ready1 = countChars(process1Chart, 'r');
    ready2 = countChars(process2Chart, 'r');
    waitingTime = (double)(ready1 + ready2) / 2.0;
    utilization = (double)(countChars(process1Chart, 'R') + countChars(process2Chart, 'R')) / (double) MAX(strlen(process1Chart), strlen(process2Chart));
    printf("\nSHORTEST JOB FIRST (sjf):\n");
    printf("%s\n", process1Chart);
    printf("%s\n", process2Chart);
    printf("%d %d %lf %lf\n", ready1, ready2, waitingTime, utilization);

    // PSJF
    psjf(process1Chart, process2Chart, x1, y1, z1, x2, y2, z2);
    ready1 = countChars(process1Chart, 'r');
    ready2 = countChars(process2Chart, 'r');
    waitingTime = (double)(ready1 + ready2) / 2.0;
    utilization = (double)(countChars(process1Chart, 'R') + countChars(process2Chart, 'R')) / (double) MAX(strlen(process1Chart), strlen(process2Chart));
    printf("\nPREEMPTIVE-SHORTEST JOB FIRST (psjf):\n");
    printf("%s\n", process1Chart);
    printf("%s\n", process2Chart);
    printf("%d %d %lf %lf\n", ready1, ready2, waitingTime, utilization);

    // RR
    rr(process1Chart, process2Chart, q, x1, y1, z1, x2, y2, z2);
    ready1 = countChars(process1Chart, 'r');
    ready2 = countChars(process2Chart, 'r');
    waitingTime = (double)(ready1 + ready2) / 2.0;
    utilization = (double)(countChars(process1Chart, 'R') + countChars(process2Chart, 'R')) / (double) MAX(strlen(process1Chart), strlen(process2Chart));
    printf("\nROUND ROBIN (rr):\n");
    printf("%s\n", process1Chart);
    printf("%s\n", process2Chart);
    printf("%d %d %lf %lf\n", ready1, ready2, waitingTime, utilization);
    
    return 0;
}

int countChars(char str[], char ch){ // Counts the number of occurances of ch in str
    int sum = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++){
        if(str[i] == ch)
            sum++;
    }

    return sum;
}
