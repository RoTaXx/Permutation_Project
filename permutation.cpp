#include "permutation.h"
#include <iostream>



int resMem(int** arr, unsigned r, unsigned c)
{
	for (size_t i = 0; i < r; i++)
	{
		arr[i] = new int[c];
	}
	return 0;
}

int delMem(int** arr, unsigned r)
{
	if (arr != nullptr) {
		for (size_t i = 0; i < r; i++)
		{
			delete[] arr[i];
		}
		delete arr;
	}
	return 0;
}

int fillArr(int** arr, unsigned rows, unsigned cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		if (i == 0) {
			std::cout << "Please enter " << cols << " elements for 'x' each one on separate row - " <<std::endl << std::endl;
		}
		else {
			std::cout << "Now please enter " << cols << " elements for 'f(x)' each one on separate row - " << std::endl <<std::endl;
		}
		for (size_t j = 0; j < cols; j++)
		{
			std::cin >> arr[i][j];
		}
	}
	return 0;
}

int printArr(int** arr, unsigned rows, unsigned cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		if (i==0)
		{
			std::cout << "   x:{";
		}
		if (i == 1) {
			std::cout << "f(x):{";
		}
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << ((j != cols - 1) ? ", " : "");
		}
		std::cout << "}" << std::endl;
	}
	return 0;
}

int swap(int** arr, int i, int j)
{
	int tmp = *arr[i];
	arr[i] = arr[j];
	*arr[j] = tmp;
	return 0;
}

int bsort(int** arr, int sz)
{
	for ( int i = 0; i < sz; i++)
	{
		for (size_t j = 0; j < sz; j++)
		{
			if (arr[i] > arr[j]) swap(arr, i, j);
		}
	}
	return 0;
}

bool check_unique_numbers(int** arr, unsigned size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i+1; j < size; j++)
		{
			if (arr[0][i] != arr[0][j] && arr[1][i] != arr[1][j]) {
				return true;
			}
			else {
				std::cout << "Numbers are not unique" << std::endl;
				return false;
			}
		}
	}
}


bool Injective(int** arr, unsigned sz)
{
	bool injection = true;


	for (int i = 0; i < sz; i++) { 
		int counter = 0; 

		for (int j = 0; j < sz; j++) { 
			if (arr[0][i] == arr[1][j] && arr[0][i] != arr[0][j])
				counter++;
		}

		if (counter > 1) 
			injection = false;
	}

	return injection;
}

bool Surjective(int** arr, unsigned sz)
{
	bool Surjection = false;

	for (int i = 0; i < sz; i++) {
		int counter = 0; 

		for (int j = 0; j < sz; j++) { 
			if (arr[1][j] == arr[0][i])
				counter++;

		}

		if (counter >= 1) 
			Surjection = true;

		counter = 0; 
	}

	return Surjection;
}

bool Bijection(int** arr, unsigned cols)
{
	return Injective(arr, cols) && Surjective(arr, cols);
}

int permutationFinder(int cols)
{
	if (cols == 1) {
		return 1;
	}
	else {
		return cols * (permutationFinder(cols - 1));
	}
}

bool fixedPoints(int**arr , unsigned cols)
{
	for (size_t i = 0; i < cols; i++)
	{
		if (arr[0][i] == arr[1][i]) {
			return true;
		}
	}
	return false;
}

int fixedPointsCounter(int**arr, unsigned cols)
{
	int counter = 0;
	for (size_t i = 0; i < cols; i++)
	{
		if (arr[0][i] == arr[1][i]) {
			counter++;
		}
	}
	return counter;
}

bool indentical(int** arr, unsigned cols)
{
	int counter = 0;
	for (int i = 0; i < cols; i++) {
		if (arr[0][i] == arr[1][i]) {
			counter++;
		}
	}
	if (counter == cols) {
		return true;
	}
	return false;
}



void cycleNotation(int** arr, unsigned cols) {
	int counter = 0;
	int* finalRow = new int[cols];
	for (int i = 0; i < cols; i++) {
		finalRow[i] = arr[1][i];
	}

	
	int* check = new int[cols];
	for (int i = 0; i < cols; i++) {
		check[i] = 0;
	}

	int* result = new int[cols];
	int idx = 0;
	for (int i = 0; i < cols; i++) {

		if (check[i] != 1) {
			std::cout << "( ";
			while (check[i] != 1) {
				result[idx] = finalRow[i];
				std::cout << result[idx] << " ";
				idx++;
				check[i] = 1;
				i = getIndexOf(arr, finalRow[i], cols);
				counter++;
			}
			std::cout << ")";
			std::cout <<"length of the cycle:"<< counter<<std::endl;
			counter = 0;
			continue;
		}
		if (check[i] == 1) {
			continue;
		}
		result[idx] = finalRow[i];
		std::cout << result[idx] << " ";
		idx++;
	}
}

	
	int getIndexOf(int** matrix, int target, unsigned col) {
		int index = 0;

		for (int i = 0; i < col; i++) {
			if (target == matrix[0][i]) {
				index = i;
			}
		}

		return index;
	}
	
/*
int** permutationComposition(int** permutation1, int** permutation2, unsigned n)
{
	int** composition = new int* [2]; 
	for (size_t i = 0; i < 2; i++)
	{
		composition[i] = new int[n];
	}
	//here we fill the first row, because it is the same as the others

	for (int m = 0; m < n; m++)
	{
		composition[0][m] = permutation2[0][m];
	}

	//now we need to fill the other rows
	int toBeCompared;
	int startingPoint;

	int counter = 0;

	for (int i = 0; i < n; i++)
	{
		startingPoint = permutation2[0][i];

		toBeCompared = permutation2[1][i];

		for (int k = 0; k < n; k++)
		{
			if (permutation1[0][k] == toBeCompared)
			{
				composition[1][counter] = permutation1[1][k];
				counter++;

			}
		}
	}


	//std::cout << "The composition of your permutations is : ";
	//independentCyclesRemake(composition, n);
	return composition;

	if (composition != nullptr)
	{
		delete[] composition;
		composition = nullptr;
	}

}
*/



