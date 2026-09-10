#include<iostream>
using namespace std;
vector<vector<int>>constructAdjencyMatrix(int n,vector<vector<int>>edge){
    vector<vector<int>>adjMat(n,vector<int>(n,0));
    for(int i=0;i<edge.size();i++){
        vector<int>list=edge[i];
        int source=list[0];
        int dest=list[1];
        adjMat[source][dest]=1;
        // adjMat[dest][source]=1;             // For Undirected Graph
    }
    return  adjMat;
}
int main (){
    vector<vector<int>>edges={{0,1},{0,2},{0,3},{1,3},{2,1},{3,1},{3,2}};
    vector<vector<int>>adjencyMatrix=constructAdjencyMatrix(4,edges);
    for(int i=0;i<adjencyMatrix.size();i++){
        for(int j=0;j<adjencyMatrix[i].size();j++){
            cout<<adjencyMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}