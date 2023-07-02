//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void dfs(int node, vector<int> &vis, vector<int> &ans, vector<int> adj[]){
        vis[node] = 1;
        for(auto adj_node : adj[node]){
            if(!vis[adj_node]){
                ans.push_back(adj_node);
                dfs(adj_node, vis, ans, adj);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> ans;
        ans.push_back(0);
        dfs(0, vis, ans, adj);
        return ans;
    }
};

