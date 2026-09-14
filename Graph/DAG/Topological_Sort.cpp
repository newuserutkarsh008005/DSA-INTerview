#include<iostream>
using namespace std;


int main(){
   vector<vector<int>> edge = {
    {0,1},
    {1,2},
    {3,4},
    {4,5},
    {6,7}
};

int n = 8;

vector<vector<int>> a(n,vector<int>(n,0));
vector<int>ind(n,0);
queue<int>q;
for(int i=0;i<edge.size();i++){
   int src=edge[i][0];
   int dest=edge[i][1];
   a[src][dest]=1;
   ind[dest]++;
}
vector<int>ans;
for(int i=0;i<ind.size();i++){
    if(ind[i]==0){
        q.push(i);
    }
}
while(!q.empty()){
    int node=q.front();
    q.pop();
    for(int x=0;x<a[node].size();x++){
        if(a[node][x]==1){
        ind[x]--;
        if(ind[x]==0){
            q.push(x);
        }
    }}
    ans.push_back(node);
}
for(int i:ans){
    cout<<i<<" ";
}
    return 0;
}