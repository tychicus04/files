// BAI 5 - TINH GIA TRI BIEU THUC HAU TO (postfix), toan hang 1 chu so
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
        for (char c : e) {
            if (isdigit((unsigned char)c)) {
                st.push(c - '0');
            } else if (c=='+'||c=='-'||c=='*'||c=='/') {
                if (st.size() < 2) break;               // bieu thuc loi
                double b = st.top(); st.pop();          // toan hang phai
                double a = st.top(); st.pop();          // toan hang trai
                double r = 0;
                if (c == '+') r = a + b;
                else if (c == '-') r = a - b;
                else if (c == '*') r = a * b;
                else r = (b != 0 ? a / b : 0);
                st.push(r);
            }
        }
        double res = st.empty() ? 0 : st.top();
        // "chi lay gia tri phan nguyen" -> cat phan thap phan (huong ve 0)
        long long ans = (long long)trunc(res + (res >= 0 ? 1e-9 : -1e-9));
        cout << ans << '\n';
    }
    return 0;
}
