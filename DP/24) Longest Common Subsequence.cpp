#include<bits/stdc++.h>
// int f(int ind1, int ind2, string S, string T, vector<vector<int>> &dp){
// 	if(ind1 == 0 || ind2 == 0)
// 		return 0;

// 	if(dp[ind1][ind2] != -1)
// 		return dp[ind1][ind2];
// 	if(S[ind1 - 1] == T[ind2 - 1]){
// 		return dp[ind1][ind2] =  1 + f(ind1 - 1, ind2 - 1, S, T, dp);
// 	}

// 	return dp[ind1][ind2] = max(f(ind1 - 1, ind2, S, T, dp), f(ind1, ind2 - 1, S, T, dp));
// }

int lcs(string S, string T)
{
	//Write your code here
	int N = S.length();
	int M = T.length();
	// vector<vector<int>> dp(N + 1, vector<int> (M + 1, -1));
	// return f(N, M, s, t, dp);
	vector<int> prev(M + 1, 0);
	// for(int ind2 = 0; ind2 <= M; ind2++) prev[ind2] = 0;
	// for(int ind1 = 0; ind1 <= N; ind1++) dp[ind1][0] = 0;

	for(int ind1 = 1; ind1 <= N; ind1++){
		vector<int> curnt(M + 1, 0);
		for(int ind2 = 1; ind2 <= M; ind2++){
			
			if(S[ind1 - 1] == T[ind2 - 1]){
				curnt[ind2] =  1 + prev[ind2 - 1];
				continue;
			}
			curnt[ind2] = max(prev[ind2], curnt[ind2 - 1]);
		}
		prev = curnt;
	}
	return prev[M];
}