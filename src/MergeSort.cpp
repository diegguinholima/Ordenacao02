#include "Sortings.hpp"
#include <utility>
#include <iostream>

void merge(int vet[], int left[], int n1, int right[], int n2){

  int i=0, j=0, k=0;

  while(i<n1 && j< n2) {
        if(left[i]  < right[j])
      vet[k++] = left[i++];
    else
      vet[k++] = right[j++];

  }

    while(i < n1)
    vet[k++] = left[i++];
  while(j < n2)
    vet[k++] = right[j++];

  }

void Sortings::MergeSort(int vet[], int size) {

  if(size<2) return; 

  int mid = size/2;

  int* left = new int[mid];
  int* right = new int[size-mid];

  
  for (int i = 0; i < mid; i++)
    left[i]=vet[i];


  for (int i = mid; i < size; i++)
    right[i-mid]=vet[i];
 


    MergeSort(left,mid); 
    MergeSort(right,size-mid); 
    merge(vet,left,mid,right,size-mid);

    delete [] left;
    delete [] right;
}