#include <iostream>
#include <functional>
#include "sortingFunctions.h"

using namespace std;
using namespace sf;

void testSortingFunction(function<void(vector<Elem>&)> function, const string& sortName);


void main() {
	testSortingFunction(bubbleSort, "bubbleSort");
	cout << endl;
	testSortingFunction(insertionSort, "insertionSort");
	cout << endl;
	testSortingFunction(selectionSort, "selectionSort");
	cout << endl;
	testSortingFunction(quickSort, "quickSort");
	cout << endl;
	testSortingFunction(mergeSort, "mergeSort");
}



void testSortingFunction(function<void(vector<Elem>&)> function, const string& sortName) {
	int i = 1;
	vector<Elem> arr;
	vector<Elem> expected;

	cout << "Test: " << i << " " << sortName << endl;
	arr = { 89, 2134, 1, 123, 2, 5, 100, 92, 101, 11 };
	expected = { 1, 2, 5, 11, 89, 92, 100, 101, 123, 2134 };
	function(arr);
	arr == expected ? cout << "PASSED" << endl : cout << "FAILED" << endl;
	i++;

	cout << "Test: " << i << " " << sortName << endl;
	arr = { 89, 2134, -1, 123, 2, -5, 100, 92, 101, 11 };
	expected = { -5, -1, 2, 11, 89, 92, 100, 101, 123, 2134 };
	function(arr);
	arr == expected ? cout << "PASSED" << endl : cout << "FAILED" << endl;
	i++;

	cout << "Test: " << i << " " << sortName << endl;
	arr = { 89, 2134, -5, 123, 2, -5, 100, 92, 101, 11 };
	expected = { -5, -5, 2, 11, 89, 92, 100, 101, 123, 2134 };
	function(arr);
	arr == expected ? cout << "PASSED" << endl : cout << "FAILED" << endl;
	i++;

	cout << "Test: " << i << " " << sortName << endl;
	arr = { };
	expected = { };
	function(arr);
	arr == expected ? cout << "PASSED" << endl : cout << "FAILED" << endl;
	i++;

	cout << "Test: " << i << " " << sortName << endl;
	arr = { };
	expected = { };
	function(arr);
	arr == expected ? cout << "PASSED" << endl : cout << "FAILED" << endl;
	i++;

	cout << "Test: " << i << " " << sortName << endl;
	arr = { 127836, -198723, 0};
	expected = { -198723, 0, 127836 };
	function(arr);
	arr == expected ? cout << "PASSED" << endl : cout << "FAILED" << endl;
	i++;


}



