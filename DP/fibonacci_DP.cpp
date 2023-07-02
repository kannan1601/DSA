
//recursion

int fibo(int n)
{
  if(n <= 1)
    return n;
  
  return fibo(n - 1) + fibo(n - 2);
}

// TC -> O(2^n)
// SC -> O(n) stack space

//memoization

// 1) create DP array of size n + 1 and fill with -1
// 2) check if it is already computed if so return the value
// 3) Before calling the function store it

int fibo(int n, vector<int> &dp){
  if(n <= 1)
    return n;
  if(dp[n] != -1)
    return dp[n];
  return dp[n] = dp[n - 1] + dp[n - 2];
}
// TC -> O(n)
// SC -> O(n) + O(n)


//Tabulation

// 1) create DP array of size n + 1 and fill with -1
// 2) look base case and reconstruct it
// 3) copy the exact recurrence relationship

vector<int> dp(n + 1, -1);
dp[0] = 0, dp[1] = 1;
for(int i = 2; i <= n; i++){
  dp[i] = dp[i - 1] + dp[i - 2];
}
return dp[n - 1];

// TC -> O(n)
// SC -> O(n) 
