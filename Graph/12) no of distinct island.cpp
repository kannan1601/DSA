//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

void dfs(int i, int j, vector<pair<int, int>> &tmp, vector<vector<int>> &vis, vector<vector<int>>& grid,
int N, int M, int row0, int col0){
    vis[i][j] = 1;
    tmp.push_back({i - row0, j - col0});
    
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    for(int dir = 0; dir < 4; dir++){
        int nxt_row = i + drow[dir];
        int nxt_col = j + dcol[dir];
        if(nxt_row >= 0 && nxt_row < N && nxt_col >= 0 && nxt_col < M && grid[nxt_row][nxt_col] == 1 && !vis[nxt_row][nxt_col]){
            dfs(nxt_row, nxt_col, tmp, vis, grid, N, M, row0, col0);
        }
    }
}

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>> vis(N, vector<int>(M, 0));
        set<vector<pair<int, int>>> S;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int,int>> tmp;
                    dfs(i, j, tmp, vis, grid, N, M, i, j);
                    S.insert(tmp);
                }
            }
        }
        return S.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends