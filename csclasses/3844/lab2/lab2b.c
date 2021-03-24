#include <stdio.h>
#include <string.h>
#define MAX 10

int readArray(int [], int);
void printArray(int [], int);
void reverseArray(int [], size_t);

int main(void) {
  int array[MAX], numElements;

  numElements = readArray(array, MAX);
  reverseArray(array, numElements);
  printArray(array, numElements);

  return 0;
}

int readArray(int arr[], int limit) {
  int i, input;

  printf("Enter up to %d integers, terminating with a negative integer.\n", limit);
  i = 0;
  scanf("%d", &input);
  while (input >= 0) {
    arr[i] = input;
    i++;
    scanf("%d", &input);
  }
  return i;
}

void reverseArray(int arr[], size_t size) {
    for(int i = 0; i < size/2; ++i){
        int temp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = temp;
    }
}

void printArray(int arr[], int size) {
  int i;

  for (i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
