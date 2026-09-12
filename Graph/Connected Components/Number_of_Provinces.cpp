#include<iostream>
using namespace std;
void dfs(vector<vector<int>>&edges,vector<bool>& visited,int node,int n){
    visited[node]=true;
for(int i=0;i<n;i++){
    if(edges[node][i]==1 && visited[i]==false){
        dfs(edges,visited,i,n);
    }
}
return ;
}

int main(){
    vector<vector<int>>edges={
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    int n=edges.size();
    vector<bool>visited(n,false);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<edges[0].size();j++){
            if(edges[i][j]==1 && visited[i]==false){
                dfs(edges,visited,i,n);
                ans++;
            }
        }
    }
    cout<<ans<<" ";

    return 0;
}