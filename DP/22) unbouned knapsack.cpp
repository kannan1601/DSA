#include <bits/stdc++.h> 
// int f(int ind, int wt, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
//     if(ind == 0){
//         if(weight[0] <= wt){
//             return (wt / weight[0]) * profit[0];
//         }
//         return 0;
//     }
//     if(dp[ind][wt] != -1)
//         return dp[ind][wt];
//     int notpick = 0 + f(ind - 1, wt, profit, weight, dp);
//     int pick = -1e9;
//     if(weight[ind] <= wt){
//         pick = profit[ind] + f(ind, wt - weight[ind], profit, weight, dp);
//     }
//     return dp[ind][wt] = max(pick, notpick);
// }
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    // vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    vector<int>prev(w + 1, 0);
    // return f(n - 1, w, profit, weight, dp);
    for(int wt = weight[0]; wt <= w; wt++){
        prev[wt] = (wt / weight[0]) * profit[0];
    }
    
    for(int ind = 1; ind < n; ind++){
        vector<int> curnt(w + 1, 0);
        for(int wt = 0; wt <= w; wt++){
            int notpick = 0 + prev[wt];
            int pick = -1e9;
            if(weight[ind] <= wt){
                pick = profit[ind] + curnt[wt - weight[ind]];
            }
            curnt[wt] = max(pick, notpick);
        }
        prev = curnt;
    }
    return prev[w];
}
