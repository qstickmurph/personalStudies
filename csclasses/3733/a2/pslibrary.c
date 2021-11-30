#define READY  0
#define RUNNING  1
#define WAITING  2
#define DONE  3

static char stateChars[] = {'r','R','w','\0'};

/* 1) handle state changes:
   running process completes CPU burst
   running process has quantum expire
   IO complete
   2) do context switch if necessary
   both ready
   one ready and CPU free
   3) append appropriate characters to character arrays
   avoid putting in multiple string terminators
   */
/* assume s1 and s2 point to buffers with enough space to hold the result */
/* assume that the int parameters are strictly greater than 0 */
void fcfs(char *s1, char *s2, int x1, int y1, int z1,
        int x2, int y2, int z2) {
    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */
    //int priority = 1;       // Tracks which process was ready first

    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];            /* terminate the string */
            }
            else
                state2 = WAITING;
        }
        // if IO complete, be ready for second CPU burst
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }  
        // if both ready, run process 1
        if ( (state1 == READY) && (state2 == READY)) {
            state1 = RUNNING;
        }  
        // if one ready, run it
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }  
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
    }                                               /* end of main for loop */
}

void sjf(char *s1, char *s2, int x1, int y1, int z1,
        int x2, int y2, int z2) {
    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];            /* terminate the string */
            }
            else
                state2 = WAITING;
        }
        // if IO complete, be ready for second CPU burst
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }  
        // if both ready, run the shorter (on tie run 1)
        if ( (state1 == READY) && (state2 == READY)) {
            if (cpuLeft1 <= cpuLeft2){
                state1 = RUNNING;
            }
            else{
                state2 = RUNNING;
            }
        }  
        // if one ready run it
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }  
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
    }                                               /* end of main for loop */
}

void psjf(char *s1, char *s2, int x1, int y1, int z1,
        int x2, int y2, int z2) {
    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];            /* terminate the string */
            }
            else
                state2 = WAITING;
        }
        // if IO complete, run if shorter than current process, otherwise, be ready
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            cpuLeft1 = z1;
            if(cpuLeft1 < cpuLeft2){
                state1 = RUNNING;
                state2 = READY;
            }
            else{
                state1 = READY;
            }
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            cpuLeft2 = z2;
            if(cpuLeft2 < cpuLeft1){
                state2 = RUNNING;
                state1 = READY;
            }
            else{
                state2 = READY;
            }
        }
        // if both ready, run shortest (run 1 on tie)
        if ( (state1 == READY) && (state2 == READY)) {
            if (cpuLeft1 <= cpuLeft2){
                state1 = RUNNING;
            }
            else{
                state2 = RUNNING;
            }
        }
        // if one ready, run it
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }  
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
    }                                               /* end of main for loop */
}

void rr(char *s1, char *s2, int q, int x1, int y1, int z1,
        int x2, int y2, int z2) {
    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */
    int qleft = q;

    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];            /* terminate the string */
            }
            else
                state2 = WAITING;
        }
        // if quantum expires set running process to ready and set ready process to running (if any)
        if ((state1 == RUNNING) && (qleft <= 0) ) {
            state1 = READY;
            qleft = q;
            if(state2 == READY){
                state2 = RUNNING;
            }
        }  
        if ((state2 == RUNNING) && (qleft <= 0) ) {
            state2 = READY;
            qleft = q;
            if(state1 == READY){
                state1 = RUNNING;
            }
        }  
        // if IO complete, be ready for second CPU burst
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }
        // if both ready run 1  
        if ( (state1 == READY) && (state2 == READY)) {
            state1 = RUNNING;
            qleft = q;
        }
        /* handle one ready and CPU available */
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
            qleft = q;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
            qleft = q;
        }  
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        qleft--;                   /* OK to decrement even if nothing running */
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
    }                                               /* end of main for loop */
}
