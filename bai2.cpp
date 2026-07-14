// BAI 2 - DANH SO THU TU CAP DAU NGOAC
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    cin.ignore();

    string out;
    while (t--) {
        string s;
        getline(cin, s);

        stack<int> st;
        int cnt = 0;                    // so cap ngoac da mo
        string line;

        for (char c : s) {
            if (c == '(') {
                st.push(++cnt);         // mo ngoac -> cap moi
                line += to_string(cnt);
                line += ' ';
            } else if (c == ')') {
                if (!st.empty()) {      // dong ngoac -> lay so cua cap tuong ung
                    line += to_string(st.top());
                    line += ' ';
                    st.pop();
                }
            }
        }
        if (!line.empty()) line.pop_back();
        out += line;
        out += '\n';
    }
    cout << out;
    return 0;
}
