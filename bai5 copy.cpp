// BAI 5: SO LUONG DAY NGOAC DUNG
// "Bac" cua bieu thuc ngoac dung = do sau long nhau lon nhat.
// Goi F(k) = so cach thay '?' de duoc day ngoac dung co bac <= k
//   -> dap so (bac dung bang K) = F(K) - F(K-1).
// F(k): quy hoach dong dp[i][b] = so cach xet i ky tu dau, dang mo b dau ngoac (0 <= b <= k).
// Ket qua co the rat lon (|S| <= 200) nen dung so nguyen lon (big integer).
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Big;            // co so 1e9, luu nguoc (little-endian), rong = 0
const int BASE = 1000000000;

void addTo(Big& a, const Big& b) {
    if (b.empty()) return;
    size_t n = max(a.size(), b.size());
    a.resize(n, 0);
    long long carry = 0;
    for (size_t i = 0; i < n; i++) {
        long long cur = (long long)a[i] + carry + (i < b.size() ? b[i] : 0);
        a[i] = (int)(cur % BASE);
        carry = cur / BASE;
    }
    if (carry) a.push_back((int)carry);
}

Big subBig(const Big& a, const Big& b) {     // gia thiet a >= b
    Big r = a;
    long long borrow = 0;
    for (size_t i = 0; i < r.size(); i++) {
        long long cur = (long long)r[i] - borrow - (i < b.size() ? b[i] : 0);
        if (cur < 0) { cur += BASE; borrow = 1; } else borrow = 0;
        r[i] = (int)cur;
    }
    while (!r.empty() && r.back() == 0) r.pop_back();
    return r;
}

string toStr(const Big& a) {
    if (a.empty()) return "0";
    string s = to_string(a.back());
    for (int i = (int)a.size() - 2; i >= 0; i--) {
        string t = to_string(a[i]);
        s += string(9 - t.size(), '0') + t;
    }
    return s;
}

// so cach thay '?' de S thanh day ngoac dung co do sau toi da <= k
Big countAtMost(const string& s, int k) {
    int n = (int)s.size();
    if (k < 0) return Big();
    if (k > n) k = n;                        // do sau khong the vuot qua n
    vector<Big> dp(k + 1);
    dp[0] = Big{1};
    for (int i = 0; i < n; i++) {
        vector<Big> nd(k + 1);
        for (int b = 0; b <= k; b++) {
            if (dp[b].empty()) continue;
            char c = s[i];
            if ((c == '(' || c == '?') && b + 1 <= k) addTo(nd[b + 1], dp[b]);
            if ((c == ')' || c == '?') && b - 1 >= 0) addTo(nd[b - 1], dp[b]);
        }
        dp = move(nd);
    }
    return dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long K;
    string s;
    if (!(cin >> K)) return 0;
    cin >> s;

    int n = (int)s.size();
    int k1 = (int)min<long long>(K, n);
    int k0 = (int)min<long long>(K - 1, n);

    Big res = subBig(countAtMost(s, k1), countAtMost(s, k0));
    cout << toStr(res) << '\n';
    return 0;
}
