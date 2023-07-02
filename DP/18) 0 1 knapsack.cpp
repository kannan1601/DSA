//recursion and memoization
#include <bits/stdc++.h> 

int f(int ind, int maxweight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
	if(ind == 0){
		if(weight[0] <= maxweight)return value[0];
		return 0;
	}
	if(dp[ind][maxweight] != -1)
		return dp[ind][maxweight];
	int notpick = 0 + f(ind - 1, maxweight, weight, value, dp);
	int pick = -1e9;
	if(weight[ind] <= maxweight){
		pick = value[ind] + f(ind - 1, maxweight - weight[ind], weight, value, dp);
	}
	return dp[ind][maxweight] = max(pick, notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxweight) 
{
	vector<vector<int>> dp(n, vector<int>(maxweight + 1, -1));
	return f(n - 1, maxweight, weight, value, dp);
}






// Tabulation
#include <bits/stdc++.h> 
int knapsack(vector<int> wt, vector<int> value, int n, int maxweight) 
{
	vector<vector<int>> dp(n, vector<int>(maxweight + 1, 0));

	for(int i = wt[0]; i <= maxweight; i++){
		dp[0][i] = value[0];
	}

	for(int ind = 1; ind < n; ind++){
		for(int W = 0; W <= maxweight; W++){
			int notpick = 0 + dp[ind - 1][W];
			int pick = INT_MIN;
			if(wt[ind] <= W){
				pick = value[ind] + dp[ind - 1][W - wt[ind]];
			}
			dp[ind][W] = max(pick, notpick);
		}
	}
	
	return dp[n - 1][maxweight];
	
}

//space optimised approach
#include <bits/stdc++.h> 


int knapsack(vector<int> wt, vector<int> value, int n, int maxweight) 
{
	vector<int> prev(maxweight + 1, 0);


	for(int i = wt[0]; i <= maxweight; i++){
		prev[i] = value[0];
	}

	for(int ind = 1; ind < n; ind++){
		vector<int> curnt(maxweight + 1, 0);
		for(int W = 0; W <= maxweight; W++){
			int notpick = 0 + prev[W];
			int pick = INT_MIN;
			if(wt[ind] <= W){
				pick = value[ind] + prev[W - wt[ind]];
			}
			curnt[W] = max(pick, notpick);
		}
		prev = curnt;
	}
	
	return prev[maxweight];
	
}