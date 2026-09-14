#include<iostream>
using namespace std;
bool ans=false;

bool dfs(vector<vector<int>>& a,vector<bool>&visited,vector<bool>&path,int cn){
visited[cn]=true;
path[cn]=true;
for(int i=0;i<a[cn].size();i++){
    if(a[cn][i]==1){
        if(visited[i]==false){
            if(dfs(a,visited,path,i))return true;
        }
        else{
            if(path[i]==true){
            
                return true;
            }
        }
    }

}
ans=false;
path[cn]=false;
return ans;

}
int main(){

    vector<vector<int>>edge={{0,1},{0,3},{1,2},{2,3}};
    int n=4;
    vector<vector<int>>a(n,vector<int>(n,0));
    vector<bool>visited(n,false);
    vector<bool>curr(n,false);
    for(int i=0;i<edge.size();i++){
        int src=edge[i][0];
        int dest=edge[i][1];

        a[src][dest]=1;
    }

    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(dfs(a,visited,curr,i)){
                ans=true;
                break;
            }
        }
    }
    cout<<ans;
    return 0;

}