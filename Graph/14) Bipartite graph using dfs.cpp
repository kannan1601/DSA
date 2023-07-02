//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool dfs(int start, vector<int> adj[], vector<int> &color, int paintedcolor){
        color[start] = paintedcolor;
        for(auto neighbor : adj[start]){
            if(color[neighbor] == -1){
                // color[neighbor] = !color[start];
                if(dfs(neighbor, adj, color, !color[start]) == false) return false;
            }
            else if(color[neighbor] == color[start]){
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1){
	            if(dfs(i, adj, color, 0) == false)
	                return false;
	        }
	    }
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends