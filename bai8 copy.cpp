// BAI 8: BIEN DOI SO TU NHIEN
// Thao tac (a): N -> N-1
// Thao tac (b): N -> max(u,v) voi u*v = N, u,v > 1
//               <=> N -> d, voi d la uoc cua N, sqrt(N) <= d < N
// Tim so thao tac it nhat de N -> 1.
//
// Cach lam:
//  1) QHD tinh f[x] chinh xac cho moi x <= LIM = 10^6:
//        f[x] = min( f[x-1] + 1 , min{ f[d] + 1 : d | x, d < x, d*d >= x } )
//  2) Voi N > LIM: tim kiem co can tia (branch & bound) - do sau loi giai rat nho.
//     - Can duoi (admissible): moi thao tac tu x cho gia tri >= floor(sqrt(x)),
//       nen f(x) >= 1 + min{ f(y) : y >= floor(sqrt(x)) }  (dung mang suffix-min).
//     - Ghi nho do sau da tham cua moi x de khong lap lai.
#include <bits/stdc++.h>
using namespace std;

const int LIM = 1000000;
const int INF = 1000000;

vector<unsigned char> f;      // f[x] voi x <= LIM
vector<unsigned char> sufmin; // sufmin[v] = min f[y], v <= y <= LIM
vector<int> spf;              // smallest prime factor
vector<int> primes;
int BIGMIN;                   // can duoi cua f(y) voi moi y > LIM

long long isqrtLL(long long x) {
    long long r = (long long)sqrtl((long double)x);
    while (r * r > x) r--;
    while ((r + 1) * (r + 1) <= x) r++;
    return r;
}

void precompute() {
    spf.assign(LIM + 1, 0);
    for (int i = 2; i <= LIM; i++) {
        if (spf[i] == 0) { spf[i] = i; primes.push_back(i); }
        for (int p : primes) {
            if (p > spf[i] || (long long)p * i > LIM) break;
            spf[p * i] = p;
        }
    }

    f.assign(LIM + 1, 0);
    f[1] = 0;
    vector<int> divs;
    for (int x = 2; x <= LIM; x++) {
        int best = f[x - 1] + 1;
        // sinh tat ca uoc cua x
        divs.clear();
        divs.push_back(1);
        int t = x;
        while (t > 1) {
            int p = spf[t], e = 0;
            while (t % p == 0) { t /= p; e++; }
            int sz = (int)divs.size();
            long long pw = 1;
            for (int k = 1; k <= e; k++) {
                pw *= p;
                for (int i = 0; i < sz; i++) divs.push_back((int)(divs[i] * pw));
            }
        }
        for (int d : divs)
            if (d < x && (long long)d * d >= x)
                best = min(best, (int)f[d] + 1);
        f[x] = (unsigned char)best;
    }

    sufmin.assign(LIM + 2, 255);
    sufmin[LIM] = f[LIM];
    for (int i = LIM - 1; i >= 1; i--) sufmin[i] = min(f[i], sufmin[i + 1]);

    BIGMIN = 1 + sufmin[isqrtLL(LIM)];   // can duoi cho moi y > LIM
}

// cac gia tri co the den bang thao tac (b) tu x: uoc d cua x, sqrt(x) <= d < x
vector<long long> movesB(long long x) {
    vector<long long> divs{1};
    long long t = x;
    for (int p : primes) {
        if ((long long)p * p > t) break;
        if (t % p == 0) {
            int e = 0;
            while (t % p == 0) { t /= p; e++; }
            int sz = (int)divs.size();
            long long pw = 1;
            for (int k = 1; k <= e; k++) {
                pw *= p;
                for (int i = 0; i < sz; i++) divs.push_back(divs[i] * pw);
            }
        }
    }
    if (t > 1) {                       // con lai 1 uoc nguyen to lon
        int sz = (int)divs.size();
        for (int i = 0; i < sz; i++) divs.push_back(divs[i] * t);
    }
    vector<long long> res;
    for (long long d : divs)
        if (d < x && d * d >= x) res.push_back(d);
    sort(res.begin(), res.end());
    return res;
}

int lowerBound(long long x) {
    if (x <= LIM) return f[x];
    long long r = isqrtLL(x);
    int a = (r <= LIM) ? sufmin[r] : 255;
    return 1 + min(a, BIGMIN);
}

int best;
unordered_map<long long, int> seen;   // x -> do sau nho nhat da tham

void dfs(long long x, int depth) {
    if (depth + lowerBound(x) >= best) return;
    if (x <= LIM) { best = min(best, depth + (int)f[x]); return; }
    auto it = seen.find(x);
    if (it != seen.end() && it->second <= depth) return;
    seen[x] = depth;

    for (long long d : movesB(x)) dfs(d, depth + 1);   // uu tien gia tri nho
    dfs(x - 1, depth + 1);                             // thao tac (a)
}

int greedy(long long x) {           // 1 loi giai bat ky -> can tren ban dau
    int steps = 0;
    while (x > LIM) {
        auto v = movesB(x);
        if (v.empty()) x--;         // x nguyen to
        else x = v[0];
        steps++;
    }
    return steps + f[x];
}

int solve(long long n) {
    if (n <= LIM) return f[n];
    best = greedy(n);
    seen.clear();
    dfs(n, 0);
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}
