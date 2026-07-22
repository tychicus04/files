// BAI 3: Do thi vo huong N dinh, M canh.
// Voi moi dinh tu 2 den N, in ra 2 dong:
//   - Dong 1: duong di tu dinh 1 den dinh do theo DFS.
//   - Dong 2: duong di tu dinh do ve 1 theo BFS (duong ngan nhat).
// Neu khong co duong di thi in ra -1.
#include <bits/stdc++.h>
using namespace std;

static vector<vector<int>> adj;
static vector<int> dpar;     // cha trong cay DFS xuat phat tu 1
static vector<char> dvis;

void dfs(int u) {
    dvis[u] = 1;
    for (int v : adj[u])
        if (!dvis[v]) { dpar[v] = u; dfs(v); }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    adj.assign(N + 1, {});
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());

    // DFS tu dinh 1
    dpar.assign(N + 1, -1);
    dvis.assign(N + 1, 0);
    dfs(1);

    // BFS tu dinh 1 (de lay duong ngan nhat)
    vector<int> bpar(N + 1, -1);
    vector<char> bvis(N + 1, 0);
    queue<int> q;
    q.push(1);
    bvis[1] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : adj[x])
            if (!bvis[y]) { bvis[y] = 1; bpar[y] = x; q.push(y); }
    }

    for (int v = 2; v <= N; v++) {
        // Dong 1: duong di 1 -> v theo DFS
        if (!dvis[v]) {
            cout << "-1\n";
        } else {
            vector<int> p;
            for (int x = v; x != -1; x = dpar[x]) p.push_back(x);
            reverse(p.begin(), p.end());
            for (size_t i = 0; i < p.size(); i++) {
                if (i) cout << ' ';
                cout << p[i];
            }
            cout << '\n';
        }
        // Dong 2: duong di v -> 1 theo BFS
        if (!bvis[v]) {
            cout << "-1\n";
        } else {
            vector<int> p;
            for (int x = v; x != -1; x = bpar[x]) p.push_back(x); // da la v ... 1
            for (size_t i = 0; i < p.size(); i++) {
                if (i) cout << ' ';
                cout << p[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
