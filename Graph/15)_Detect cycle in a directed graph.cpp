//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int node, vector<int> &vis, vector<int> &Path_Vis, vector<int> adj[]){
        vis[node] = 1;
        Path_Vis[node] = 1;
        for(auto neighbors : adj[node]){
            if(!vis[neighbors]){
                if(dfs(neighbors, vis, Path_Vis, adj) == true)
                    return true;
            }
            else if(Path_Vis[neighbors])
                return true;
        }
        
        Path_Vis[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> vis(V, 0);
        vector<int> Path_Vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, vis, Path_Vis, adj) == true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends