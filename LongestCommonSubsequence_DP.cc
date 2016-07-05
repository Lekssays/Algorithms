/* DP - Longest Common Subsequence Problem
Time Complexity : O(m * n)
m : length of the first string
n : length of the second string
#include <love>
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int LongestCommonSubsequence(string A, string B, int a, int b){
  int dp[a + 1][b + 1];
  for(int i = 0; i <= a; i++){
    for(int j = 0; j <= b; j++){
      if(i == 0 || j == 0) dp[i][j] = 0;
      else if(A[i - 1] == B[i - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[a][b];
}

int main(void){
  string A, B;
  int a, b;
  cin >> A >> B;
  a = A.length();
  b = B.length();
  cout << LongestCommonSubsequence(A, B, a, b) << endl;
  return 0;
}
