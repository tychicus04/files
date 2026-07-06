// BAI 4 - NOI DAY 2
// (!) Anh chup bai nay bi mo -> minh giai theo dang KINH DIEN cua "Noi day":
//     Cho N soi day, moi lan noi 2 soi ton chi phi = tong do dai 2 soi do,
//     va tao thanh 1 soi moi. Noi tat ca thanh 1 soi voi TONG CHI PHI NHO NHAT.
//     Tham lam: luon noi 2 soi NGAN NHAT truoc (dung min-heap / Huffman).
// Neu de bai / dinh dang input khac, bao minh de sua lai cho dung.
//
// Gia dinh dinh dang: dong dau la so bo test T; moi test: N roi N do dai.
// Output: chi phi noi nho nhat cho moi test.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < N; i++) {
            long long x;
            cin >> x;
            pq.push(x);
        }

        long long cost = 0;
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            cost += a + b;
            pq.push(a + b);
        }
        cout << cost << "\n";
    }
    return 0;
}
