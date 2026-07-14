// BAI 6: SO NGUYEN THUY
// K nguyen thuy: so chu so chan, moi chu so la 4 hoac 5, K doi xung (palindrome).
// => K = nua_dau + dao_nguoc(nua_dau). Voi nua dau dai d co 2^d so, xep tang dan
//    theo thu tu tu dien cua nua dau. N <= 10^4 nen can d toi da 13 -> so co 26 chu so
//    => phai luu duoi dang XAU (khong du long long).
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int NEED = 10000;
    vector<string> num;
    num.reserve(NEED + 20);

    for (int d = 1; (int)num.size() < NEED; d++) {          // d = do dai nua dau
        for (int mask = 0; mask < (1 << d) && (int)num.size() < NEED; mask++) {
            string half;
            for (int j = d - 1; j >= 0; j--)                // bit cao -> chu so trai
                half += ((mask >> j) & 1) ? '5' : '4';
            string s = half;
            for (int j = d - 1; j >= 0; j--) s += half[j];  // ghep phan doi xung
            num.push_back(s);
        }
    }

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        string out;
        for (int i = 0; i < n; i++) {
            if (i) out += ' ';
            out += num[i];
        }
        cout << out << '\n';
    }
    return 0;
}
