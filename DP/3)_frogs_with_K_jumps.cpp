// recursion

int f(int ind, int k, vector<int> &heights){
  if(ind == 0)
    return 0;
  int minsteps = INT_MAX;
  for(int i = 1; i <= k; i++){
    if(ind - i >= 0){
      int jumps = f(ind - i, k, heights) + abs(heights[ind] - heights[ind - i]);
      minsteps = min(minsteps, jumps);
    }
  }
  return minsteps;
}

//TC -> O(N * K)
// SC -> O(N)

//Memoization

int f(int ind, int k, vector<int> &heights, vector<int> &dp){
  if(ind == 0)
    return 0;
  if(dp[ind] != -1)
    return dp[ind];
  int minsteps = INT_MAX;
  for(int i = 1; i <= k; i++){
    if(ind - i >= 0){
      int jumps = f(ind - i, k, heights, dp) + abs(heights[ind] - heights[ind - i]);
      minsteps = min(minsteps, jumps);
    }
  }
  return dp[ind] = minsteps;
}

//TC -> O(N * K)
// SC -> O(N) + O(N)

//Tabulation

vector<int> dp(N + 1, -1);
int dp[0] = 0;
for(int i = 1; i < N; i++){
  int minsteps = INT_MAX;
  for(int j = 1; j <= k; j++){
    if(i - j >= 0){
      int jumps = dp[i - j] + abs(heights[i] - heights[i - j]);
      minsteps = min(minsteps, jumps);
    }
  }
  dp[i] = minsteps;
}
cout << dp[n - 1] <<"\n";

//TC -> O(N *K)
// SC -> O(N);