// BAI 6 - TINH GIA TRI BIEU THUC TIEN TO (prefix), toan hang 1 chu so
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        string e;
        cin >> e;

        stack<double> st;
        // tien to: duyet TU PHAI SANG TRAI
        for (int i = (int)e.size() - 1; i >= 0; i--) {
            char c = e[i];
            if (isdigit((unsigned char)c)) {
                st.push(c - '0');
            } else if (c=='+'||c=='-'||c=='*'||c=='/') {
                if (st.size() < 2) break;
                double a = st.top(); st.pop();          // toan hang trai (o tren)
                double b = st.top(); st.pop();          // toan hang phai
                double r = 0;
                if (c == '+') r = a + b;
                else if (c == '-') r = a - b;
                else if (c == '*') r = a * b;
                else r = (b != 0 ? a / b : 0);
                st.push(r);
            }
        }
        double res = st.empty() ? 0 : st.top();
        long long ans = (long long)trunc(res + (res >= 0 ? 1e-9 : -1e-9));
        cout << ans << '\n';
    }
    return 0;
}
