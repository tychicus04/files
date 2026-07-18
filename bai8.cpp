// BAI 8: Nuoc do tu phia thuong luu (ben trai). Tinh V[i] = the tich nuoc can
// de nuoc tran qua buc tuong thu i, roi tra loi truy van K bang tim kiem nhi phan.
//
// GIA THIET DINH DANG (xem ghi chu trong cau tra loi):
//   T                      so bo test
//   N                      so buc tuong
//   L[1..N]                vi tri (tang dan)
//   H[1..N]                do cao
//   Q                      so truy van
//   K (Q dong)             luu luong nuoc
// In ra CHI SO (1..N) cua buc tuong cuoi cung bi tran; 0 neu khong buc nao.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Rec { ll h, pos, wsum, water; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<ll> L(n + 1), H(n + 1);
        for (int i = 1; i <= n; i++) cin >> L[i];
        for (int i = 1; i <= n; i++) cin >> H[i];

        vector<ll> V(n + 1, 0);
        vector<Rec> st;
        ll W = 0;                              // tong nuoc dang chua

        for (int i = 1; i <= n; i++) {
            ll h = H[i], pos = L[i], wsum = 0;
            // cac buc tuong thap hon bi nhan chim -> gop ho nuoc
            while (!st.empty() && st.back().h <= h) {
                W    -= st.back().water;
                wsum += st.back().wsum + st.back().h;
                st.pop_back();
            }
            ll leftPos = st.empty() ? 0 : st.back().pos;   // ho tu [leftPos, pos-1]
            ll size    = pos - leftPos;
            ll water   = h * size - (st.empty() ? 0 : h) - wsum;
            if (water < 0) water = 0;
            st.push_back({h, pos, wsum, water});
            W += water;
            V[i] = max(W, V[i - 1]);
        }

        int q; cin >> q;
        while (q--) {
            ll k; cin >> k;
            int lo = 1, hi = n, ans = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (V[mid] <= k) { ans = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            cout << ans << '\n';           // doi thanh L[ans] neu de bai can VI TRI
        }
    }
    return 0;
}
