#include<iostream>
using namespace std;
int main(){
    int n=5;
    vector<vector<int>> edges = {
    {0, 1, 2},
    {1, 2, 3},
    {3, 4, 5}
};
vector<vector<pair<int,int>>>adj(n);
for(int i=0;i<edges.size();i++){
    int src=edges[i][0];
    int dest=edges[i][1];
    int wt=edges[i][2];

    adj[src].push_back({dest,wt});
    adj[dest].push_back({src,wt});
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
vector<bool>visited(n,false);
int sum=0;
pq.push({0,0});
while(!pq.empty()){
    auto pt=pq.top();
    pq.pop();
    int wt=pt.first;
    int node=pt.second;
    if(visited[node]==true)continue;
    visited[node]=true;
    sum+=wt;
    for(int j=0;j<adj[node].size();j++){
        auto nt=adj[node][j];
        int neigh=nt.first;
        int wts=nt.second;
        if(visited[neigh]==false){
            pq.push({wts,neigh});
        }
        
    }
}
cout<<sum;
    return 0;
}