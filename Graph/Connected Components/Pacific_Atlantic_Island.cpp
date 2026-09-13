
   #include<iostream>
   using namespace std;
   
   
   
   bool left(int i, int j, int m, int n) {
        if (j - 1 < 0) return false;
        return true;
    }

    bool right(int i, int j, int m, int n) {
        if (j + 1 == n) return false;
        return true;
    }

    bool top(int i, int j, int m, int n) {
        if (i - 1 < 0) return false;
        return true;
    }

    bool bottom(int i, int j, int m, int n) {
        if (i + 1 == m) return false;
        return true;
    }

    void dfs(vector<vector<int>>& heights,
             int i,
             int j,
             int m,
             int n,
             vector<vector<bool>>& visit) {

        visit[i][j] = true;

        bool l = left(i, j, m, n);
        bool r = right(i, j, m, n);
        bool t = top(i, j, m, n);
        bool b = bottom(i, j, m, n);

        
        if (l && heights[i][j - 1] >= heights[i][j] &&
            !visit[i][j - 1]) {

            dfs(heights, i, j - 1, m, n, visit);
        }

        
        if (r && heights[i][j + 1] >= heights[i][j] &&
            !visit[i][j + 1]) {

            dfs(heights, i, j + 1, m, n, visit);
        }

        
        if (t && heights[i - 1][j] >= heights[i][j] &&
            !visit[i - 1][j]) {

            dfs(heights, i - 1, j, m, n, visit);
        }

        
        if (b && heights[i + 1][j] >= heights[i][j] &&
            !visit[i + 1][j]) {

            dfs(heights, i + 1, j, m, n, visit);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> topLeft(
            m, vector<bool>(n, false)
        );

        vector<vector<bool>> botRight(
            m, vector<bool>(n, false)
        );

       
        
        for (int i = 0; i < m; i++) {
            topLeft[i][0] = true;
        }

        
        for (int j = 0; j < n; j++) {
            topLeft[0][j] = true;
        }

        
        
        for (int i = 0; i < m; i++) {
            botRight[i][n - 1] = true;
        }

        
        for (int j = 0; j < n; j++) {
            botRight[m - 1][j] = true;
        }

        
        // Top row
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, m, n, topLeft);
        }

        // Left column
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, m, n, topLeft);
        }

       

        // Bottom row
        for (int j = 0; j < n; j++) {
            dfs(heights, m - 1, j, m, n, botRight);
        }

        // Right column
        for (int i = 0; i < m; i++) {
            dfs(heights, i, n - 1, m, n, botRight);
        }

        
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (topLeft[i][j] && botRight[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    int main(){

        vector<vector<int>>heights={{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
       vector<vector<int>>ans=pacificAtlantic(heights);
       int m=ans.size();
       int n=ans[0].size();
       for(int i=0;i<m;i++){
        cout<<"[";
        for(int j=0;j<n;j++){
            cout<<" "<<ans[i][j]<<" ";
        }
        cout<<"]";
       }
    return 0;
   }