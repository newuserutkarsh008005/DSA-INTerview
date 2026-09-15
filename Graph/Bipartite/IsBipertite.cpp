#include<iostream>
using namespace std;
bool ans=true;
void dfs(vector<vector<int>>&a,int node,int c,vector<int>&col){
col[node]=c;
for(int x=0;x<a[node].size();x++){
    int nei=a[node][x];
    if(col[nei]==-1){
        dfs(a,nei,1-c,col);
    }
    if(col[nei]!=-1 && col[nei]==c){
        ans=false;
    }
}
}
int main (){
    vector<vector<int>>a={{1,2,3},{0,2},{0,1,3},{0,2}};
    int n=a.size();
    vector<int>col(n,-1);
    for(int i=0;i<n;i++){
        if(col[i]==-1){
            dfs(a,i,0,col);
        }
    }
cout<<ans<<" ";
    return 0;
}