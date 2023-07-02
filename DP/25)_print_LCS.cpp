#include<bits/stdc++.h>
using namespace std;

string lcs(string S, string T){
  string ans = "";
  int N = S.length();
  int M = T.length();
  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      if(S[i - 1] == T[j - 1]){
        dp[i][j] = 1 + dp[i - 1][j - 1];
        continue;
      }
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
    }
  }
  int i = N, j = M;
  while(i > 0 && j > 0){
    if(S[i - 1] == T[j - 1]){
      ans += S[i - 1];
      i--;
      j--;
    }
    else if(dp[i - 1][j] >= dp[i][j - 1]){
      i--;
    }
    else{
      j--;
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  string S = "abcde";
  string T = "bdgek";
  cout << lcs(S, T);
}