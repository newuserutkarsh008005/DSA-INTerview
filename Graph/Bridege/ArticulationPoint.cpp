#include<iostream>
#include<set>
using namespace std;
set<int>ans;
void dfs(vector<vector<int>>&adj,vector<int>&dt,vector<int>&mt,int src,int par,int &t){
    dt[src]=mt[src]=++t;
    int child=0;
    for(int i=0;i<adj[src].size();i++){
        int neigh=adj[src][i];

        if(dt[neigh]==-1){
            dfs(adj,dt,mt,neigh,src,t);
            mt[src]=min(mt[src],mt[neigh]);
            if(par!=-1 && mt[neigh]>=dt[src] ){
                child++;
                ans.insert(src);
            }
        }
        else if(neigh!=par){
            mt[src]=min(mt[src],dt[src]);
        }
    }
    if(par==-1 && child>1){
        ans.insert(src);
    }
}

int main(){
    int n = 4;

    int t = 0;

    vector<int> dt(n, -1);
    vector<int> mt(n);

    vector<vector<int>> edge = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3}
    };

    vector<vector<int>> adj(n);

    // Create undirected graph
    for (auto i : edge) {

        int src = i[0];
        int dest = i[1];

        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    // DFS for every component
    for (int i = 0; i < adj.size(); i++) {

        if (dt[i] == -1) {
            dfs(adj, dt, mt, i,-1,t);
        }
    }

    // Print bridges
    cout << "Bridges are:\n";

    
        for (int x : ans) {
            cout << x << " ";
        }

        
    


    return 0;
}