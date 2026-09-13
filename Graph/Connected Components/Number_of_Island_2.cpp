#include<iostream>
using namespace std;
vector<int>x={-1,1,0,0};
vector<int>y={0,0,-1,1};
bool check(int i,int j,int m,int n){
    if(i<0 || j<0 || i>=m|| j>=n)return true;
    return false;
}

void dfs(vector<vector<int>>& a, int i,int j,int m,int n,vector<vector<bool>>&visited){
visited[i][j]=true;
for(int v=0;v<4;v++){
bool ch=check(i+x[v],j+y[v],m,n);
int t=i+x[v];
int u=j+y[v];
if(ch==false && a[t][u]==1 && visited[t][u]==false){
    dfs(a,t,u,m,n,visited);
}


}
}
int numberOfIsland(vector<vector<int>>& a,int m,int n){
vector<vector<bool>>visited(m,vector<bool>(n,false));
int ans=0;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(a[i][j]==1 && visited[i][j]==false){
            dfs(a,i,j,m,n,visited);
            ans++;
        }
    }
}
return ans;
}

int main(){
    int m=3;
    int n=3;
    vector<vector<int>> positions={
    {0,0},
    {0,1},
    {1,2},
    {2,1}
};
vector<vector<int>>matrix(m,vector<int>(n,0));
vector<int>ans;
for(int i=0;i<positions.size();i++){
    int src=positions[i][0];
    int dest=positions[i][1];
    matrix[src][dest]=1;
    int island=numberOfIsland(matrix,m,n);
    ans.push_back(island);
}
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  } 
return 0;
    }
