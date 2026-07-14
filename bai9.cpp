// BAI 9 - NHAY SANG PHAI: dp tren "next greater element"
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];

    vector<int> nxt(n + 2, 0);          // cot gan nhat ben phai co chieu cao lon hon
    vector<long long> dp(n + 2, 0);     // so buoc nhay toi da khi xuat phat tu i
    stack<int> st;

    for (int i = n; i >= 1; i--) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        nxt[i] = st.empty() ? 0 : st.top();
        dp[i] = (nxt[i] == 0) ? 0 : dp[nxt[i]] + 1;
        st.push(i);
    }

    string out;
    while (q--) {
        int x;
        cin >> x;
        out += to_string(dp[x]);
        out += '\n';
    }
    cout << out;
    return 0;
}
