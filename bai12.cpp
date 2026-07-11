#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; long long K;
    while (scanf("%d %lld", &N, &K) == 2) {         // robust: one or many tests
        vector<long long> A(N), dp(N);
        long long total = 0;
        for (int i = 0; i < N; i++) { scanf("%lld", &A[i]); total += A[i]; }

        if (N < K) { printf("%lld\n", total); continue; }   // no window of K -> keep all

        // Delete a minimum-cost set so that no K positions in a row are all kept.
        // dp[i] = min delete cost with position i deleted (prev deletion within K).
        deque<int> dq;                                       // sliding-window min of dp[i-K..i-1]
        for (int i = 0; i < N; i++) {
            while (!dq.empty() && dq.front() < i - (int)K) dq.pop_front();
            long long prevMin = (i < (int)K) ? 0 : dp[dq.front()];
            dp[i] = A[i] + prevMin;
            while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        long long minDel = LLONG_MAX;
        for (int i = N - (int)K; i < N; i++) minDel = min(minDel, dp[i]);
        printf("%lld\n", total - minDel);
    }
    return 0;
}
