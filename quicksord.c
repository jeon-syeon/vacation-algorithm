#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort(int ar[], int L, int R) {
	int left = L, right = R;
	int pivot = ar[(L + R) / 2];
	while (left<=right) {
		while (ar[left] < pivot) left++;
		while (ar[right] > pivot) right--;
		if ((left <= right) && (left!=right)) swap(&ar[left], &ar[right]);
		left++, right--;
	}
	if (L < right) quicksort(ar, L, right);
	if (R > left) quicksort(ar, left, R);
}

int main() {
	int *ar = NULL, n;
	scanf("%d", &n);
	ar = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
	quicksort(ar, 0, n - 1);
	for (int i = 0; i < n; i++) printf(" %d", ar[i]);
	return 0;
}