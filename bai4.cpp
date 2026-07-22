// BAI 4: Dem so dinh tru (articulation point) va so canh cau (bridge)
// cua do thi vo huong (co the khong lien thong). Dung thuat toan Tarjan.
// Input: dong dau N M ; M dong tiep theo, moi dong 1 canh (u v).
// Output: hai so nguyen: so dinh tru va so canh cau.
#include <bits/stdc++.h>
using namespace std;

static vector<vector<pair<int,int>>> adj; // (dinh ke, id canh)
static vector<int> disc, low;
static vector<char> isArt;
static int timer_ = 0, bridges = 0;

// dung id canh de xu ly dung canh boi (parallel edges) va khuyen (self-loop)
void dfs(int u, int pe) {
    disc[u] = low[u] = ++timer_;
    int children = 0;
    for (auto &e : adj[u]) {
        int v = e.first, id = e.second;
        if (id == pe) continue;          // bo qua canh vua di xuong
        if (!disc[v]) {
            children++;
            dfs(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) bridges++;                 // canh cau
            if (pe != -1 && low[v] >= disc[u]) isArt[u] = 1; // dinh tru (khong phai goc)
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (pe == -1 && children >= 2) isArt[u] = 1;             // goc la dinh tru neu co >= 2 con
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    adj.assign(N + 1, {});
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    disc.assign(N + 1, 0);
    low.assign(N + 1, 0);
    isArt.assign(N + 1, 0);
    for (int s = 1; s <= N; s++)
        if (!disc[s]) dfs(s, -1);

    int artCount = 0;
    for (int i = 1; i <= N; i++) artCount += isArt[i];

    cout << artCount << ' ' << bridges << '\n';
    return 0;
}
