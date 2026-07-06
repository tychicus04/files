// BAI 1 - DOI TIEN (Doi tien / Money change)
// Menh gia: 1,2,5,10,20,50,100,200,500,1000 -> he tien chuan, tham lam luon toi uu.
// Input: T (T<=50), moi test 1 so N (1<=N<=100000). Output: so to it nhat.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int denom[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long N;
        cin >> N;
        long long cnt = 0;
        for (int d : denom) {
            cnt += N / d;
            N %= d;
        }
        cout << cnt << "\n";
    }
    return 0;
}
