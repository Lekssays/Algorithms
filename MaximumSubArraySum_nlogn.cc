/* Maximum Sum Subarray Problem
Divide and Conquer Implementation
Time Complexity : O(n log n)
#include <love>
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const double eps = 1e-9;
const int INF = 1e9;

int max(int a, int b) { return (a > b) ? a : b;}
int max(int a, int b, int c) {return max(max(a, b), c);}

bool isNegative(vector<int> &V){
	int cnt = 0;
	for(int i = 0; i < V.size(); i++){
		if(V[i] < 0)
			cnt++;
	}
	return (cnt == V.size()) ? true : false;
}

int MaxCrossingSum(vector<int> &V, int start, int mid, int end){
	int sum = 0, left_sum = eps;
	for(int i = mid; i >= 1; i--){
		sum += V[i];
		if(sum > left_sum)
			left_sum = sum;
	}
	sum = 0;
	int right_sum = eps;
	for (int i = mid + 1; i <= end; i++){
		sum += V[i];
		if(sum > right_sum)
			right_sum = sum;
	}
	return left_sum + right_sum;
}

int MaxSubArraySum(vector<int> &V, int start, int end){
	if(start == end) return V[start];
	if(isNegative(V)){
		int min = INF;
		for(int i = 0; i < V.size(); i++){
			if(V[i] < min)
				min = V[i];
		}
		return min;
	} else {
		int mid = (start + end) / 2;
		return max(MaxSubArraySum(V, start, mid), MaxSubArraySum(V, mid + 1, end), MaxCrossingSum(V, start, mid, end));
	}
}

vector<int> V;
int main(void){
	int size;

	cin >> size;

	for(int i = 0; i < size; i++){
		int tmp;
		cin >> tmp;
		V.push_back(tmp);
	}

	cout << MaxSubArraySum(V, 0, size - 1) << endl;

	return 0;
}