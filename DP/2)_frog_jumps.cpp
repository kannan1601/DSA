// Recursion 

int f(int ind){
  if(ind == 0)
    return 0;
  int left =f(n - 1) + abs(heights[ind] - heights[ind - 1]);
  int right = INT_MAX;
  if(ind > 1)
    right = f(n - 2) + abs(heights[ind] - heights[ind - 2]);
  return min(left, right);
}
// TC -> O(2^N)
// SC -> O(N)

//recursion to DP (memoization)

int f(int ind, vector<int> &dp){
  if(ind == 0)
    return 0;
  if(dp[ind] != -1)
    return dp[ind];
  int left = f(n - 1, dp) + abs(heights[ind] - heights[ind - 1]);
  int right = INT_MAX;
  if(ind > 1)
    right = f(n - 2, dp) + abs(heights[ind] - heights[ind - 2]);
  return dp[ind] = min(left, right);
}
// The ans will be stored at dp[n - 1]
//TC -> O(N)
// SC -> O(N) + O(N)

//Tabulation

vector<int> dp(n + 1, -1);
dp[0] = 0;
for(int ind = 1; ind < n; ind++){
  int left = dp[i - 1] + abs(heights[ind] - heights[ind - 1]);
  int right = INT_MAX;
  if(ind > 1)
    right = dp[i - 2] + abs(heights[ind] - heights[ind - 2]);
  dp[ind] = min(left ,right);
}
// TC -> O(N)
// SC -> O(N)

// space optimisation

THUMB RULE : WHEN THERE IS  A TRANSISTION LIKE INDEX - 1 AND INDEX - 2, THERE IS ALWAYS SOME OPTIMISATION.
int first = 0;
int second = 0;
for(int i = 1; i < n; i++){
  int first_step = first + abs(heights[i] - heights[i - 1]);
  int second_step = INT_MAX;
  if(i > 1){
    second_step = second + abs(heights[i] - heights[i - 2]);
  }
}
cout << second <<"\n";

// TC -> O(N)
// SC -> O(1)
