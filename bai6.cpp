#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<string> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];   // read numbers as strings (keep original form)

    set<string> res;
    for (int mask = 1; mask < (1 << N); mask++) {   // every non-empty subset
        string s;
        for (int i = 0; i < N; i++) if (mask & (1 << i)) s += a[i];  // order preserved
        res.insert(move(s));
    }
    for (auto &x : res) cout << x << "\n";      // lexicographic order
    return 0;
}
