#include<iostream>
#include<vector>
using namespace std;

vector<int>x={-1,1,0,0};

vector<int>y={0,0,-1,1};

bool check(int i,int j,int m,int n){
    return !(i<0|| j<0|| i>=m|| j>=n);
}
void dfs(vector<vector<int>>&grid,int i,int j,int &oC,vector<vector<bool>>&visited,int m,int n){
oC--;
visited[i][j]=true;
for(int t=0;t<4;t++){
    int newRow=i+x[t];
    int newCol=j+y[t];
    if(check(newRow,newCol,m,n) && grid[newRow][newCol]==1 && visited[newRow][newCol]==false){
        dfs(grid,newRow,newCol,oC,visited,m,n);
        
    }
}


}
    int numEnclaves(vector<vector<int>>& grid) {
        int oC=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)oC++;
            }
        }
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        if(grid[i][0]==1 && visited[i][0]==false){
            dfs(grid,i,0,oC,visited,m,n);
        }
        if(grid[i][n-1]==1 && visited[i][n-1]==false){
            dfs(grid,i,n-1,oC,visited,m,n);
        }
    }
    for(int j=0;j<n;j++){
        if(grid[0][j]==1 && visited[0][j]==false){
            dfs(grid,0,j,oC,visited,m,n);
        }
        if(grid[m-1][j]==1 && visited[m-1][j]==false){
            dfs(grid,m-1,j,oC,visited,m,n);
        }
    }
return oC;
    }

    int main(){
        vector<vector<int>>grid={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
        cout<<numEnclaves(grid);
        return 0;
    }