#include <bits/stdc++.h>
using namespace std;

int n, k, a[15];

void gen(int pos, int start) {
    if (pos == k) {
        for (int i = 0; i < k; i++) { if (i) cout << ' '; cout << a[i]; }
        cout << "\n";
        return;
    }
    for (int v = start; v <= n; v++) { a[pos] = v; gen(pos + 1, v); } // v..n => non-decreasing
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    gen(0, 1);
    return 0;
}
