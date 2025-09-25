#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdio.h>
#include <stdlib.h>


int* array_merge(int num_arrays, int* sizes, int** values) {
 int total_size = 0;
 for (int i = 0; i < num_arrays; ++i) {
   total_size = total_size + sizes[i];   //accumulated the total size of the arrays in values
 }


 int* merged_array = malloc(total_size * sizeof(int));   //allocating memory for final array


 int mergedIndex = 0;   //index in merged_array


 //condensing into 1 array
 for (int i = 0; i < num_arrays; ++i) {   //array in values index
   for (int j = 0; j < sizes[i]; ++j) {   //element in array in values index
     merged_array[mergedIndex++] = values[i][j];   //adding all elements to final array
   }
 }


 //eliminating duplicates
 for (int i = 0; i < total_size; i++){   //element in final array index
   for (int j = i+1; j < total_size;){   //next element in final array index
     if (merged_array[i] == merged_array[j]){   //checks for duplicate
       for (int k = j; k < total_size - 1; k++){   //moving succeeding elements to the left by 1
         merged_array[k] = merged_array[k+1];   //replacing duplicate (removal)
       }
       total_size--;   //adjusting size
     } else {
         j++; //will check if element is equal to all elements in array (besides self) not just first the ones closest to it
     }
   }
 }


 //print check
 for (int i = 0; i < total_size; ++i) {
   printf("%d ", merged_array[i]);
 }
 printf("/n ");




 //mergesort here!!!




 //print check
 for (int i = 0; i < total_size; ++i) {
   printf("%d ", merged_array[i]);
 }
 printf("/n ");


 //final step
 for (int i = total_size; i > 0; i--) {
   merged_array[i] = merged_array[i - 1];   //shifting elements right 1
 }
 merged_array[0] = total_size;     //set first element to the length of the array (excluding 0th element)
 total_size ++;


 //print check
 for (int i = 0; i < total_size; ++i) {
   printf("%d ", merged_array[i]);
 }
 printf("/n ");


 return merged_array;
}


int main(void) {
 int num_arrays = 3;
 int sizes[] = {4, 2, 5};
 int a[] = {3, 2, 0, 5};
 int b[] = {8, 9};
 int c[] = {6, 3, 2, 0, 5};
 int* values[] = {a, b, c};
 int total_size = 4 + 2 + 5;

 int* result = array_merge(num_arrays, sizes, values);


 free(result);
 return 0;
}
