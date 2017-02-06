#include "Sortings.hpp"
#include <utility>
#include <iostream>

using namespace std;

int partition(int vector[], int low, int high){

	int pivot, i;

	pivot = vector[high];
	i = low-1;

	for (int j = low; j<=(high-1);++j)
	{
		if (vector[j] <= pivot)
		{
			i++;
			swap(vector[i],vector[j]);
		}
	}
	swap(vector[i+1],vector[high]);
	return (i+1);
}
void Sortings::QuickSort(int vector[], int low, int high){

	if (low < high)
	{
		int part;

		part = partition(vector,low,high);
		QuickSort(vector, low, part - 1);
        QuickSort(vector, part + 1, high);
	}
}