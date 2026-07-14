// BAI 2: THAY THE DAU NGOAC
// '(' co cap -> 0 ; ')' co cap -> 1 ; ngoac thua (khong ghep duoc) -> -1
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    cin.ignore();

    while (T--) {
        string s;
        if (!getline(cin, s)) break;
        int n = (int)s.size();

        vector<int> code(n, -1);   // mac dinh -1 (ngoac thua)
        vector<int> st;            // vi tri cac '(' chua ghep

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push_back(i);
            else if (s[i] == ')') {
                if (!st.empty()) {
                    code[st.back()] = 0;   // '(' ghep duoc
                    st.pop_back();
                    code[i] = 1;           // ')' ghep duoc
                }
                // neu stack rong -> giu -1
            }
        }

        string out;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == ')') out += to_string(code[i]);
            else out += s[i];
        }
        cout << out << '\n';
    }
    return 0;
}
