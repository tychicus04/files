// BAI 1: Do sau lon nhat cua cac cap ngoac long nhau. Bieu thuc sai -> -1
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

        long long depth = 0, best = 0;
        bool ok = true;
        for (char c : s) {
            if (c == '(') { if (++depth > best) best = depth; }
            else if (c == ')') { if (--depth < 0) { ok = false; break; } }
        }
        if (depth != 0) ok = false;
        cout << (ok ? best : -1LL) << '\n';
    }
    return 0;
}
