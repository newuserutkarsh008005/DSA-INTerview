#include<iostream>
using namespace std;
bool isValid(int i,int j,int m, int n){
    if(i==0 || j==0 ||i==m-1 || j==n-1)return true;
    return false;
}
bool dfs(vector<vector<char>>&edge,vector<vector<bool>>& visited,int i,int j,int m,int n,vector<pair<int,int>>&reg){
if(i<0|| j<0||i>=m||j>=n)return false;
if(edge[i][j]!='O' || visited[i][j]==true)return false;
visited[i][j]=true;
reg.push_back({i,j});
bool bound=isValid(i,j,m,n);
bool left=dfs(edge,visited,i-1,j,m,n,reg);
bool right=dfs(edge,visited,i+1,j,m,n,reg);
bool up=dfs(edge,visited,i,j-1,m,n,reg);
bool down=dfs(edge,visited,i,j+1,m,n,reg);

return bound||left||right||up||down;



}
int main(){
vector<vector<char>> edge = {
    {'X','O','X','X','X','X','X','X','X'},
    {'X','O','O','X','O','O','O','X','X'},
    {'X','X','O','X','X','O','X','X','X'},
    {'X','O','X','X','X','O','X','O','X'},
    {'X','O','O','X','X','X','O','O','X'},
    {'X','X','X','X','O','X','X','X','X'},
    {'X','X','O','O','O','X','X','X','X'},
    {'X','X','X','X','X','X','X','O','X'},
    {'X','X','X','X','X','X','X','X','X'}
};
int m=edge.size();
int n=edge[0].size();
vector<vector<bool>>visited(m,vector<bool>(n,false));
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(edge[i][j]=='O' &&  visited[i][j]==false){
                vector<pair<int,int>>reg;
                bool ans=dfs(edge,visited,i,j,m,n,reg);
                if(ans==false){
                    for(auto it:reg){
                        int x=it.first;
                        int y=it.second;
                        edge[x][y]='X';
                    }
                }
        }
    }
}
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cout<<edge[i][j]<< " ";
    }
    cout<<endl;
}
    return 0;
}