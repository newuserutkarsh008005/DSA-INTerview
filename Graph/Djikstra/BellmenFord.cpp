#include<iostream>
using namespace std;
struct Edge {
int u,v,wt;
};

vector<int>BellmanFord(int v,vector<Edge>&edge,int src){
    vector<int>dist(v,1e9);
    dist[src]=0;
    for(int i=0;i<v-1;i++){
        bool changed=false;
        for(auto x:edge){
            int sc=x.u;
            int dest=x.v;
            int wt=x.wt;
            if(dist[sc]!=1e9 && dist[sc]+wt<dist[dest]){
                changed=true;
                dist[dest]=dist[sc]+wt;
            }
        }
        if(!changed){
            break;
        }
    }
    for(auto x:edge){
        int u=x.u;
        int v=x.v;
        int w=x.wt;
        if(dist[u]!=1e9 && dist[u]+w<dist[v]){
            cout<<"Negative weight determined";
            return {};
        }
    }
    return dist;
}
int main(){
vector<Edge> edges = {
    {0, 1, 6},
    {0, 2, 7},
    {1, 2, 8},
    {1, 3, 5},
    {1, 4, -4},
    {2, 3, -3},
    {2, 4, 9},
    {3, 1, -2},
    {4, 0, 2},
    {4, 3, 7},

    // Negative cycle
    {3, 4, -10}
};
int src=0;
int v=5;
vector<int>distance=BellmanFord(v,edges,src);
for(int i :distance){
    cout<<i<<" ";
}
    return 0;
}