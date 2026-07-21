// BAI 2: dem cach thay '?' trong S bang '(' hoac ')' de duoc day ngoac dung co BAC = K
// bac = do sau long nhau lon nhat  =>  dem(bac <= K) - dem(bac <= K-1)
// Ket qua co the rat lon (S dai toi 200) nen dung so nguyen lon (BigInt co so 1e9).
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

static const ull BASE = 1000000000ULL;

struct Big {
    vector<ull> d; // little-endian, base BASE
    Big(ull v = 0) { if (v) d.push_back(v); }
    bool isZero() const { return d.empty(); }
    void trim() { while (!d.empty() && d.back() == 0) d.pop_back(); }
};

Big add(const Big &a, const Big &b) {
    Big r;
    size_t n = max(a.d.size(), b.d.size());
    r.d.assign(n, 0);
    ull carry = 0;
    for (size_t i = 0; i < n; i++) {
        ull s = carry;
        if (i < a.d.size()) s += a.d[i];
        if (i < b.d.size()) s += b.d[i];
        r.d[i] = s % BASE;
        carry = s / BASE;
    }
    if (carry) r.d.push_back(carry);
    r.trim();
    return r;
}

// gia su a >= b
Big sub(const Big &a, const Big &b) {
    Big r;
    r.d.assign(a.d.size(), 0);
    long long borrow = 0;
    for (size_t i = 0; i < a.d.size(); i++) {
        long long cur = (long long)a.d[i] - borrow - (i < b.d.size() ? (long long)b.d[i] : 0);
        if (cur < 0) { cur += BASE; borrow = 1; } else borrow = 0;
        r.d[i] = (ull)cur;
    }
    r.trim();
    return r;
}

string toString(const Big &a) {
    if (a.d.empty()) return "0";
    string s = to_string(a.d.back());
    for (int i = (int)a.d.size() - 2; i >= 0; i--) {
        string part = to_string(a.d[i]);
        s += string(9 - part.size(), '0') + part;
    }
    return s;
}

static string S;

// so cach thay '?' de duoc day ngoac dung voi do sau toi da <= m (m>=0)
Big countAtMost(int m) {
    int n = (int)S.size();
    vector<Big> dp(m + 2), nd(m + 2);
    dp[0] = Big(1);
    for (int i = 0; i < n; i++) {
        for (auto &x : nd) x = Big(0);
        for (int d = 0; d <= m; d++) {
            if (dp[d].isZero()) continue;
            if (S[i] == '(' || S[i] == '?') { if (d + 1 <= m) nd[d + 1] = add(nd[d + 1], dp[d]); }
            if (S[i] == ')' || S[i] == '?') { if (d - 1 >= 0) nd[d - 1] = add(nd[d - 1], dp[d]); }
        }
        dp.swap(nd);
    }
    return dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) return 0;
    if (!(cin >> S)) S.clear();

    if ((int)S.size() % 2 != 0) { cout << 0 << '\n'; return 0; }
    Big hi = countAtMost(K);
    Big lo = (K >= 1) ? countAtMost(K - 1) : Big(0);
    cout << toString(sub(hi, lo)) << '\n';
    return 0;
}
