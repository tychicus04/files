// BAI 7 - TIEN TO: N token cach nhau boi dau cach, so nhieu chu so / so am
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
        vector<string> tok(n);
        for (auto &x : tok) cin >> x;

        stack<long long> st;
        for (int i = n - 1; i >= 0; i--) {
            const string &s = tok[i];
            // la toan tu <=> do dai 1 va thuoc + - * /
            bool isOp = (s.size() == 1) &&
                        (s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/');
            if (!isOp) {
                st.push(stoll(s));                      // "-10" van la so
            } else {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();
                long long r = 0;
                if (s[0] == '+') r = a + b;
                else if (s[0] == '-') r = a - b;
                else if (s[0] == '*') r = a * b;
                else r = (b != 0 ? a / b : 0);          // chia nguyen
                st.push(r);
            }
        }
        cout << st.top() << '\n';
    }
    return 0;
}
