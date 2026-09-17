#include<iostream>
using namespace std;

vector<int>x={-1,1,0,0};
vector<int>y={0,0,-1,1};
bool check(int i,int j,int m,int n){
    if(i<0||j<0||i>=m||j>=n)return false;
    return true;
}
bool bfs(vector<vector<int>>& grid,int m,int n,int money){
    if(grid[0][0]>money)return false;
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    

    queue<pair<int,int>>q;
    q.push({0,0});
    visited[0][0]=true;
    while(!q.empty()){
        auto pair=q.front();
        q.pop();
        int row=pair.first;
        int col=pair.second;
        if(row==m-1 && col==n-1)return true;
        for(int i = 0; i < 4; i++){
    int newRow = row + x[i];
    int newCol = col + y[i];

    if(check(newRow, newCol, m, n) &&
       !visited[newRow][newCol] &&
       money >= grid[newRow][newCol]) {

        visited[newRow][newCol] = true;
        q.push({newRow, newCol});
    }
}

        
    }
    return false;
    

}
    int swimInWater(vector<vector<int>>& grid) {
        int low=grid[0][0];
        int high=grid[0][0];
        int ans=low;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for (int j=0;j<grid[i].size();j++){
                high=max(high,grid[i][j]);
            }
        }
        while(low<=high){
            int mid=(low+high)/2;

            if(bfs(grid,m,n,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }

    int main(){
        vector<vector<int>>grid={{0,2},{1,3}};
        cout<<swimInWater(grid);

        return 0;
    }