#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& a, int node, int parent,
         vector<bool>& visited, int n) {

    visited[node] = true;

    for (int x = 0; x < n; x++) {

        if (a[node][x] == 0)
            continue;

        // Ignore the edge back to our parent
        if (x == parent)
            continue;

        // Already visited => cycle
        if (visited[x])
            return true;

        if (dfs(a, x, node, visited, n))
            return true;
    }

    return false;
}

int main() {

    int n = 3;

    vector<vector<int>> edge = {
        {0, 1},
        {1, 2},
        {2, 0}
    };

    vector<vector<int>> a(n, vector<int>(n, 0));

    for (auto& e : edge) {
        int sou = e[0];
        int dest = e[1];

        a[sou][dest] = 1;
        a[dest][sou] = 1;
    }

    vector<bool> visited(n, false);

    bool ans = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(a, i, -1, visited, n)) {
                ans = true;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
