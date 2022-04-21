
/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>


void mergeSort(int A[], int l, int h){
    int m;
   

    if(l<h){
    m = l + (h-l)/2;
    mergeSort(A, l, m);
    mergeSort(A, m+1, h);
    merge(A, l, m, h);
    }
}

void merge(int A[], int l, int m, int h){

    int leftS = m - l + 1;
    int RightS = h - m;

    int L[leftS];
    int R[RightS];

    for(int i = 0; i<leftS; i++)
        L[i]=A[l+i];
    for(int j = 0; j<RightS; j++)
        R[j]=A[m+j+1];

    int a = 0;
    int b = 0;
    int k = l;
    while(a < leftS && b < RightS){
            if(L[a]<=R[b]){
                A[k] = L[a];
                a++;
            }
            else{
                A[k] = R[b];
                b++;
            }
            k++;
        }
    while(a < leftS){
        A[k]=L[a];
        a++;
        k++;
    }
    while(b < RightS){
        A[k]=R[b];
        b++;
        k++;
    }

}

void printArray(int A[], int n){
    for(int i = 0; i<n; i++)
        printf("%d ", A[i]);
}
/* Driver code */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7, 66,33,5, 7, 1, 3, 4, 4, 4 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
  
    printf("Given array is \n");
    printArray(arr, arr_size);
  
    mergeSort(arr, 0, arr_size - 1);
  
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}