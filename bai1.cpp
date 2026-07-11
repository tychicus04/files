#include <bits/stdc++.h>
using namespace std;

int N, K, bits[25];
long long cnt;
string body;

// true if the string has a MAXIMAL block of zeros whose length is exactly K
bool ok() {
    int i = 0;
    while (i < N) {
        if (bits[i] == 0) {
            int j = i;
            while (j < N && bits[j] == 0) j++;
            if (j - i == K) return true;
            i = j;
        } else i++;
    }
    return false;
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
