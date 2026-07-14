// BAI 8 - NHIP CHUNG KHOAN (stock span)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<int> b(n);
        stack<int> st;                  // luu chi so, gia GIAM dan tu day len

        for (int i = 0; i < n; i++) {
            // bo het cac ngay co gia <= a[i]  (chung deu bi "phu" boi ngay i)
            while (!st.empty() && a[st.top()] <= a[i]) st.pop();
            b[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
    }
    return 0;
}
