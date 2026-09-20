#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int n = 3;

    vector<vector<int>> rel = {
        {1, 3},
        {2, 3}
    };

    vector<int> time = {3, 2, 5};

    vector<vector<int>> a(n + 1);
    vector<int> ind(n + 1, 0);
    vector<int> dp(n + 1, 0);

    // Create graph and calculate indegree
    for (int i = 0; i < rel.size(); i++) {
        int src = rel[i][0];
        int dest = rel[i][1];

        a[src].push_back(dest);
        ind[dest]++;
    }

    queue<int> q;

    // Add nodes with indegree 0
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    // Topological sort + DP
    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (int x = 0; x < a[node].size(); x++) {

            int neigh = a[node][x];

            ind[neigh]--;

            dp[neigh] = max(
                dp[neigh],
                dp[node] + time[node - 1]
            );

            if (ind[neigh] == 0) {
                q.push(neigh);
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i] + time[i - 1]);
    }

    cout << ans << endl;

    return 0;
}
