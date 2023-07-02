class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>& image, int color, int delRow[],
    int delCol[], int inicolor){
        ans[row][col] = color;
        int N = image.size();
        int M = image[0].size();
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && image[nrow][ncol] == inicolor 
            && ans[nrow][ncol] != color){
                ans[nrow][ncol] = color;
                dfs(nrow, ncol, ans, image, color, delRow, delCol, inicolor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         vector<vector<int>> ans = image;
        int inicolor = image[sr][sc];
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, color, delRow, delCol, inicolor);
        return ans;
    }
};