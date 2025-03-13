#include <time.h>
#include <iostream>
#include "sortingFunctions.h"


using namespace sf;

void switchVectorEl(vector<Elem> &v, const unsigned int a, const unsigned int b);
unsigned int minPos(const vector<Elem> &arr, const unsigned int start, const unsigned int end);
unsigned int partition(vector<Elem>& v, const unsigned int low, const unsigned int high);
void quickSortAux(vector<Elem>& v, const unsigned int low, const unsigned int high);
vector<Elem> mergeSortAux(const vector<Elem>& v, const unsigned int start, const unsigned int end);
vector<Elem> merge(const vector<Elem> vOne, const vector<Elem> vTwo);


/**
* https://2024.aulaweb.unige.it/pluginfile.php/412941/mod_resource/content/5/05-namespaces.pdf
*
* https://2024.aulaweb.unige.it/pluginfile.php/412907/mod_resource/content/2/03-odinamentoQuadratico.pdf
* https://2024.aulaweb.unige.it/pluginfile.php/412945/mod_resource/content/7/07-RicBinMergeSort-intro.pdf
* https://2024.aulaweb.unige.it/pluginfile.php/427926/mod_resource/content/2/10-quicksort.pdf
*/

namespace sf {
	vector<Elem> randomVector(const unsigned int size) {
		vector<Elem> v;
		int randomNum;

		for (unsigned int i = 0; i < size; ++i) {
			randomNum = ( - 1000 + rand() % 2001);
			v.push_back(randomNum);
		}
		return v;
	}
	
	void printArr(const vector<Elem> v) {
		for (unsigned int i = 0; i < v.size(); ++i) {
			cout << v[i] << " ";
		}
		cout << endl;
	}

	void bubbleSort(vector<Elem>& v) {
		unsigned int size = v.size();
		bool switched;
		for (unsigned int i = 1; i < size; ++i){
			switched = false;
			for (unsigned int j = 0; j < size - i; ++j){
				if (v[j] > v[j + 1]){
					switchVectorEl(v, j, j + 1);
					switched = true;
				}
			}
			if (!switched) return;
		}
	}

	void insertionSort(vector<Elem>& v) {
		unsigned int size = v.size();
		for (unsigned int i = 1; i < size; ++i) {
			for (unsigned int j = i; j > 0; --j) {
				if (v[j] < v[j-1]) {
					switchVectorEl(v, j, j-1);
				}
			}
		}
	}

	void selectionSort(vector<Elem>& v) {
		unsigned int size = v.size();
		if (size < 1)return;
		unsigned int min;
		for (unsigned int i = 0; i < size-1; ++i) {
			min = minPos(v, i, size);
			if(min!=i)switchVectorEl(v, min, i);
		}
	}

	void quickSort(vector<Elem>& v) {
		unsigned int size = v.size();
		quickSortAux(v,0,size);
	}

	void mergeSort(vector<Elem>& v) {
		unsigned int size = v.size();
		if (size==0)return;
		v=mergeSortAux(v, 0, size-1);
	}
}

void quickSortAux(vector<Elem>& v, const unsigned int low, const unsigned int high) {
	if (low<high) {
		unsigned int pivot = partition(v, low, high);
		quickSortAux(v, low, pivot);
		quickSortAux(v, pivot+1, high);
	}
}

unsigned int partition(vector<Elem>& v, const unsigned int low, const unsigned int high) {
	unsigned int pivot = high-1;
	unsigned int leftWall = low;

	for (unsigned int i = low; i < high-1; ++i) {
		if (v[i] < v[pivot]) {
			switchVectorEl(v, i, leftWall);
			leftWall++;
		}
	}
	switchVectorEl(v, pivot, leftWall);
	return leftWall;
}

vector<Elem> mergeSortAux(const vector<Elem>& v, const unsigned int start, const unsigned int end) {
	if (start >= end)return { v[start] };
	unsigned int mid = start + (end - start) / 2;

	return merge(mergeSortAux(v, start, mid), mergeSortAux(v, mid + 1, end));
}

vector<Elem> merge(const vector<Elem> vOne, const vector<Elem> vTwo) {
	vector<Elem> res;
	unsigned int i, j; 
	i=j=0;

	while((i < vOne.size()) && (j < vTwo.size())) {
		if (vOne[i]<vTwo[j]) {
			res.push_back(vOne[i]);
			i++;
		}
		else {
			res.push_back(vTwo[j]);
			j++;
		}
	}
	while (i < vOne.size()) {
		res.push_back(vOne[i]);
		i++;
	}
	while (j < vTwo.size()) {
		res.push_back(vTwo[j]);
		j++;
	}

	return res;
}


void switchVectorEl(vector<Elem> &v, const unsigned int a, const unsigned int b) {
	Elem temp;
	temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

unsigned int minPos(const vector<Elem> &arr, const unsigned int start, const unsigned int end) {
	if (start >= end || end > arr.size()) {
		throw invalid_argument("Invalid start or end values");
	}
	unsigned int pos=start;
	for (unsigned int i = start+1; i < end; ++i) {
		if (arr[i]<arr[pos]) {
			pos = i;
		}
	}
	return pos;
}
