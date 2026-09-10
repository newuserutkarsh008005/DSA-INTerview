#include<iostream>
using namespace std;
vector<vector<int>>constructAdjencyMatrix(int n,vector<vector<int>>edge){
    vector<vector<int>>adjMat(n);
    for(int i=0;i<edge.size();i++){
        vector<int>list=edge[i];
        int source=list[0];
        int dest=list[1];
        adjMat[source].push_back(dest);
        adjMat[dest].push_back(source);
        
    }
    return  adjMat;
}
int main (){
    vector<vector<int>>edges={{0,1},{0,2},{0,3},{1,3},{2,1},{3,1},{3,2}};
    vector<vector<int>>adjencyList=constructAdjencyMatrix(4,edges);
    for(int i=0;i<adjencyList.size();i++){
        cout<<i <<"->";
        for(int j=0;j<adjencyList[i].size();j++){
            cout<<adjencyList[i][j]<<",";
        }
        cout<<endl;
    }
    return 0;
}