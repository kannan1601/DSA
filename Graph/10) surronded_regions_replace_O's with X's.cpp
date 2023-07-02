int delta_row[] = {-1, 0, 1, 0};
int delta_column[] = {0, 1, 0, -1};
class Solution{
private:
void dfs(int i, int j, vector<vector<char>> &mat, int n, int m, vector<vector<int>> &vis){
    vis[i][j] = 1;
    for(int i = 0; i < 4; i++){
        int next_row = i + delta_row[i];
        int next_col = j + delta_column[j];
        if(next_row >= 0 && next_row < n && next_col >= 0 && next_col < m && mat[next_row][next_col] == 'O' 
        && !vis[next_row][next_col]){
            vis[next_row][next_col] = 1;
            dfs(next_row, next_col, mat, n, m, vis);
        }
    }
}
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat)
    {
        // code here
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
       
        for(int j = 0; j < m; j++){
             // first row
            if(mat[0][j] == 'O' && !vis[0][j]){
                dfs(0, j, mat, n, m, vis);
            }
            
            //last row
             if(mat[n - 1][j] == 'O' && !vis[n - 1][j]){
                dfs(n - 1, j, mat, n, m, vis);
            }
        }
        
        
        for(int i = 0; i < n; i++){
            //first column
            if(mat[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, mat, n, m, vis);
            }
            
            //last column
            if(mat[i][m - 1] == 'O' && !vis[i][m - 1]){
                dfs(i, m - 1, mat, n, m, vis);
            }
        }
        
       
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 'O' && !vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
        
    }