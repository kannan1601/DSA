#include<bits/stdc++.h>
// int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp){
// 	if(ind == 0){
// 		if(N >= 1){
// 			return (N * price[0]);
// 		}
// 		return 0;
// 	}
// 	if(dp[ind][N] != -1)
// 		return dp[ind][N];
// 	int notcut = 0 + f(ind - 1, N, price, dp);
// 	int cut = -1e9;
// 	int rodlength = ind + 1;
// 	if(rodlength <= N){
// 		cut = price[ind] + f(ind, N - rodlength, price, dp);
// 	}
// 	return dp[ind][N] = max(cut, notcut);
// }
int cutRod(vector<int> &price, int N)
{
	// Write your code here.
	// vector<vector<int>> dp(N, vector<int>(N + 1, 0));

	vector<int> prev(N + 1, 0);
	for(int i = 1; i <= N; i++){
		prev[i] = i * price[0];
	}
	// return f(N - 1, N, price, dp);

	for(int ind = 1; ind < N; ind++){
		vector<int> curnt(N + 1, 0);
		for(int i = 1; i <= N; i++){
			int notcut = 0 + prev[i];
			int cut = -1e9;
			int rodlength = ind + 1;
			if(rodlength <= i){
				cut = price[ind] + curnt[i - rodlength];
			}
			curnt[i] = max(cut, notcut);
		}
		prev = curnt;
	}
	return prev[N];
}
