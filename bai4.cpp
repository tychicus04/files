// BAI 4 - BIEU THUC DUNG: do sau long nhau lon nhat, sai -> -1
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

        int depth = 0, best = 0;
        bool ok = true;

        for (char c : s) {
            if (c == '(') {
                depth++;
                best = max(best, depth);
            } else if (c == ')') {
                depth--;
                if (depth < 0) { ok = false; break; }   // dong truoc khi mo
            }
        }
        if (depth != 0) ok = false;                     // con ngoac mo chua dong

        cout << (ok ? best : -1) << '\n';
    }
    return 0;
}
