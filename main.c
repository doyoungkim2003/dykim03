#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertItem(int* arr1, int* arr2, int size) {
    int number = rand() % size;
    *arr1 = number;
    *arr2 = number;
}

void selectionSort(int* arr, int size) {
    if(size <= 1) { return; }
    int i, j, min, tmp;

    for(i = 0; i < size - 1; i++) {
        min = i;
        for(j = i + 1; j < size; j++) {
            if(*(arr + j) < *(arr + min)) { min = j; }
        }
        tmp = *(arr + i);
        *(arr + i) = *(arr + min);
        *(arr + min) = tmp;
    }
}

void insertionSort(int* arr, int size) {
    int i, j, tmp;
    if(size <= 1) { return; }

    for(i = 1; i < size; i++) {
        tmp = *(arr + i);
        j = i - 1;
        while((j >= 0) && (*(arr + j) > tmp)) {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j + 1) = tmp;
    }
}

void print(int* arr, int size) {
    int i;
    for(i = 0; i < size; i++) { printf(" %d", *(arr+i)); }
    printf("\n");
}

int main(void) {
    int* arr1 = NULL, *arr2 = NULL;
    int size, i;
    srand(time(NULL));
    scanf("%d", &size);

    arr1 = (int *)malloc(sizeof(int) * size);
    arr2 = (int *)malloc(sizeof(int) * size);

    for(i = 0; i < size; i++) { insertItem(arr1+i, arr2+i, size); }

    insertionSort(arr1, size);
    print(arr1, size);
    
    return 0;
}
