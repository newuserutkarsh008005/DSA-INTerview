#include<iostream>
using namespace std;
bool dfs(vector<vector<int>>&a,vector<bool>&visited,int cn,int parent,int n){
visited[cn]=true;

for(int i=0;i<n;i++){
   if(a[cn][i]==1){
    if(visited[i]==false){
        if(dfs(a,visited,i,cn,n))return true;
    }
    else if(parent !=i){
        return true;
    }}

   
}
return false;
}

int main(){

    vector<vector<int>>edge={{0,1},{1,2},{2,0}};
    int n=3;
    vector<vector<int>>a(n,vector<int>(n,0));
    vector<bool>visited(n,false);
    for(int i=0;i<edge.size();i++){
        int src=edge[i][0];
        int dest=edge[i][1];

        a[src][dest]=1;
        a[dest][src]=1;
    
    }
bool ans=false;

    for(int i=0;i<n;i++){
        if(visited[i]==false){
            ans=dfs(a,visited,i,-1,n);
        }
        if(ans==true){
            
            break;
        }
    }
    cout<<ans;

    return 0;

}