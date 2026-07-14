// BAI 9: SO BUOC DI CHUYEN IT NHAT
// Tu o (i,j), moi buoc di theo 1 trong 3 huong, SO O DI CHUYEN d bang hieu
// (tri tuyet doi) cua hai gia tri:
//   - Xuong duoi : d = |A[i][j] - A[i+1][j]|      -> den (i+d, j)
//   - Sang phai  : d = |A[i][j] - A[i][j+1]|      -> den (i, j+d)
//   - Cheo xuong : d = |A[i][j] - A[i+1][j+1]|    -> den (i+d, j+d)
// (d phai >= 1 va o den phai nam trong bang; neu d = 0 thi khong di duoc)
// Moi buoc co "chi phi" 1 -> BFS tren luoi. Khong den duoc thi in -1.
#include <bits/stdc++.h>
using namespace std;

static inline int readInt() {
    int c = getchar_unlocked();
    while (c != '-' && (c < '0' || c > '9')) {
        if (c == EOF) return INT_MIN;
        c = getchar_unlocked();
    }
    int sgn = 1;
    if (c == '-') { sgn = -1; c = getchar_unlocked(); }
    int x = 0;
    while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = getchar_unlocked(); }
    return x * sgn;
}

int main() {
    int T = readInt();
    if (T == INT_MIN) return 0;

    while (T--) {
        int n = readInt(), m = readInt();
        vector<int> a((size_t)n * m);
        for (int i = 0; i < n * m; i++) a[i] = readInt();

        vector<int> dist((size_t)n * m, -1);
        deque<int> q;
        dist[0] = 0;
        q.push_back(0);

        while (!q.empty()) {
            int cur = q.front(); q.pop_front();
            int i = cur / m, j = cur % m, d0 = dist[cur];
            int v = a[cur];

            // xuong duoi
            if (i + 1 < n) {
                int d = abs(v - a[cur + m]);
                int ni = i + d;
                if (d >= 1 && ni < n && dist[ni * m + j] == -1) {
                    dist[ni * m + j] = d0 + 1;
                    q.push_back(ni * m + j);
                }
            }
            // sang phai
            if (j + 1 < m) {
                int d = abs(v - a[cur + 1]);
                int nj = j + d;
                if (d >= 1 && nj < m && dist[i * m + nj] == -1) {
                    dist[i * m + nj] = d0 + 1;
                    q.push_back(i * m + nj);
                }
            }
            // cheo xuong
            if (i + 1 < n && j + 1 < m) {
                int d = abs(v - a[cur + m + 1]);
                int ni = i + d, nj = j + d;
                if (d >= 1 && ni < n && nj < m && dist[ni * m + nj] == -1) {
                    dist[ni * m + nj] = d0 + 1;
                    q.push_back(ni * m + nj);
                }
            }
        }
        printf("%d\n", dist[(size_t)n * m - 1]);   // = -1 neu khong den duoc
    }
    return 0;
}
