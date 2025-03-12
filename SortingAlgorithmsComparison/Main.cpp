#include <iostream>
#include <chrono>
#include "sortingFunctions.h"

using namespace std;
using namespace sf;

void printMenu();
void printArr(const vector<Elem> v);

void main() {
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
			case 4:
				auto begin = chrono::high_resolution_clock::now();

				bubbleSort(arr);

				auto end = chrono::high_resolution_clock::now();
				auto dur = end - begin;
				auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
				cout << "array sorted with bubble sort, elapsed time: " << ms << " ms" << endl;
				break;
		}
	}
}


void printMenu() {
	cout << "Select action (type 0 to quit): " << endl; 
	
	cout << "\t0: QUIT" << endl;
	cout << "\t1: print menu" << endl;
	cout << "\t2: set array size	args: unsigned int size" << endl;
	cout << "\t3: print array" << endl;
	cout << "\t4: bubbleSort" << endl;
}

void printArr(const vector<Elem> v) {
	for (unsigned int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}