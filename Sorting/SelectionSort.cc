/* include <love> 
Selection Sort Implementation in C++
Time Complexity : O(n^2)
*/
#include <vector>
#include <iostream>

using namespace std;

void swap(int *x, int *y){ *x ^= *y ^ (*y = *x);} //XOR-Swapping

void SelectionSort(vector<int> &V){ // Increading Order
	for(int i = 0; i < V.size() - 1; i++){ // Loop through the array
		int minIndex = i; // set minindex as the starting one -> i (in this case)
		for(int j = i + 1; j < V.size(); j++){ // loop through the following element to look for the min value
			if(V[j] < V[minIndex]) minIndex = j; // compare it with our min value
		}
		swap(V[i], V[minIndex]); // swap if you find it
	}
}

int main(void){
	int size, b;
	vector<int> V;

	cin >> size;

	for(int i = 0; i < size; i++){
		cin >> b;
		V.push_back(b);
	}

	SelectionSort(V);

	for(int i = 0; i < size; i++)
		cout << V[i] << " "; 
	cout << endl;

	return 0;
}