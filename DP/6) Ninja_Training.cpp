#include<bits/stdc++.h>
using namespace std;

int f(int day, int last_task, vector<vector<int>> &A,  vector<vector<int>> &dp){
  if(day == 0){
    int maxi = INT_MIN;
    for(int task = 0; task < 3; task++){
      if(task != last_task){
        maxi = max(maxi, A[0][task]);
      }
    }   
    return maxi;      
  }

  if(dp[day][last_task] != -1)
    return dp[day][last_task];

  
  int maxi = INT_MIN;
  for(int task = 0; task < 3; task++){
    if(task != last_task){
      int point = A[day][task] + f(day - 1, task, A, dp);
      maxi = max(maxi, point);
    }
  }
  
  return dp[day][last_task] = maxi;
}

int solve(){
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(3, 0));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 3; j++){
      cin >> A[i][j];
  }
 }
  vector<vector<int>> dp(N + 1, vector<int>(4, -1));
  return f(N - 1, 3, A, dp);
  
}
int main(){
  cout << solve() <<"\n";
}