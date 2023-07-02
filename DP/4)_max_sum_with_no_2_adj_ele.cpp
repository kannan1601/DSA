//Recursion

int f(int ind, vector<int> &nums){

    if(ind == 0)
      return nums[0]; // because i can reach index = 0 only if picked up the 2nd index
    
    int pick = nums[ind]; // i can pick the curnt indx in pick option
    if(ind - 2 >= 0) // i need ans from the guy who is f(ind - 2) only if that guy exists (-ve index)
      pick += f(ind - 2, nums);
    
    //not pick option
    int notPick = 0 + f(ind - 1, nums);

    return max(pick, notPick);
}

//TC -> O(2^N)
// SC -> o(N) recursion stack space

//Memoiaztion for avoiding future recursion calls

int f(int ind, vector<int> &nums, vector<int> &dp){

    if(ind == 0)
      return nums[0]; // because i can reach index = 0 only if picked up the 2nd index

    if(dp[ind] != -1)
      return dp[ind];

    int pick = nums[ind]; // i can pick the curnt indx in pick option
    if(ind - 2 >= 0) // i need ans from the guy who is f(ind - 2) only if that guy exists (-ve index)
      pick += f(ind - 2, nums);
    
    //not pick option
    int notPick = 0 + f(ind - 1, nums);

    return dp[ind] = max(pick, notPick);
}

// TC -> O(N)
// SC -> O(N) + O(N)

//Tabulation

vector<int>dp(N + 1, - 1);
dp[0] = nums[0];
int neg = 0;

for(int i = 1; i < N; i++){
  int pick = nums[ind];
  if(i - 2 >= 0){
    pick += d[i - 2];
  }
  int notPick = 0 + dp[i - 1];

  dp[i] = max(pick, notPick);
}
cout << dp[N - 1] <<"\n";

// TC -> O(N)
// SC -> O(N);

// space optimisation
// here for dp[i], we need only dp[i - 1] or dp[i - 2]


int prev = nums[0];
int prev2 = 0;

for(int i = 1; i < N; i++){
  int pick = nums[ind];
  if(i - 2 >= 0){
    pick += prev2;
  }
  int notPick = 0 + prev;

  dp[i] = max(pick, notPick);
}
cout << prev <<"\n"; WHY PREV.. BECAUSE WHEN 'I' CAME OUT FROM THE LOOP IT WILL BE 'N'
                    SO, PREV WILL BE AT 'N - 1' SINCE OUR ANS WILL BE AT 'N - 1' INDEX, WE ARE 
                    PRINTING PREV.