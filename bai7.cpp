#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    while (cin >> n) {                       // read until EOF (handles multi-test files)
        vector<long long> A(n), dp(n);
        long long total = 0;
        for (int i = 0; i < n; i++) { cin >> A[i]; total += A[i]; dp[i] = A[i]; }
        // dp[i] = best (mover - opponent) difference on A[i..j] as j grows
        for (int j = 1; j < n; j++)
            for (int i = j - 1; i >= 0; i--)
                dp[i] = max(A[i] - dp[i + 1], A[j] - dp[i]);
        long long diff = dp[0];
        long long ti = (total + diff) / 2, teo = (total - diff) / 2;
        cout << ti << " " << teo << "\n";
    }
    return 0;
}