// BAI 1: Duyet do thi vo huong theo chieu sau (DFS) bat dau tai dinh u.
// Input: dong dau T (so bo test). Moi bo test: dong dau |V| |E| u,
//        tiep theo la |E| dong, moi dong la mot canh (a b).
// Output: moi bo test in ra "DFS(u) = " roi danh sach cac dinh theo thu tu duyet.
// Khi duyet, cac dinh ke duoc xet theo thu tu tang dan.
#include <bits/stdc++.h>
using namespace std;

static vector<vector<int>> adj;
static vector<char> vis;
static vector<int> order;

void dfs(int u) {
    vis[u] = 1;
    order.push_back(u);
    for (int v : adj[u])
        if (!vis[v]) dfs(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int V, E, u;
        cin >> V >> E >> u;
        adj.assign(V + 1, {});
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= V; i++)
            sort(adj[i].begin(), adj[i].end());

        vis.assign(V + 1, 0);
        order.clear();
        dfs(u);

        cout << "DFS(" << u << ") = ";
        for (size_t i = 0; i < order.size(); i++) {
            if (i) cout << ' ';
            cout << order[i];
        }
        cout << '\n';
    }
    return 0;
}
