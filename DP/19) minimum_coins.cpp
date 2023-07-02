#include <bits/stdc++.h> 
// int f(int ind, int t, vector<int> &num, vector<vector<int>> &dp){
//     if(ind == 0){
//         if(t % num[0] == 0)
//             return t / num[0];
//         return 1e9;
//     }
//     if(dp[ind][t] != -1)
//         return dp[ind][t];
//     int notpick = 0 + f(ind - 1, t, num, dp);
//     int pick = 1e9;
//     if(num[ind] <= t)
//         pick = 1 + f(ind, t - num[ind], num, dp);
//     return dp[ind][t] = min(pick, notpick);
// }
int minimumElements(vector<int> &num, int target)
{
    // Write your code here.
    int N = num.size();
    vector<int>prev(target + 1, 1e9);

    for(int t = 0; t <= target; t++){
        if(t % num[0] == 0)
            prev[t] = t / num[0];
    }
    for(int ind = 1; ind < N; ind++){
        vector<int> curnt(target + 1, 1e9);
        for(int t = 0; t <= target; t++){
            int notpick = 0 + prev[t];
            int pick = 1e9;
            if(num[ind] <= t)
                pick = 1 + curnt[t - num[ind]];
            curnt[t] = min(pick, notpick);
        }
        prev = curnt;
    }
    if(prev[target] == 1e9)
        return -1;
    return prev[target];
}