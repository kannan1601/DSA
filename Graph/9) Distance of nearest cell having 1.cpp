//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int N = grid.size();
	    int M = grid[0].size();
	    
	    vector<vector<int>> ans(N, vector<int>(M, 0));
	    vector<vector<int>> vis(N, vector<int>(M, 0));
	    queue<pair<pair<int, int>, int>> q;
	    for(int i = 0; i < N; i++){
	        for(int j = 0; j < M; j++){
	            if(grid[i][j] == 1){
	                q.push({{i, j}, 0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    
	    //BFS
	    int delta_row[] = {-1, 0, 1, 0};
	    int delta_col[] = {0, 1, 0, -1};
	    while(!q.empty()){
            int curnt_row = q.front().first.first;
            int curnt_col = q.front().first.second;
            int distance = q.front().second;
            ans[curnt_row][curnt_col] = distance;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nxt_row = curnt_row + delta_row[i];
                int nxt_col = curnt_col + delta_col[i];
                if(nxt_row >= 0 && nxt_row < N && nxt_col >= 0 && nxt_col < M && !vis[nxt_row][nxt_col]){
                    vis[nxt_row][nxt_col] = 1;
                    q.push({{nxt_row, nxt_col}, distance + 1});
                }
            }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends