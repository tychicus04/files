// BAI 11: So buoc di chuyen it nhat cua quan ma tren ban co 8x8 tu ST den EN.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dx[8] = {1,1,-1,-1,2,2,-2,-2};
    int dy[8] = {2,-2,2,-2,1,-1,1,-1};

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;
        int sx = s1[0] - 'a', sy = s1[1] - '1';
        int ex = s2[0] - 'a', ey = s2[1] - '1';

        vector<vector<int>> dist(8, vector<int>(8, -1));
        queue<pair<int,int>> q;
        dist[sx][sy] = 0;
        q.push({sx, sy});
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == ex && y == ey) break;
            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        cout << dist[ex][ey] << '\n';
    }
    return 0;
}
