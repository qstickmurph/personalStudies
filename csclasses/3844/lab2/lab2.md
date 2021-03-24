# Lab 2
Quinn Murphey // pfl955 // 03-22-21 // CS3884.0B2

## 3. Copy the content of the file and select C as your language from the top-right dropdown. Run the program by clicking the “Run” button. What is the error encountered (if any!)?
Floating Point Exception (Core Dumped)

## 7. What are the values of variables c and d at the start of line 8 (before executing line 8)?
c = 20; d = 0

## 10. Debug and modify lab2a.c to carry out four arithmetic operations (+,-,/,*).
```
#include <stdio.h>

int main(){
	int a = 10;
	int b = 10;
	int c = a+b;
	int d = a-b;
	int e = b/a;
	int f = a*b;
  
	printf("Arithmetic operations:\n");
	printf("a+b = %d\n", c);
	printf("a-b = %d\n", d);
	printf("b/a = %d\n", e);
	printf("a*b = %d\n\n", f);

	return 0;
}
```

## 12. Can you give 2 ways of displaying the stored value and address value of the first element of an array?
(Assume a is the array of integers) \\
Stored Value 
```
printf("%d\n", a[0]);
printf("%d", a*);
```

Address Value
```
printf("%p\n", a);
pritnf("%p", &a[0]);
```

## 13. Can you define the function reverseArray(int arr[], size_t size) in the lab1b.c using pointers to traverse the array? Write your function below. 
```
void reverseArray(int arr[], size_t size) {
    for(int i = 0; i < size/2; ++i){
        int temp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = temp;
    }
}
```

## 14. Why do we pass the size of the array to the reverseArray function in lab1b.c? Can we calculate the size of the array inside the function?
We are not able to compute the length of the array in the function reverseArray because an array is just a pointer to memory. Unlike strings with their null terminator character, there is no way to tell if we have reached the end of memory. Thus, we must pass the length of the array to the function in order to reverse the correct amount of memory.
