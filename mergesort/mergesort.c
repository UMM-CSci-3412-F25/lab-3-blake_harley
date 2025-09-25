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

	int L = malloc(m1 * sizeof(int));
	int R = malloc(m2 * sizeof(int));

	while ( i < m1 && j < m2 ){
		if(L[i] <= R[j]){
		
		}
	
	}

}

