#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; if (!(cin >> T)) return 0;
    const long long INF = LLONG_MAX / 4;

    while (T--) {
        int n; cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

        // For each position the final value is one of {a-1, a, a+1}.
        // (It is provably enough to change each element by at most 1.)
        long long pv[3], pd[3];                 // previous values / dp
        pv[0] = a[0] - 1; pv[1] = a[0]; pv[2] = a[0] + 1;
        pd[0] = b[0];     pd[1] = 0;    pd[2] = b[0];

        for (int i = 1; i < n; i++) {
            long long cv[3] = { a[i] - 1, a[i], a[i] + 1 };
            long long cc[3] = { b[i], 0, b[i] };
            long long cd[3];
            for (int k = 0; k < 3; k++) {
                long long best = INF;
                for (int p = 0; p < 3; p++)
                    if (cv[k] != pv[p]) best = min(best, pd[p]);   // adjacent must differ
                cd[k] = cc[k] + best;
            }
            for (int k = 0; k < 3; k++) { pv[k] = cv[k]; pd[k] = cd[k]; }
        }
        cout << min({ pd[0], pd[1], pd[2] }) << "\n";
    }
    return 0;
}
