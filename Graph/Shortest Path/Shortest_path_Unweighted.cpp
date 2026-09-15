#include<iostream>
using namespace std;
int main(){
    vector<vector<int>> graph = {
    {1, 2},
    {0, 3, 4},
    {0, 4},
    {1, 5},
    {1, 2, 5},
    {3, 4}
};

int src = 5;
int n=6;
vector<int>ans(n,0);
vector<bool>visited(n,false);
queue<pair<int,int>>q;
q.push({src,0});
visited[src]=true;
while(!q.empty()){
    auto pr=q.front();
    q.pop();
    int node=pr.first;
    int dist=pr.second;
    ans[node]=dist;
    for(int i=0;i<graph[node].size();i++){
        int neigh=graph[node][i];
        if(visited[neigh]==false){
            visited[neigh]=true;
            q.push({neigh,dist+1});
        }
    }
}
for(int i:ans){
    cout<<i<<" ";
}



    return 0;
}