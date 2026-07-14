// BAI 1: DANH SO THU TU CAP DAU NGOAC
// Dung stack: moi '(' duoc cap 1 so moi (tang dan), ')' lay so cua '(' o dinh stack.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    cin.ignore();                       // bo qua ky tu xuong dong sau T

    while (T--) {
        string s;
        if (!getline(cin, s)) break;

        vector<int> st;                 // stack cac so hieu cua '(' dang mo
        int cnt = 0;                    // so cap ngoac da gap
        string out;

        for (char c : s) {
            if (c == '(') {
                st.push_back(++cnt);
                out += to_string(cnt);
                out += ' ';
            } else if (c == ')') {
                if (!st.empty()) {
                    out += to_string(st.back());
                    out += ' ';
                    st.pop_back();
                }
            }
        }
        if (!out.empty()) out.pop_back();   // bo dau cach cuoi
        cout << out << '\n';
    }
    return 0;
}
