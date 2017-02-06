#include "Sortings.hpp"
#include <utility>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

 
using namespace std;

std::vector<int> read(std::string path){
	std::ifstream file;
	file.open(path, std::fstream::in);
	int index = -1;
	std::string line;
	
	file >> line;
	int size = stoi(line);
	std::vector<int> vec(size);

	while(getline(file, line)){
		if(index!=-1)
			vec[index] = std::stoi(line);
		++index;
	}

	file.close();
	return vec;
}

int main(int argc, char const *argv[])

{
	int size_file = 0;
	clock_t initialTime, finalTime;
	float sortTime, soma;
	int var = atoi(argv[1]);
	string path = "";
	int turn = 1;

	int levelOrd[] = {1,5,9}; 	// Nivel de ordenação
	int sizeInst[] = {1,5,10};	// Tamanho da instancia  

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			turn = 1;
			soma = 0;

			while(turn < 2){
				
				path = "/home/diego-lima/Ordenacao01/instancias/";
				string currentFile = std::to_string(levelOrd[i]) + "0." + std::to_string(sizeInst[j]) + "00000." + std::to_string(turn) +".in";
				path += currentFile; 

				std::vector<int> vec = read(path); 
				size_file = vec.size();

				int arr[size_file];

				// vector to array
				std::copy(vec.begin(), vec.end(), arr);

					switch (var){
						case 1:
							initialTime = clock();
							Sortings::SelectionSort(arr,size_file);		
							finalTime = clock();
							break;

						case 2:	
							initialTime = clock();
							Sortings::InsertionSort(arr,size_file);
							finalTime = clock();
							break;
						
						case 3:
							initialTime = clock();
							Sortings::QuickSort(arr,0,size_file);
							finalTime = clock();
							break;

						case 4:
							initialTime = clock();
							Sortings::MergeSort(arr,size_file);
							finalTime = clock();
							break;	
						
						case 5:
							initialTime = clock();
							Sortings::HeapSort(arr,size_file);
							finalTime = clock();
							break;

						case 6:		
							std::size_t size = sizeof(arr) / sizeof(arr[0]);
							initialTime = clock();
							std::sort(arr, arr+ size);
							finalTime = clock();
							break;
					}		

					sortTime = (((double)(finalTime - initialTime) * 1000 / CLOCKS_PER_SEC));	
					soma += sortTime;
					turn++;
			}
			cout <<levelOrd[i]<<"0% ordenado  size= "<<sizeInst[j]<<"00000  tempo medio(ms)= "<<soma<<endl;
		}

	}

	return 0;
}		