/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>


void quickSort(int A[], int l, int r){
    int pivot;
    if(l<r)
    {
    pivot = partition(A, l, r);
    quickSort(A, l, pivot - 1);
    quickSort(A, pivot + 1, r);
    }

}

int partition(int A[], int l, int r){

     int cur = l-1;

     for(int i = l; i<r; i++){
          if(A[i]<=A[r])
         {
            cur++;
            swap(&A[i],&A[cur]);
         }
     }
     swap(&A[r],&A[cur+1]); 
     return (cur+1);
}




void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
 
}

// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// main function
int main() {
  int data[] = {3, 8, 7, 2, 1, 0, 9, 6};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Unsorted Array\n");
  printArray(data, n);
  
  // perform quicksort on data
  quickSort(data, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}