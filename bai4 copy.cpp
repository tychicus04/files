// BAI 4: HINH CHU NHAT DON SAC
// Cot i: A[i] o vang tinh tu tren xuong, M - A[i] o xanh tinh tu duoi len.
// => HCN vang lon nhat = HCN lon nhat trong histogram cac cot cao A[i]
//    HCN xanh lon nhat = HCN lon nhat trong histogram cac cot cao M - A[i]
// Dap so = max cua hai gia tri tren  (thuat toan stack O(N)).
#include <bits/stdc++.h>
using namespace std;

long long largestRectangle(const vector<int>& h) {
    int n = (int)h.size();
    vector<int> st;                 // stack cac chi so voi chieu cao tang dan
    long long best = 0;
    for (int i = 0; i <= n; i++) {
        int cur = (i == n ? 0 : h[i]);
        while (!st.empty() && h[st.back()] >= cur) {
            int height = h[st.back()];
            st.pop_back();
            int left = st.empty() ? -1 : st.back();
            long long width = i - left - 1;
            best = max(best, (long long)height * width);
        }
        st.push_back(i);            // i == n khong anh huong vi vong lap ket thuc
        if (i == n) break;
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long m, n;
    while (cin >> m >> n) {         // M = so dong, N = so cot
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = (int)m - a[i];
        }
        cout << max(largestRectangle(a), largestRectangle(b)) << '\n';
    }
    return 0;
}
