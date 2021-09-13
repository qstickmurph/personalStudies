#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

typedef struct pid_ll {
    pid_t pid;
    struct pid_ll *next;
} pid_ll;

int main(int argc, char* argv[]){
    // Parent process spawn one child process for each argument in argv
    
    // Start LL
    pid_ll *pidRoot = NULL;
    pid_ll *pidHead = NULL;
    int i;
    for(i = 1; i < argc; i++){
        pid_t tempPid = fork();

        if(tempPid == 0){// If child process, break;
            break;
        }
        pid_ll *llEntry = malloc(sizeof(pid_ll));
        
        if(pidRoot == NULL && pidHead == NULL){
            pidRoot = llEntry;
        }else{
            pidHead->next = llEntry;
        }

        llEntry->pid = tempPid;

        pidHead = llEntry;
    }
    
    if(i == argc){ // Parent wait for children
        while(pidRoot != NULL){
            waitpid(pidRoot->pid, NULL, 0);
            pid_ll *toBeFreed = pidRoot;
            pidRoot = pidRoot->next;
            free(toBeFreed);
        }

        printf("All %d files have been counted.\n", i-1);
    }else{ // Child counts the number of words in the file.
        FILE *f = NULL;
        f = fopen(argv[i], "r");
        if(f == NULL){
            printf("File %s could not be opened\n", argv[i]);
        }
        
        char c;
        bool insideWhitespace = true;
        int numWords = 0;
        while( (c = fgetc(f)) != EOF ){
            if(c == ' ' || c == '\t' || c == '\n'){
                insideWhitespace = true;   
            }else if(insideWhitespace == true){
                numWords += 1;
                insideWhitespace = false;
            }
        }

        printf("Child process for %s: number of words is %d\n", argv[i], numWords);
        fclose(f);
    }
}
