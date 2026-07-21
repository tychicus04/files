// BAI 6: Cot i to vang A[i] o tren, xanh M-A[i] o duoi. Hinh chu nhat cung mau lon nhat
// = max(dien tich lon nhat trong bieu do cot A[], dien tich lon nhat trong bieu do cot (M-A[])).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll largestRectArea(const vector<ll> &h) {
    int n = (int)h.size();
    vector<int> st; st.reserve(n + 1);
    ll best = 0;
    for (int i = 0; i <= n; i++) {
        ll cur = (i == n) ? -1 : h[i];
        while (!st.empty() && h[st.back()] >= cur) {
            ll height = h[st.back()];
            st.pop_back();
            int left = st.empty() ? -1 : st.back();
            ll width = i - left - 1;
            best = max(best, height * width);
        }
        st.push_back(i);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll M, N;
    if (!(cin >> M >> N)) return 0;
    vector<ll> A(N), B(N);
    for (ll i = 0; i < N; i++) { cin >> A[i]; B[i] = M - A[i]; }

    ll ans = max(largestRectArea(A), largestRectArea(B));
    cout << ans << '\n';
    return 0;
}
