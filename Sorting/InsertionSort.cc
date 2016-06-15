/* include <love> 
Insertion Sort Implementation in C++
Time Complexity : O(n^2)
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V;

void InsertionSort(vector<int> &V){
	int j, tmp;
	for(int i = 0; i < V.size(); i++){
		j = i;
		while(j > 0 && V[j] < V[j - 1]){
			tmp = V[j];
			V[j] = V[j - 1];
			V[j - 1] = tmp;
			j--;
		}
	}
}

int main(void){
	int size;

	cin >> size;

	for(int i = 0; i < size; i++) {
		int tmp;
		cin >> tmp;
		V.push_back(tmp);
	}

	InsertionSort(V);

	for(int i = 0; i < V.size(); i++)
		cout << V[i] << " ";
	cout << endl;

	return 0;
}