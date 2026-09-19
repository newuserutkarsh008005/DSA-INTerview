#include<iostream>
using namespace std;

class DJS{
public:
int n;
vector<int>par,rank;
DJS(int n){
    for(int i=0;i<n;i++){
        par.push_back(i);
        rank.push_back(0);
    }

}
void dsu(int a,int b){
int parA=find(a);
int parB=find(b);
if(parA==parB)return;
if(rank[parA]==rank[parB]){
    par[parB]=parA;
    rank[parA]++;
}
else if(rank[parA]>rank[parB]){
    par[parB]=parA;
}
else{
    par[parA]=parB;
}
    
}
int find(int x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
}


};
int main(){
    int v= 6;

vector<vector<int>> edges = {
    {0, 1, 4},
    {0, 2, 4},
    {1, 2, 2},
    {1, 3, 5},
    {2, 3, 8},
    {2, 4, 10},
    {3, 4, 2},
    {3, 5, 6},
    {4, 5, 3}
};
sort(edges.begin(),edges.end(),[](auto &a ,auto &b){
    return a[2]<b[2];
});
DJS ds(v);
int minCost=0;
for(auto i:edges){
    int src=i[0];
    int dest=i[1];
    int wt=i[2];
   
    if(ds.find(src)!=ds.find(dest)){ // Diff Set
        minCost+=wt;
        ds.dsu(src,dest);
        v--;
         if(v==1)break;
    }
}
cout<<minCost<<" "<<endl;

    return 0;

}