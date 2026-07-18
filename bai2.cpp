// BAI 2: '(' dung -> 0, ')' dung -> 1, ngoac sai -> -1
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
        int n = (int)s.size();

        vector<char> matched(n, 0);
        vector<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push_back(i);
            else if (s[i] == ')') {
                if (!st.empty()) { matched[st.back()] = 1; matched[i] = 1; st.pop_back(); }
            }
        }

        string out;
        out.reserve(n * 2);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')      out += matched[i] ? "0"  : "-1";
            else if (s[i] == ')') out += matched[i] ? "1"  : "-1";
            else                  out += s[i];
        }
        cout << out << '\n';
    }
    return 0;
}
