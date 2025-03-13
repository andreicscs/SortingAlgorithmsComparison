#include <iostream>
#include <chrono>
#include "sortingFunctions.h"

using namespace std;
using namespace sf;

void printMenu();

/*
int main() {
	vector<Elem> arr = randomVector(10);
	srand((unsigned int)time(NULL));

	int input;
	printMenu();
	while ((cin >> input) && (input != 0))
	{
		switch(input){
			case 0:
				break;
			case 1: 
				printMenu();
				break;
			case 2:
				unsigned int size;
				cin >> size;
				arr = randomVector(size);
				cout << "vector intialized to size " << size << endl;
				break;
			case 3:
				printArr(arr);
				break;
			case 4:{
				auto begin = chrono::high_resolution_clock::now();

				bubbleSort(arr);

				auto end = chrono::high_resolution_clock::now();
				auto dur = end - begin;
				auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
				cout << "array sorted with bubble sort, elapsed time: " << ms << " ms" << endl;
				break;
			}
			case 5:{
				auto begin = chrono::high_resolution_clock::now();

				insertionSort(arr);

				auto end = chrono::high_resolution_clock::now();
				auto dur = end - begin;
				auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
				cout << "array sorted with bubble sort, elapsed time: " << ms << " ms" << endl;
				break;
			}
			case 6:{
				auto begin = chrono::high_resolution_clock::now();

				selectionSort(arr);

				auto end = chrono::high_resolution_clock::now();
				auto dur = end - begin;
				auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
				cout << "array sorted with bubble sort, elapsed time: " << ms << " ms" << endl;
				break;
			}
			case 7: {
				auto begin = chrono::high_resolution_clock::now();

				quickSort(arr);

				auto end = chrono::high_resolution_clock::now();
				auto dur = end - begin;
				auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
				cout << "array sorted with bubble sort, elapsed time: " << ms << " ms" << endl;
				break;
			}
			case 8: {
				auto begin = chrono::high_resolution_clock::now();

				mergeSort(arr);

				auto end = chrono::high_resolution_clock::now();
				auto dur = end - begin;
				auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
				cout << "array sorted with bubble sort, elapsed time: " << ms << " ms" << endl;
				break;
			}
		}
	}
	return 0;
}
//*/

void printMenu() {
	cout << "Select action (type 0 to quit): " << endl; 
	
	cout << "\t0: QUIT" << endl;
	cout << "\t1: print menu" << endl;
	cout << "\t2: set array size	args: unsigned int size" << endl;
	cout << "\t3: print array" << endl;
	cout << "\t4: bubbleSort" << endl;
	cout << "\t5: insertionSort" << endl;
	cout << "\t6: selectionSort" << endl;
	cout << "\t7: quickSort" << endl;
	cout << "\t8: mergeSort" << endl;
}

