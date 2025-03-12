#pragma once

#include <vector>


using namespace std;


namespace sf
{
	typedef int Elem;

	vector<Elem> randomVector(const unsigned int size);
	
	// O(n^2)
	void bubbleSort(vector<Elem> &v);
	void insertionSort(vector<Elem> &v);
	void selectionSort(vector<Elem> &v);
	
	// O( n log(n) )
	void quickSort(vector<Elem> &v);
	void mergeSort(vector<Elem> &v);
}