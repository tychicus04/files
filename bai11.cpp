#include <bits/stdc++.h>
using namespace std;

static int LG[100005];

int main() {
    for (int i = 2; i <= 100000; i++) LG[i] = LG[i / 2] + 1;
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N; long long K;
        scanf("%d %lld", &N, &K);
        vector<int> A(N);
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        int H = LG[N] + 1;
        vector<vector<int>> sp(H, vector<int>(N));
        for (int i = 0; i < N; i++) sp[0][i] = A[i];
        for (int k = 1; k < H; k++)
            for (int i = 0; i + (1 << k) <= N; i++)
                sp[k][i] = __gcd(sp[k-1][i], sp[k-1][i + (1 << (k-1))]);
        auto qry = [&](int l, int r) -> long long {
            int k = LG[r - l + 1];
            return __gcd(sp[k][l], sp[k][r - (1 << k) + 1]);
        };

        // GCD of A[l..r] is non-increasing as r grows -> "gcd <= K" is monotone.
        // Find first r where gcd(l..r) <= K; if it equals K -> shortest for this l.
        int ans = INT_MAX;
        for (int l = 0; l < N && ans > 1; l++) {
            int lo = l, hi = N - 1, pos = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (qry(l, mid) <= K) { pos = mid; hi = mid - 1; }
                else lo = mid + 1;
            }
            if (pos != -1 && qry(l, pos) == K) ans = min(ans, pos - l + 1);
        }
        printf("%d\n", ans == INT_MAX ? -1 : ans);
    }
    return 0;
}
