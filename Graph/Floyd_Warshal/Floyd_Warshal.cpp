#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    vector<tuple<int,int,int>> edges = {
        {0,1,3},
        {0,2,5},
        {0,3,7},
        {1,0,8},
        {1,2,2},
        {2,0,5},
        {2,3,1},
        {3,0,2}
    };

    int n = 4;

    vector<vector<int>> fw(n, vector<int>(n, 1e9));

    // Distance from a node to itself
    for (int i = 0; i < n; i++) {
        fw[i][i] = 0;
    }

    // Add edges
    for (auto [src, dest, wt] : edges) {
        fw[src][dest] = wt;
    }

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fw[i][j] = min(fw[i][j],
                                fw[i][k] + fw[k][j]);
            }
        }
    }

    // Print answer
    for (auto i : fw) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
