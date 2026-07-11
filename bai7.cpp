#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if (!(cin >> n)) return 0;
    vector<long long> a(n), pre(n + 1, 0);
    for (int i = 0; i < n; i++) { cin >> a[i]; pre[i + 1] = pre[i] + a[i]; }

    // dp[i][j] = max score the player to move can get from a[i..j] (both play optimally)
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = a[i];
    for (int len = 2; len <= n; len++)
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            long long pickL = a[i] + (pre[j + 1] - pre[i + 1]) - dp[i + 1][j];
            long long pickR = a[j] + (pre[j]     - pre[i])     - dp[i][j - 1];
            dp[i][j] = max(pickL, pickR);
        }

    long long ti = dp[0][n - 1];         // Ti moves first
    cout << ti << " " << (pre[n] - ti) << "\n";
    return 0;
}
