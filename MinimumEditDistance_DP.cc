/* DP - Minimum Edit Distance Problem
Time Complexity : O(m * n)
m : length of the first string
n : length of the second string
#include <love>
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int min(int a, int b, int c){
  return min(min(a, b), c);
}

int MinimumEditDistance(string A, string B, int a, int b){
  int dp[a + 1][b + 1];
  for(int i = 0; i <= a; i++){
    for(int j = 0; j <= b; j++){
      if(i == 0) dp[i][j] = 0;
      else if(j == 0) dp[i][j] = 0;
      else if(A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
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
  cout << MinimumEditDistance(A,B,a,b) << endl;
  return 0;
}
