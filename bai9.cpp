#include <bits/stdc++.h>
using namespace std;

// fast input
static char buf[1 << 16]; int bl = 0, bn = 0;
inline int gc() { if (bl == bn) { bn = (int)fread(buf, 1, sizeof(buf), stdin); bl = 0; if (!bn) return -1; } return buf[bl++]; }
inline long long rd() { int c = gc(); while (c != '-' && (c < '0' || c > '9')) c = gc(); long long x = 0; while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = gc(); } return x; }

int main() {
    int T = (int)rd();
    string out;
    const long long INF = LLONG_MAX / 4;
    while (T--) {
        int n = (int)rd();
        long long a0 = rd(), b0 = rd();
        // INCREASE-ONLY: each element's final value is a, a+1 or a+2 (proven enough).
        long long pv[3] = { a0, a0 + 1, a0 + 2 };
        long long pd[3] = { 0, b0, 2 * b0 };
        for (int i = 1; i < n; i++) {
            long long a = rd(), b = rd();
            long long cv[3] = { a, a + 1, a + 2 };
            long long cc[3] = { 0, b, 2 * b };
            long long cd[3];
            for (int k = 0; k < 3; k++) {
                long long best = INF;
                for (int p = 0; p < 3; p++)
                    if (cv[k] != pv[p]) best = min(best, pd[p]);
                cd[k] = cc[k] + best;
            }
            for (int k = 0; k < 3; k++) { pv[k] = cv[k]; pd[k] = cd[k]; }
        }
        out += to_string(min({ pd[0], pd[1], pd[2] }));
        out += '\n';
    }
    fputs(out.c_str(), stdout);
    return 0;
}