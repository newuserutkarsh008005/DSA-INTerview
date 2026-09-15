

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
using namespace std;
int main(){
    vector<vector<int>> t = {
    {1, 2, 4},
    {1, 3, 2},
    {1, 4, 7},
    {2, 3, 1},
    {2, 5, 5},
    {2, 6, 10},
    {3, 2, 3},
    {3, 4, 4},
    {3, 6, 8},
    {3, 7, 6},
    {4, 6, 3},
    {4, 8, 5},
    {5, 6, 2},
    {5, 9, 7},
    {5, 10, 4},
    {6, 7, 1},
    {6, 9, 3},
    {6, 11, 6},
    {7, 8, 2},
    {7, 11, 4},
    {7, 12, 8},
    {8, 10, 3},
    {8, 12, 2},
    {9, 10, 1},
    {9, 13, 5},
    {10, 11, 2},
    {10, 14, 6},
    {11, 12, 1},
    {11, 14, 3},
    {12, 13, 2},
    {12, 15, 5},
    {13, 14, 1},
    {13, 15, 3},
    {14, 15, 2},
    {4, 5, 6}
};

int n = 16;
int k = 1;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<vector<pair<int,int>>>a(n);
for(int i=0;i<t.size();i++){
    int sr=t[i][0];
    int de=t[i][1];
    int wt=t[i][2];
    a[sr].push_back({de,wt});
    a[de].push_back({sr,wt});
}
vector<int>dist(n,INT_MAX);
dist[k]=0;
pq.push({0,k});
while(!pq.empty()){
auto pr=pq.top();
pq.pop();
int di=pr.first;
int node=pr.second;

//checkinng 
if(di>dist[node])continue;
for(int j=0;j<a[node].size();j++){
    auto nd=a[node][j];
    int neigh=nd.first;
    int dis=nd.second;
    if(dis+di<dist[neigh]){
        dist[neigh]=dis+di;
        pq.push({dis+di,neigh});
    }
}

}
for(int i:dist){
    cout<<i<<" ";
}



    return 0;
}