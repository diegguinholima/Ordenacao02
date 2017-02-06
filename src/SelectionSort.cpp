#include "Sortings.hpp"
#include <utility>
#include <iostream>

using namespace std;

void Sortings::SelectionSort(int vector[], int size){

	int min = 0;

	for (int i = 0; i < (size-1); ++i)
	{
		min = i;

		for (int j = i; j < size; ++j)
		{
			if (vector[j] < vector[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(vector[i],vector[min]);
		}
	}
}