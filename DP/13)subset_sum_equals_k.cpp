#include <bits/stdc++.h> 
bool f(int i, int N, int sum, vector<int> &arr){
    if(i >= N)
    {
        if(sum == 0)
            return true;
        return false;
    }
    if(sum == 0)
        return true;
    
    if(f(i + 1, N, sum - arr[i], arr) == true)
        return true;
    if(f(i + 1, N, sum, arr) == true)
        return true;
    return false;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    return f(0, n, k, arr);
}

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k + 1, false);
    prev[0] = true;
    prev[arr[0]] = true;
    for(int ind = 1; ind < n; ind++){
        vector<bool> curnt(k + 1, false);
        curnt[0] = true;
        for(int target = 1; target <= k; target++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind] <= target)
                take = prev[target - arr[ind]];
            curnt[target] = take || notTake;
        }
        prev = curnt;
    }
    return prev[k];
}