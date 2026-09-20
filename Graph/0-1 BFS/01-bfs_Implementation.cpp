#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

vector<int> zeroOneBfs(
    vector<vector<pair<int,int>>>& adj,
    int n,
    int src
) {
    vector<int> ans(n, 1e9);

    ans[src] = 0;

    deque<int> q;

    q.push_front(src);

    while(!q.empty()) {

        int node = q.front();
        q.pop_front();

        for(int i = 0; i < adj[node].size(); i++) {

            auto nei = adj[node][i];

            int neighbNode = nei.first;
            int weight = nei.second;

            // Relaxation
            if(ans[node] + weight < ans[neighbNode]) {

                ans[neighbNode] = ans[node] + weight;

                // IMPORTANT:
                // Only push if distance was improved

                if(weight == 0) {
                    q.push_front(neighbNode);
                }
                else {
                    q.push_back(neighbNode);
                }
            }
        }
    }

    return ans;
}

int main() {

    int n = 5;

    vector<tuple<int, int, int>> edges = {
        {0, 1, 0},
        {0, 2, 1},
        {1, 2, 1},
        {1, 3, 0},
        {2, 4, 1},
        {3, 4, 1}
    };

    vector<vector<pair<int,int>>> adj(n);

    for(auto [src, dest, weight] : edges) {
        adj[src].push_back({dest, weight});
    }

    vector<int> ans = zeroOneBfs(adj, n, 0);

    for(int i : ans) {
        cout << i << " ";
    }

    cout << '\n';

    return 0;
}