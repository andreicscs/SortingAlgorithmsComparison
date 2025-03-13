#include <iostream>
#include <functional>
#include "sortingFunctions.h"

using namespace std;
using namespace sf;

void testSortingFunction(function<void(vector<Elem>&)> function, const string& sortName);
void assert(vector<Elem> expected, vector<Elem> arr);
void expectedVSresult(vector<Elem> arr, vector<Elem> expected, vector<Elem> sortedArrr);
void test(unsigned int& i, const vector<Elem> arr, const vector<Elem> expected, const function<void(vector<Elem>&)> function, const string& sortName);

int main() {
	testSortingFunction(bubbleSort, "bubbleSort");
	cout << "-------------------"<<endl;
	testSortingFunction(insertionSort, "insertionSort");
	cout << "-------------------" << endl;
	testSortingFunction(selectionSort, "selectionSort");
	cout << "-------------------" << endl;
	testSortingFunction(quickSort, "quickSort");
	cout << "-------------------" << endl;
	testSortingFunction(mergeSort, "mergeSort");

	return 0;
}
//*/


void testSortingFunction(const function<void(vector<Elem>&)> function, const string& sortName) {
	unsigned int i = 1;
	vector<Elem> arr;
	vector<Elem> expected;

	arr = { 89, 2134, 1, 123, 2, 5, 100, 92, 101, 11 };
	expected = { 1, 2, 5, 11, 89, 92, 100, 101, 123, 2134 };
	test(i, arr, expected, function, sortName);

	arr = { 89, 2134, -1, 123, 2, -5, 100, 92, 101, 11 };
	expected = { -5, -1, 2, 11, 89, 92, 100, 101, 123, 2134 };
	test(i, arr, expected, function, sortName);

	arr = { 89, 2134, -5, 123, 2, -5, 100, 92, 101, 11 };
	expected = { -5, -5, 2, 11, 89, 92, 100, 101, 123, 2134 };
	test(i, arr, expected, function, sortName);

	arr = { };
	expected = { };
	test(i, arr, expected, function, sortName);

	arr = { 127836, -198723, 0};
	expected = { -198723, 0, 127836 };
	test(i, arr, expected, function, sortName);

	arr = { 0 };
	expected = { 0 };
	test(i, arr, expected, function, sortName);
}

void test(unsigned int &i, const vector<Elem> arr, const vector<Elem> expected, const function<void(vector<Elem>&)> function, const string& sortName) {
	vector<Elem> sortedArrr;
	cout << "\tTest: " << i << " -----> " << sortName << endl;
	sortedArrr = arr;
	function(sortedArrr);
	expectedVSresult(arr, expected, sortedArrr);
	assert(expected, sortedArrr);
	i++;
}


void expectedVSresult(vector<Elem> arr, vector<Elem> expected, vector<Elem> sortedArrr) {
	cout << "Array:          \t";
	printArr(arr);
	cout << "Expected result:\t";
	printArr(expected);
	cout << "Result:         \t";
	printArr(sortedArrr);
}
void assert(vector<Elem> expected, vector<Elem> arr) {
	arr == expected ? cout << "PASSED" << endl : cout << "FAILED" << endl;
}




