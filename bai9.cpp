// BAI 10: tong cac "so may man tiep theo" cua moi so trong [a,b]
// So may man = chi gom chu so 4 va 7. next(n) = so may man nho nhat >= n.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<ll> lucky;
    for (int len = 1; len <= 10; len++)                 // 4444444444 > 1e9
        for (int mask = 0; mask < (1 << len); mask++) {
            ll x = 0;
            for (int i = 0; i < len; i++)
                x = x * 10 + (((mask >> (len - 1 - i)) & 1) ? 7 : 4);
            lucky.push_back(x);
        }
    sort(lucky.begin(), lucky.end());

    ll a, b;
    if (!(cin >> a >> b)) return 0;

    ll ans = 0, prev = 0;
    for (ll Lk : lucky) {
        ll lo = max(a, prev + 1), hi = min(b, Lk);      // next(n) == Lk voi n in (prev, Lk]
        if (lo <= hi) ans += (hi - lo + 1) * Lk;
        prev = Lk;
        if (prev >= b) break;
    }
    cout << ans << '\n';
    return 0;
}
