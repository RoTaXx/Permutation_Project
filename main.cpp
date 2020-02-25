#include <iostream>
#include "permutation.h"

using namespace std;

int main() {

	unsigned rows = 2;
	unsigned cols;
	int target = 0;

	cout << "Please eneter the number of elements in the array: ";
	cin >> cols;
	int** arr = nullptr;
	arr = new int* [rows];
	resMem(arr, rows, cols);

	fillArr(arr, 2, cols);
	printArr(arr, 2, cols);
	if (cols==0 || rows<=0)
	{
		cout << "Invalid value! Please enter positive number only!" << endl;
		return false;
	}

	int number_of_problem;
	cout << endl << endl << "If you want to stop the program press 1" << endl << endl << endl;
	cout << "If you want to know if this function is Injection press 3" << endl;
	cout << "If you want to know if this function is Surjection press 4" << endl;
	cout << "If you want to know if this function is Bijection/Permutation press 5" << endl;
	cout << "If you want to know how many permutations you have press 6" << endl;
	cout << "If you want to know if this function has a fixed point press 7" << endl;
	cout << "If you want to know how many fixed points you have in this function press 8" << endl;
	cout << "If you want to know if this function is identical press 9" << endl << endl;
	cout << "If you want to see our permutation as independent cycles press 10" << endl;
	

	do {
		cin >> number_of_problem;

		cout << endl;

		if (number_of_problem == 3) {
			cout << (Injective(arr, cols) == true ? "Yes, this is injection" : "No, this is not injection") << endl;
			cout << "---------------" << endl;
		}

		if (number_of_problem == 4) {
			cout << (Surjective(arr, cols) == true ? "Yes, this is surjection" : "No, this is not surjection") << endl;
			cout << "---------------" << endl;
		}

		if (number_of_problem == 5) {
			cout << (Bijection(arr, cols) == true ? "Yes, this is bijection" : "No, this is not bijection") << endl;
			cout << "---------------" << endl;

		}

		if (number_of_problem == 6) {
			if (Bijection(arr, cols) == true) {
				cout << "The number of Permutations is - " << permutationFinder(cols) << endl;
				cout << "---------------" << endl;
			}
			else {
				cout << "Sorry this is not a bijection and I can not show you what you want! Please try again with a correct function!" << endl;
				cout << "---------------" << endl;
			}
		}

		if (number_of_problem == 7) {
			if (Bijection(arr, cols) == true) {
				cout << (fixedPoints(arr, cols) == true ? "Yes, in this permutation you have at least one fixed point" : "No, in this permutation you have not got fixed point") << endl;
				cout << "---------------" << endl;
			}
			else {
				cout << "Sorry this is not a bijection and I can not show you what you want! Please try again with a correct function!" << endl;
				cout << "---------------" << endl;
			}
		}

		if (number_of_problem == 8) {
			if (Bijection(arr, cols) == true) {
				cout << "You have " << fixedPointsCounter(arr, cols) << " fixed point/points" << endl;
				cout << "---------------" << endl;
			}
			else {
				cout << "Sorry this is not a bijection and I can not show you what you want! Please try again with a correct function!" << endl;
				cout << "---------------" << endl;
			}
		}

		if (number_of_problem == 9) {
			if (Bijection(arr, cols) == true) {
				cout << (indentical(arr, cols) == true ? "Yes, this function is identical" : "No, this function is not identical") << endl;
				cout << "---------------" << endl;
			}
			else {
				cout << "Sorry this is not a bijection and I can not show you what you want! Please try again with a correct function!" << endl;
				cout << "---------------" << endl;
			}
		}

		if (number_of_problem == 10) {
			if (Bijection(arr, cols) == true) {
				cout << "This is our Permutation" << endl;
				cycleNotation(arr, cols);
				cout << endl;
				cout << "---------------" << endl;
			}
			else {
				cout << "Sorry this is not a bijection and I can not show you what you want! Please try again with a correct function!" << endl;
				cout << "---------------" << endl;
			}
		}

		if (number_of_problem == 1) {
			cout << "Thank you for your attention!" << endl;
			cout << "---------------" << endl;

		}

	} while (number_of_problem != 1);

}

	