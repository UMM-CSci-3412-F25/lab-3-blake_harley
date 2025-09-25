#include "mergesort.h"

void mergesort(int size, int values[]) {
	if (size > 1 ) {
		merge_recursive(values, 0, size - 1);
	}
}

static void merge_recursive(int values[], int left, int right){
	
	
	if (left < right) {
		int mid = (left + right) / 2;
		merge_recursive(values, left, mid);
		merge_recursive(values, mid + 1, right);
		merge(values, left, mid, right);
	}
}

static void merge(int values[], int left, int mid, int right){
	int m1 = mid - left + 1;
	int m2 = right - mid;
	
	int L* = malloc(m1 * sizeof(int));
	int R* = malloc(m2 * sizeof(int));

	for (int i = 0; i < m1; i++) {
		L[i] = values[left + 1];
	}

	for (int j = 0; j < m2; j++) {
		R[j] = values[mid + 1 + j];
	}
	
	int i = 0, j = 0, k = left;

	while ( i < m1 && j < m2 ){
		if(L[i] <= R[j]){
			values[k++] = L[i++ ]
		} else {
			values[k++] = R[j++]
		}
	}

	while (i < m1) {
		values[k++] = L[i++]
	}
	while (j < m2) {
		values[k++] = R[++]
	}
	

}

