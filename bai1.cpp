#include <bits/stdc++.h>
using namespace std;

int N, K, bits[25];
long long cnt;
string body;

// true iff the string has EXACTLY ONE maximal block of zeros whose length is exactly K
bool ok() {
    int found = 0, i = 0;
    while (i < N) {
        if (bits[i] == 0) {
            int j = i;
            while (j < N && bits[j] == 0) j++;
            if (j - i == K) { if (++found > 1) return false; }
            i = j;
        } else i++;
    }
    return found == 1;
}

void gen(int pos) {
    if (pos == N) {
        if (ok()) {
            cnt++;
            for (int i = 0; i < N; i++) { if (i) body += ' '; body += char('0' + bits[i]); }
            body += '\n';
        }
        return;
    }
    bits[pos] = 0; gen(pos + 1);   // 0 first -> lexicographic order
    bits[pos] = 1; gen(pos + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; if (!(cin >> T)) return 0;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;
        cnt = 0; body.clear();
        gen(0);
        if (t) cout << "\n";                 // blank line between test cases
        cout << cnt << "\n" << body;
    }
    return 0;
}