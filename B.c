#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void printArray(int* arr, int size); // 배열 출력 함수, 확인용으로 넣었음.
void swapElement(int* a, int* b); 
void selectionSort(int* arr, int size); // 제자리 선택 정렬 알고리즘.
void inPlaceInsertionSort(int* arr, int size); // 제자리 삽입 정렬 알고리즘.

int main(void) {
	int* A = NULL, * B = NULL;
	int i, count; // count는 A, B의 크기
	
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	scanf("%d", &count);

	// A, B 동적 할당
	A = (int*)malloc(sizeof(int) * count);
	B = (int*)malloc(sizeof(int) * count);
	
	// A, B 초기화
	for (i = 0; i < count; i++) {
		*(A + i) = i + 1;
		*(B + i) = i + 1;
	}

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	selectionSort(A, count);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	inPlaceInsertionSort(B, count);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	free(A);
	free(B);

	return 0;
}

void printArray(int* arr, int size) {
	int i;
	for (i = 0; i < size; i++) { printf(" %d", *(arr + i)); }
	printf("\n");
	return;
}

void swapElement(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int* arr, int size) {
	int i, j, min;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (*(arr + j) < *(arr + min)) {
				min = j;
			}
		}
		swapElement(arr + i, arr + min);
	}
	return;
}

void inPlaceInsertionSort(int* arr, int size) {
	int i, j, save;
	for (i = 1; i < size; i++) {
		save = *(arr + i);
		j = i - 1;
		while ((j >= 0) && (*(arr + j) > save)) {
			*(arr + j + 1) = *(arr + j);
			j -= 1;
		}
		*(arr + j + 1) = save;
	}
	return;
}
