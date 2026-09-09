#include<iostream>
using namespace std;
vector<vector<int>>constructAdjencyList(int n,vector<vector<int>>edge){

vector<vector<int>>adjList(n);
for(int i=0;i<edge.size();i++){
    vector<int>list=edge[i];
    int src=list[0];
    int dest=list[1];

    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}
return adjList;

}
void dfs(vector<vector<int>>adjList,vector<int>&ans,vector<bool>&visited,int node){
    ans.push_back(node);
    visited[node]=true;
    for(int i=0;i<adjList[node].size();i++){
        int neigh=adjList[node][i];
        if(visited[neigh]==false){
            dfs(adjList,ans,visited,neigh);
        }
    }
    return ;
}
int main(){
    vector<vector<int>> edges = {
    {0, 1},
    {0, 2},
    {1, 3},
    {1, 4},
    {2, 5},
    {2, 6},
    {4, 7},
    {5, 8}
};

    vector<vector<int>>adjencyList=constructAdjencyList(9,edges);
    vector<bool>visited(9,false);
    vector<int>ans;
    dfs(adjencyList,ans,visited,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}