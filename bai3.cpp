#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<string> names;
vector<int> idx;

void gen(int start, int cnt) {
    if (cnt == K) {
        for (int i = 0; i < K; i++) { if (i) cout << ' '; cout << names[idx[i]]; }
        cout << "\n";
        return;
    }
    for (int i = start; i < (int)names.size(); i++) { idx[cnt] = i; gen(i + 1, cnt + 1); }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    set<string> s;                    // distinct names, sorted lexicographically
    for (int i = 0; i < N; i++) { string x; cin >> x; s.insert(x); }
    for (auto &x : s) names.push_back(x);
    idx.assign(max(K, 1), 0);
    if (K <= (int)names.size()) gen(0, 0);
    return 0;
}
