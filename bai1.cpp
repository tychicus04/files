// BAI 1 - KIEM TRA DAY NGOAC DUNG  ( ) [ ] { }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    cin.ignore();                       // bo ky tu xuong dong sau T

    while (t--) {
        string s;
        getline(cin, s);                // xau rong cung hop le -> dung getline

        stack<char> st;
        bool ok = true;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                char need = (c == ')') ? '(' : (c == ']') ? '[' : '{';
                if (st.empty() || st.top() != need) { ok = false; break; }
                st.pop();
            }
            // ky tu khac (dau cach...) -> bo qua
        }
        if (!st.empty()) ok = false;

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
