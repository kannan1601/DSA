#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int k = 0;
	for(int i = 0; i < n; i++){
		k += arr[i];
	}
	vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
	for(int i = 0; i < n; i++){
		dp[i][0] = true;
	}
	if(arr[0] <= k)dp[0][arr[0]] = true;
	for(int ind = 1; ind < n; ind++){
		for(int target = 1; target <= k; target++){
			bool notpick = dp[ind - 1][target];
			bool pick = false;
			if(arr[ind] <= target){
				pick = dp[ind - 1][target - arr[ind]];
			}
			dp[ind][target] = pick || notpick;
		}
	}
	int mini = 1e9;
	for(int sum = 0; sum <= k; sum++){
		if(dp[n - 1][sum] == true){
			mini = min(mini, abs(sum - (k - sum)));
		}
	}
	return mini;
}
