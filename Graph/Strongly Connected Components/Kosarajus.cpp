#include<iostream>
using namespace std;
void Tdfs(vector<vector<int>>&adj,int node,stack<int>&st,vector<bool>&visited){
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++){
        int neigh=adj[node][i];
        if(visited[neigh]==false){
            Tdfs(adj,neigh,st,visited);
        }

    }
    st.push(node);
}
 vector<vector<int>> Transpose(vector<vector<int>>&edge){
    int n=edge.size();
    vector<vector<int>>tadj(n);
    for(int i=0;i<n;i++){
        int src=edge[i][0];
        int dest=edge[i][1];
        tadj[dest].push_back(src);
    }
    return tadj;

}
void dfs(vector<vector<int>>&adj,vector<bool>&vis,int src){
vis[src]=true;
cout<<src<<" ";
for(int i=0;i<adj[src].size();i++){
    int neigh=adj[src][i];
    if(vis[neigh]==false){
        dfs(adj,vis,neigh);
    }
}
}
int main(){
    int n = 8;

vector<vector<int>> edges = {
    {0,1},
    {1,2},
    {2,0},
    {2,3},
    {3,4},
    {4,5},
    {5,3},
    {5,6},
    {6,7},
    {7,6}
};

stack<int>st;
vector<bool>visited(n,false);

vector<vector<int>>adj(n);
for(int i=0;i<edges.size();i++){
    int src=edges[i][0];
    int dest=edges[i][1];
    adj[src].push_back(dest);
}
for(int i=0;i<adj.size();i++){
   
        
        if(visited[i]==false){
            Tdfs(adj,i,st,visited);
        }
    
}
visited.assign(n,false);
vector<vector<int>>ans=Transpose(edges);
while(!st.empty()){
    int node=st.top();
    st.pop();
    if(visited[node]==false){
        dfs(ans,visited,node);
        cout<<endl;
    }
}
    return 0;
}