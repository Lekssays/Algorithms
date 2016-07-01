/* DP - Longest Common Subsequence Problem
#include <love>
*/
#include <iostream>
#include <algorithms>

using namespace std;

int LongestCommonSubsequence(string A, string B, int a, int b){
    if(a == 0 || b == 0) 
      return 0;
    if(A[a - 1] == B[b - 1]) 
      return LongestCommonSubsequence(A, B, a - 1, b -1) + 1;
    else 
      return max(LongestCommonSubsequence(A, B, a - 1, b), LongestCommonSubsequence(A, B, a, b - 1));
}

int main(void){
  string A, B;
  cin >> A >> B;
  int a = A.length(), b = B.length();
  cout << LongestCommonSubsequence(A, B, a, b) << endl;
  return 0;
}
