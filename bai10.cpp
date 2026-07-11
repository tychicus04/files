#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long N, K;
    if (!(cin >> N >> K)) return 0;
    vector<int> len(N);
    for (int i = 0; i < N; i++) { string s; cin >> s; len[i] = (int)s.size(); }

    unordered_map<int, long long> freq;         // name-length -> count inside current window
    freq.reserve(2048);
    long long ans = 0;
    for (long long i = 0; i < N; i++) {
        if (i - K - 1 >= 0) freq[len[i - K - 1]]--;   // drop the element now too far (dist K+1)
        auto it = freq.find(len[i]);                  // window holds positions [i-K, i-1]
        if (it != freq.end()) ans += it->second;      // pairs (j, i) with dist <= K, equal length
        freq[len[i]]++;
    }
    cout << ans << "\n";
    return 0;
}
