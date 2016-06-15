/* include <love> 
Quick Sort Implementation in C++
Time Complexity : O(n^2)
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> V;

void swap(int *x, int *y){ 
	*x ^= *y ^ (*y = *x);
}

int Partition(vector<int> &V, int start, int end){
	int pivotIndex = start, pivot = V[start];
	for(int i = start + 1; i <= end; i++){
		if(V[i] <= pivot){
			pivotIndex++;
			swap(V[i], V[pivotIndex]);
		}
	}
	swap(V[pivotIndex], V[start]);
	return pivotIndex;
}

void QuickSort(vector<int> &V, int start, int end){
	if(start < end){
		int pivotIndex = Partition(V, start, end);
		QuickSort(V, start, pivotIndex - 1);
		QuickSort(V, pivotIndex + 1, end);
	}	
}

int main(void){
	int size;

	cin >> size;

	for(int i = 1; i <= size; i++){
		int tmp;
		cin >> tmp;
		V.push_back(tmp);
	}

	QuickSort(V, 1, size);

	for(int i = 1; i <= size; i++)
		cout << V[i] << " ";
	cout << endl;

	return 0;
}