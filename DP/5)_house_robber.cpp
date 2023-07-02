// same as question 4
#include <bits/stdc++.h> 
 long long int f(vector<int> &dp){
    long long int prev = dp[0];
    long long int prev2 = 0;
    for(int i = 1; i < dp.size(); i++){
        long long int pick = dp[i];
        if(i > 1){
            pick += prev2;
        }
        long long int notPick = 0 + prev;
        long long int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
long long int houseRobber(vector<int>& house)
{
    int N = house.size();
    if(N == 1) return house[0];
    vector<int> dp1, dp2;
    for(int i = 0; i < N; i++){
        if(i != 0)
            dp1.push_back(house[i]);
        if(i != N - 1)
            dp2.push_back(house[i]);
    }
    return max(f(dp1), f(dp2));
}