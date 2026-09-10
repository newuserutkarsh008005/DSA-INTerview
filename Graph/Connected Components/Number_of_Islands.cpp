#include<iostream>
using namespace std;
vector<int>x={-1,1,0,0};
vector<int>y={0,0,-1,1};
vector<vector<int>>adjMatrix(vector<vector<int>>edges,int n){
    vector<vector<int>>mat(n,vector<int>(n,0));
    for(int i=0;i<edges.size();i++){
        int src=edges[i][0];
        int dest=edges[i][1];
        mat[src][dest]=1;
        mat[dest][src]=1;
    }
    return mat;
}
bool isValid(int i,int j,int m,int n){
if(i<0 || i>=m || j<0 || j>=n){
    return false;
}
return true;
}
void dfs(vector<vector<char>>&adjMatrix,vector<vector<bool>>& visited,int i,int j,int m,int n){
visited[i][j]=true;
for(int t=0;t<4;t++){
    bool valid=isValid(i+x[t],j+y[t],m,n);
    if(valid && adjMatrix[i+x[t]][j+y[t]]=='1' &&visited[i+x[t]][j+y[t]]==false){
        dfs(adjMatrix,visited,i+x[t],j+y[t],m,n);
    }
}
return ;



}

int main(){
vector<vector<int>> edges = {
    {0,1},
    {0,4},
    {1,2},
    {1,5},
    {2,3},
    {3,6},
    {4,5},
    {4,7},
    {5,6},
    {5,8},
    {7,8}
};

vector<vector<int>>adjMat=adjMatrix(edges,9);
vector<vector<char>> grid = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
};

vector<vector<bool>>visited(4,vector<bool>(5,false));
int ans=0;
for(int i=0;i<4;i++){
    for(int j=0;j<5;j++){
        if(grid[i][j]=='1' && visited[i][j]!=true){
            dfs(grid,visited,i,j,4,5);
            ans++;
        }
    }
}
cout<<ans;
    return 0;
}