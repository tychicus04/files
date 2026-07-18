// BAI 6: xau con lien tiep la day ngoac dung co nhieu dau '[' nhat
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line, s;
    if (!getline(cin, line)) return 0;
    for (char c : line) if (c=='('||c==')'||c=='['||c==']') s += c;

    int n = (int)s.size();
    vector<char> used(n, 0);
    vector<int> st;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '[') st.push_back(i);
        else if (c == ')') {
            if (!st.empty() && s[st.back()] == '(') { used[st.back()] = used[i] = 1; st.pop_back(); }
            else st.clear();               // ngoac dong khong khop -> chan moi ket noi
        } else { // ']'
            if (!st.empty() && s[st.back()] == '[') { used[st.back()] = used[i] = 1; st.pop_back(); }
            else st.clear();
        }
    }

    // doan lien tiep dai nhat gom cac vi tri da ghep cap -> dem '['
    int best = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) { if (s[i] == '[') cur++; }
        else { best = max(best, cur); cur = 0; }
    }
    best = max(best, cur);
    cout << best << '\n';
    return 0;
}
