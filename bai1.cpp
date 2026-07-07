#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N, K;
        cin >> N >> K;

        vector<string> results;
        // Sinh tất cả xâu nhị phân độ dài N bằng cách duyệt mask từ 0 -> 2^N - 1
        for (long long mask = 0; mask < (1LL << N); mask++) {
            string s(N, '0');
            for (int i = 0; i < N; i++) {
                if (mask & (1LL << (N - 1 - i))) s[i] = '1';
            }
            // Đếm số dãy 0 liên tiếp có độ dài đúng bằng K
            int run = 0, cnt = 0;
            for (int i = 0; i < N; i++) {
                if (s[i] == '0') run++;
                else { if (run == K) cnt++; run = 0; }
            }
            if (run == K) cnt++; // dãy 0 ở cuối xâu
            if (cnt == 1) results.push_back(s);
        }

        cout << results.size() << "\n";
        for (auto &s : results) cout << s << "\n";
        if (tc != T - 1) cout << "\n"; // dòng trống giữa các bộ test
    }
    return 0;
}
