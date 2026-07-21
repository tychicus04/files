// BAI 10: Chi phi di chuyen = |hieu gia tri hai o|. Tim tong chi phi nho nhat tu (1,1) den (N,M)
// voi 3 huong: xuong, phai, cheo xuong-phai. (Luon co duong di nen khong can in -1.)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> A(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> A[i][j];

        vector<vector<ll>> dp(n, vector<ll>(m, INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                ll best = INF;
                if (i > 0) best = min(best, dp[i - 1][j] + llabs(A[i - 1][j] - A[i][j]));
                if (j > 0) best = min(best, dp[i][j - 1] + llabs(A[i][j - 1] - A[i][j]));
                if (i > 0 && j > 0) best = min(best, dp[i - 1][j - 1] + llabs(A[i - 1][j - 1] - A[i][j]));
                dp[i][j] = best;
            }
        }
        cout << dp[n - 1][m - 1] << '\n';
    }
    return 0;
}
