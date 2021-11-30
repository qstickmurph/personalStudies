#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hundred = 100;

static void doit(double p){
    int a = 3;
    int *b = &a;
    static long c = 300;
    char *str = "abcd";
    char *str2 = strdup(str);
    void *p1 = malloc(100);
    void *p2 = (void *) "xyz";
    void *p3 = (void *) &a;

    printf("global var hundred is at %p\n", &hundred);
    printf("param p is at %p\n", &p);
    printf("char *str is at %p which points to %p\n", &str, str);
    printf("char *str2 is at %p which points to %p\n", &str2, str);
    printf("local var a is at %p\n", &a);
    printf("local var b is at %p which points to %p\n", &b, b);
    printf("static var c is at %p\n", &c);
    printf("void *p1 is at %p which points to %p\n", &p1, p1);
    printf("void *p2 is at %p which points to %p\n", &p2, p2);
    printf("void *p3 is at %p which points to %p\n", &p3, p3);
    printf("function doit is at %p\n", &doit);
}

int main(int argc, char *argv[]){
    doit(4);
    return 0;
}
