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
void bfs(vector<vector<int>>& adjList,vector<int> & ans,vector<bool>&visited,int node){
    queue<int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
    int no=q.front();
visited[no]=true;
    q.pop();
    ans.push_back(no);
    for(int i=0;i<adjList[no].size();i++){
        int nei=adjList[no][i];
        if(visited[nei]==false){

            q.push(nei);
        }
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
    bfs(adjencyList,ans,visited,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}