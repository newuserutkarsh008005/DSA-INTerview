#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

void TarjanDfs(
    vector<vector<int>>& adj,
    vector<int>& dt,
    vector<int>& mt,
    int& t,
    int src,
    int par
) {
    // Discovery time
    dt[src] = ++t;

    // Initially low time = discovery time
    mt[src] = dt[src];

    for (int i = 0; i < adj[src].size(); i++) {

        int node = adj[src][i];

        // If node is not visited
        if (dt[node] == -1) {

            TarjanDfs(adj, dt, mt, t, node, src);

            // Update low time
            mt[src] = min(mt[src], mt[node]);

            // Bridge condition
            if (mt[node] > dt[src]) {
                ans.push_back({src, node});
            }
        }

        // Back edge
        else if (node != par) {
            mt[src] = min(mt[src], dt[node]);
        }
    }
}

int main() {

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
            TarjanDfs(adj, dt, mt, t, i, -1);
        }
    }

    // Print bridges
    cout << "Bridges are:\n";

    for (auto i : ans) {

        for (int x : i) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}
