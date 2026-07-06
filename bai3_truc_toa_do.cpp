// BAI 3 - TRUC TOA DO
// Chon nhieu nhat cac doan thang khong chong lan nhau (bai toan chon hoat dong).
// Tham lam: sap xep theo diem KET THUC tang dan, chon doan neu diem bat dau >= ket thuc doan truoc.
// (Hai doan cham nhau tai 1 diem duoc coi la khong chong lan -> dung >=.)
// Input: so bo test (<=10). Moi test: N (<=1e5), roi N dong "x1 x2" (toa do 0..1e6).
// Output: moi test 1 dong - so doan nhieu nhat.
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
        vector<pair<long long, long long>> seg(N); // {end, start}
        for (int i = 0; i < N; i++) {
            long long a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            seg[i] = {b, a};
        }
        sort(seg.begin(), seg.end()); // theo end tang dan

        long long cnt = 0, lastEnd = LLONG_MIN;
        for (auto &s : seg) {
            long long end = s.first, start = s.second;
            if (start >= lastEnd) { // khong chong lan
                cnt++;
                lastEnd = end;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
