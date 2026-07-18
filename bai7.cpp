// BAI 7: dem cap (i,j), i<j sao cho moi phan tu giua i va j deu <= min(A[i],A[j])
// Ngan xep don dieu khong tang, gom nhom cac gia tri bang nhau.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char ibuf[1 << 16];
static size_t ipos = 0, ilen = 0;
static inline int gc() {
    if (ipos == ilen) { ilen = fread(ibuf, 1, sizeof(ibuf), stdin); ipos = 0; if (ilen == 0) return -1; }
    return (unsigned char)ibuf[ipos++];
}
static inline bool readInt(ll &out) {
    int c = gc();
    while (c != -1 && (c < '0' || c > '9') && c != '-') c = gc();
    if (c == -1) return false;
    bool neg = false;
    if (c == '-') { neg = true; c = gc(); }
    ll x = 0;
    while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = gc(); }
    out = neg ? -x : x;
    return true;
}

int main() {
    ll n;
    if (!readInt(n)) return 0;

    vector<pair<ll,ll>> st;            // (gia tri, so luong)
    st.reserve((size_t)n + 1);
    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        ll a;
        if (!readInt(a)) break;
        while (!st.empty() && st.back().first < a) { ans += st.back().second; st.pop_back(); }
        if (!st.empty() && st.back().first == a) {
            ans += st.back().second;
            ll c = st.back().second + 1;
            st.pop_back();
            if (!st.empty()) ans++;     // phan tu cao hon o duoi cung nhin thay
            st.push_back({a, c});
        } else {
            if (!st.empty()) ans++;
            st.push_back({a, 1});
        }
    }
    printf("%lld\n", ans);
    return 0;
}
