// BAI 7: So loc phat = chi gom chu so 6 va 8. Liet ke tat ca so do dai N, tang dan.
// Coi 6 la bit 0, 8 la bit 1: dem tu 0..2^N-1 (MSB truoc) cho ra dung thu tu tang dan.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        int total = 1 << n;
        cout << total << '\n';
        for (int mask = 0; mask < total; mask++) {
            if (mask) cout << ' ';
            string num(n, '6');
            for (int b = 0; b < n; b++)
                if (mask & (1 << (n - 1 - b))) num[b] = '8';
            cout << num;
        }
        cout << '\n';
    }
    return 0;
}
