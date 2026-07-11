#include <bits/stdc++.h>
using namespace std;

int K, N;
string S, cur;
set<string> res;

void gen(int start) {
    if ((int)cur.size() == K) { res.insert(cur); return; }
    for (int i = start; i < N; i++) { cur.push_back(S[i]); gen(i + 1); cur.pop_back(); }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        cin >> S >> K;
        N = S.size(); res.clear(); cur.clear();
        gen(0);                       // choose K positions i1<i2<...<iK, keep order
        for (auto &x : res) cout << x << "\n";   // set => increasing (equal length)
    }
    return 0;
}
