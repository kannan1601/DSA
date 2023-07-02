class Solution {
    private:
     void dfs(int node, vector<int> adj[], vector<int> &vis){
         vis[node] = 1;
         for(auto it : adj[node]){
             if(!vis[it]){
                 dfs(it, adj, vis);
             }
         }
     }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V + 1];
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }
        
        vector<int> vis(V + 1, 0);
        int ans = 0;
        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                ans++;
                dfs(i, adj, vis);
            }
        }
        return ans;
    }
};