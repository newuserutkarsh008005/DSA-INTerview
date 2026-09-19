#include<iostream>
using namespace std;

class Dsu{
public:
int n;
vector<int>par,rank;
Dsu(int n){
    for(int i=0;i<n;i++){
        par.push_back(i);
        rank.push_back(0);
    }

}

void unionBy(int a,int b){
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

int find(int a){
if(par[a]==a){
    return a;
}
return par[a]=find(par[a]);
}
bool check(int a,int b){
    return find(a)==find(b);
}
void getInfo(){
    for(int i:par){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i:rank){
        cout<<i<<" ";
    }

}
};

int main(){
   vector<vector<int>> input = {
    {1, 0, 1},
    {1, 1, 2},
    {2, 0, 2},
    {1, 3, 4},
    {1, 5, 6},
    {2, 3, 6},
    {1, 4, 5},
    {2, 3, 6},
    {2, 0, 7},
    {2, 5, 6}
};

int n=8;
Dsu disj(n);
for(auto i:input){
    int opr=i[0];
    int n1=i[1];
    int n2=i[2];
    if(opr==1){
        disj.unionBy(n1,n2);
    }
    else{
        cout<<disj.check(n1,n2) << " "<<endl;
    }

}
cout<<"All operation done"<<" "<<endl;
disj.getInfo();
    return 0;
}