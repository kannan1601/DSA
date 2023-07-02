#include <bits/stdc++.h> 
int lcs(string &S, string &T){
	int N = S.length();
	int M = T.length();
	int ans = 0;
	vector<vector<int>> dp(N + 1, vector<int> (M + 1, 0));
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(S[i - 1] == T[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
				continue;
			}
			dp[i][j] = 0;
		}
	}

	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= M; j++){
			cout << dp[i][j] << " "; 
		}
		cout << '\n';
	}

	return ans;
}