// BAI 4: kiem tra cap ngoac () va [] trong cau van ban
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (T--) {
        string s;
        if (!getline(cin, s)) s.clear();

        vector<char> st;
        bool ok = true;
        for (char c : s) {
            if (c == '(' || c == '[') st.push_back(c);
            else if (c == ')') {
                if (st.empty() || st.back() != '(') { ok = false; break; }
                st.pop_back();
            } else if (c == ']') {
                if (st.empty() || st.back() != '[') { ok = false; break; }
                st.pop_back();
            }
        }
        if (!st.empty()) ok = false;
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
