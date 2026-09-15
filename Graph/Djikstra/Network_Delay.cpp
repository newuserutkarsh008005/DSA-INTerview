#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    int ans = 0;

    vector<vector<pair<int, int>>> a(n + 1);

    for(auto i : times) {
        int src = i[0];
        int des = i[1];
        int wt = i[2];

        a[src].push_back({des, wt});
    }

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> dist(n + 1, INT_MAX);

    dist[k] = 0;
    pq.push({0, k});

    while(!pq.empty()) {

        auto nd = pq.top();
        pq.pop();

        int dis = nd.first;
        int node = nd.second;

        if(dis > dist[node])
            continue;

        for(int j = 0; j < a[node].size(); j++) {

            auto nei = a[node][j];

            int neigh = nei.first;
            int d = nei.second;

            if(d + dis < dist[neigh]) {

                dist[neigh] = d + dis;

                pq.push({d + dis, neigh});
            }
        }
    }

    for(int i = 1; i < dist.size(); i++) {
        ans = max(ans, dist[i]);
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {

    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int n = 4;
    int k = 2;

    int answer = networkDelayTime(times, n, k);

    cout << "Network Delay Time: " << answer << endl;

    return 0;
}
