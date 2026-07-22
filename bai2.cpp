// BAI 2: Tim duong di tu dinh s den tat ca cac dinh con lai bang BFS.
// Input: dong dau T (so bo test). Moi bo test gom 2 dong:
//        dong 1: N M s ; dong 2: cac bo doi (u, v) la cac canh.
// Output: voi moi dinh tu 1 den N (tru dinh s), in ra duong di ngan nhat
//         tu s den dinh do. Neu khong co duong di thi in ra "No path".
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, M, s;
        cin >> N >> M >> s;
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= N; i++)
            sort(adj[i].begin(), adj[i].end());

        vector<int> par(N + 1, -1);
        vector<char> vis(N + 1, 0);
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int y : adj[x])
                if (!vis[y]) { vis[y] = 1; par[y] = x; q.push(y); }
        }

        for (int v = 1; v <= N; v++) {
            if (v == s) continue;
            if (!vis[v]) { cout << "No path\n"; continue; }
            vector<int> path;
            for (int x = v; x != -1; x = par[x]) path.push_back(x);
            reverse(path.begin(), path.end());
            for (size_t i = 0; i < path.size(); i++) {
                if (i) cout << ' ';
                cout << path[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
