#include "Sortings.hpp"
#include <utility>
#include <iostream>

using namespace std;

void Sortings::InsertionSort(int vector[], int size){

	int aux,j,i;

	for (j = 0; j < size; ++j)
	{
		aux = vector[j];

		for (i = (j-1); i >= 0 && vector[i] > aux; --i)
		{
			swap(vector[i+1],vector[i]);
		}
		
		vector[i+1] = aux;
	}
}