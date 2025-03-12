#include <time.h>
#include "sortingFunctions.h"


using namespace sf;

void switchVectorEl(vector<Elem> &v, int a, int b);



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

	void bubbleSort(vector<Elem>& v) {
		unsigned int size = v.size();
		bool switched;
		for (unsigned int i = 1; i < size; ++i)
		{
			switched = false;
			for (unsigned int j = 0; j < size - i; ++j)
				if (v[j] > v[j + 1])
				{
					switchVectorEl(v, j, j + 1);
					switched = true;
				}
			if (!switched) return;
		}
	}

	void insertionSort(vector<Elem>& v) {

	}

	void selectionSort(vector<Elem>& v) {

	}

	void quickSort(vector<Elem>& v) {

	}

	void mergeSort(vector<Elem>& v) {

	}
}




void switchVectorEl(vector<Elem> &v, int a, int b) {
	Elem temp;
	temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}