// BAI 10 - HINH CHU NHAT LON NHAT (largest rectangle in histogram)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> h(n + 1);
        for (int i = 0; i < n; i++) cin >> h[i];
        h[n] = 0;                       // cot "ao" cao 0 de xa het stack

        stack<int> st;                  // chi so, chieu cao TANG dan
        long long best = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                long long ht = h[st.top()]; st.pop();
                int left = st.empty() ? -1 : st.top();   // bien trai (khong tinh)
                long long width = i - left - 1;
                best = max(best, ht * width);
            }
            st.push(i);
        }
        cout << best << '\n';
    }
    return 0;
}
