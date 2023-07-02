class Solution {
  private:
    int detect_cycle(int src, vector<int> adj[], vector<int> &vis){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src, -1});
        while(!q.empty()){
            int curnt_node = q.front().first;
            int from_node = q.front().second;
            q.pop();
            for(auto i : adj[curnt_node]){
                if(i == from_node)
                    continue;
                else if(vis[i]){
                    return 1;
                }
                else{
                    vis[i] = 1;
                    q.push({i, curnt_node});
                }
            }
        }
        return 0;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(detect_cycle(i, adj, vis) == 1){
                    return 1;
                }
            }
        }
        return 0;
    }
};