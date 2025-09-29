#include "mergesort.h"


static void merge(int values[], int left, int mid, int right){
	int node1 = mid - left + 1;
	int node2 = right - mid;
	
	int* L =(int*) malloc(node1 * sizeof(int));
	int* R =(int*) malloc(node2 * sizeof(int));

	for (int i = 0; i < node1; i++) {
		L[i] = values[left + i];
	}

	for (int j = 0; j < node2; j++) {
		R[j] = values[mid + 1 + j];
	}
	
	int i = 0, j = 0, k = left;

	while ( i < node1 && j < node2 ){
		if(L[i] <= R[j]){
			values[k++] = L[i++];
		} else {
			values[k++] = R[j++];
		}
	}

	while (i < node1) {
		values[k++] = L[i++];
	}
	while (j < node2) {
		values[k++] = R[j++];
	}

	free(L);
	free(R);
	

}

static void merge_recursive(int values[], int left, int right){
	
	if (left < right) {
		int mid = (left + right) / 2;
		merge_recursive(values, left, mid);
		merge_recursive(values, mid + 1, right);
		merge(values, left, mid, right);
	}
}

void mergesort(int size, int values[]) {
	if (size > 1 ) {
		merge_recursive(values, 0, size - 1);
	}
}

