#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> x = {-1, 1, 0, 0};
vector<int> y = {0, 0, -1, 1};

bool check(int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n)
        return false;

    return true;
}

int orangesRotting(vector<vector<int>>& a, int m, int n) {

    queue<pair<int, int>> q;

    int fresh = 0;
    int time = 0;

    // Put all rotten oranges into queue
    // Count all fresh oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (a[i][j] == 2) {
                q.push({i, j});
            }

            if (a[i][j] == 1) {
                fresh++;
            }
        }
    }

    // BFS
    while (!q.empty() && fresh > 0) {

        int size = q.size();

        while (size--) {

            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for (int v = 0; v < 4; v++) {

                int t = i + x[v];
                int u = j + y[v];

                bool ch = check(t, u, m, n);

                if (ch == true && a[t][u] == 1) {

                    // Fresh orange becomes rotten
                    a[t][u] = 2;

                    fresh--;

                    q.push({t, u});
                }
            }
        }

        // One minute completed
        time++;
    }

    if (fresh == 0)
        return time;

    return -1;
}

int main() {

    int m = 3;
    int n = 3;

    vector<vector<int>> matrix = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int ans = orangesRotting(matrix, m, n);

    cout << ans << endl;

    return 0;
}
