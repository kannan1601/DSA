class Solution {

private:
    bool dfs(int node, vector<int> &vis, vector<int> &check, vector<int> &pathVis, vector<vector<int>>& graph){
        vis[node] = 1;
        pathVis[node] = 1;
       
        for(auto neighbors : graph[node]){
            if(!vis[neighbors]){
                if(dfs(neighbors, vis, check, pathVis, graph) == true){
                    return true;
                }
            }
            else if(pathVis[neighbors] == 1)
                return true;
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
}

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> check(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> safeNodes;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, check, pathVis, graph);
            }
        }
        for(int i = 0; i < V; i++){
            if(check[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;


    }
};