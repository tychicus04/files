// BAI 5: dem cach thay '?' de duoc bieu thuc ngoac dung co BAC = K
// bac = do sau long nhau lon nhat  =>  dem(bac <= K) - dem(bac <= K-1)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static string S;

// so cach thay '?' de duoc day ngoac dung voi do sau toi da <= m
ll countAtMost(int m) {
    if (m < 0) return 0;
    int n = (int)S.size();
    vector<ll> dp(m + 2, 0), nd(m + 2, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        fill(nd.begin(), nd.end(), 0LL);
        for (int d = 0; d <= m; d++) {
            if (!dp[d]) continue;
            if (S[i] == '(' || S[i] == '?') { if (d + 1 <= m) nd[d + 1] += dp[d]; }
            if (S[i] == ')' || S[i] == '?') { if (d - 1 >= 0) nd[d - 1] += dp[d]; }
        }
        dp.swap(nd);
    }
    return dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) return 0;
    if (!(cin >> S)) S.clear();

    if (S.size() % 2 != 0) { cout << 0 << '\n'; return 0; }
    cout << countAtMost(K) - countAtMost(K - 1) << '\n';
    return 0;
}
