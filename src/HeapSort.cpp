#include "Sortings.hpp"
#include <utility>
#include <iostream>
#include <utility>

using namespace std;

void maxHeap(int vector[], int size, int i){
  
  int left = (2*i)+1;
  int right = (2*i)+2;
  int big = i;
  int aux;

  if( (left<size) && (vector[left] > vector[big]) )
    big = left;

  if((right<size) && (vector[right] > vector[big]) )
    big = right;

  if(big != i){
    aux = vector[i];
    vector[i] = vector[big];
    vector[big] = aux;
    maxHeap(vector, size, big);
  }

}

void buildMaxHeap(int vector[], int size){
  for (int i = size/2; i > -1; i--) {
    maxHeap(vector, size, i);
  }
}

void Sortings::HeapSort(int vector[], int size){
  buildMaxHeap(vector, size);
  for (int i = size-1; i >= 0; i--) {
    swap(vector[0], vector[i]);
    size--;
    maxHeap(vector, size, 0);
  }
}