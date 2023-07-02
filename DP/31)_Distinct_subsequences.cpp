class Solution {
private:
    int f(int i, int j, string S1, string S2, vector<vector<int>> &dp){
        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        if(S1[i - 1] == S2[j - 1])
            return dp[i][j] = f(i - 1, j - 1, S1, S2, dp) + f(i - 1, j, S1, S2, dp);
        return dp[i][j] = f(i - 1, j, S1, S2, dp);
    }
public:
    int numDistinct(string s, string t) {
        int N = s.size();
        int M = t.size();
        vector<vector<int>> dp(N + 1, vector<int>(M + 1, - 1));
        return f(N, M, s, t, dp);
    }
};

class Solution {
public:
    int numDistinct(string S1, string S2) {
        int N = S1.size();
        int M = S2.size();
        vector<double> prev(M+ 1, 0);

        prev[0] = 1;
        for(int i = 1; i <= N; i++){
            vector<double> curnt(M + 1, 0);
            curnt[0] = 1;
            for(int j = 1; j <= M; j++){
                if(S1[i - 1] == S2[j - 1])
                    curnt[j] = prev[j - 1] + prev[j];
                else curnt[j] = prev[j];
            }
            prev = curnt;
        }

        return (int)prev[M];
        
    }
};