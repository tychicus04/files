// BAI 9: N so "nguyen thuy" dau tien: so chu so chan, chi gom 4/5, doi xung
// => sinh nua trai (moi bit: 0->'4', 1->'5') roi lay doi xung guong
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAXN = 10000;
    vector<string> v;
    v.reserve(MAXN);
    for (int half = 1; (int)v.size() < MAXN; half++) {
        for (int mask = 0; mask < (1 << half) && (int)v.size() < MAXN; mask++) {
            string a(half, '4');
            for (int b = 0; b < half; b++)
                if (mask & (1 << (half - 1 - b))) a[b] = '5';
            string full = a;
            full.append(a.rbegin(), a.rend());
            v.push_back(full);
        }
    }
    // tien xu ly chuoi ghep san de xuat ket qua that nhanh
    string all;
    vector<size_t> endPos(MAXN + 1, 0);
    for (int i = 0; i < MAXN; i++) {
        if (i) all += ' ';
        all += v[i];
        endPos[i + 1] = all.size();
    }

    int T;
    if (scanf("%d", &T) != 1) return 0;
    string out;
    while (T--) {
        int n;
        if (scanf("%d", &n) != 1) break;
        if (n > MAXN) n = MAXN;
        out.append(all, 0, endPos[n]);
        out += '\n';
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
