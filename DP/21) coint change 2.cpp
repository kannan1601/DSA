#include<bits/stdc++.h>
// long f(int ind, int target, int denominations[], vector<vector<long>> &dp){
//     if(ind == 0){
//         return (target % denominations[0] == 0);
//     }
//     if(dp[ind][target] != -1)
//         return dp[ind][target];
//     long notpick = f(ind - 1, target, denominations, dp);
//     long pick = 0;
//     if(denominations[ind] <= target){
//         pick = f(ind, target - denominations[ind],denominations, dp);
//     }
//     return dp[ind][target] = pick + notpick;
// }

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    // vector<vector<long>> dp(n, vector<long>(value + 1, 0));

    // return f(n - 1, value, denominations, dp);

    vector<long> prev(value + 1, 0);

    for(int target = 0; target <= value; target++){
        if(target % denominations[0] == 0)
            prev[target] = 1;
    }
    
    for(int ind = 1; ind < n; ind++){
        vector<long> curnt(value + 1, 0);
        for(int target = 0; target <= value; target++){
            long notpick = prev[target];
            long pick = 0;
            if(denominations[ind] <= target){
                pick = curnt[target - denominations[ind]];
            }
            curnt[target] = pick + notpick;
        }
        prev = curnt;
    }
    return prev[value];
}