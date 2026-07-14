// BAI 3 - DAY NGOAC DUNG DAI NHAT (longest valid parentheses)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);

        // giu lai chi cac ky tu ngoac
        string a;
        for (char c : s) if (c == '(' || c == ')') a += c;

        stack<int> st;                  // luu chi so
        st.push(-1);                    // "moc" bien trai
        int best = 0;

        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) st.push(i);              // moc moi
                else best = max(best, i - st.top());     // do dai doan hop le
            }
        }
        cout << best << '\n';
    }
    return 0;
}
