// BAI 5: Tinh gia tri bieu thuc dang tien to hoac hau to (tu dong nhan dang).
// Toan tu la token co do dai 1 va thuoc {+,-,*,/}; toan hang la so nguyen (co the am).
// Neu token dau tien la toan tu -> bieu thuc dang tien to, nguoc lai la hau to.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static bool isOp(const string &t) {
    return t.size() == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/');
}

static ll apply(ll a, ll b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default:  return a / b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<string> tok(n);
        for (int i = 0; i < n; i++) cin >> tok[i];

        vector<ll> st;
        st.reserve(n);
        if (isOp(tok[0])) {
            // tien to: duyet phai -> trai
            for (int i = n - 1; i >= 0; i--) {
                if (isOp(tok[i])) {
                    ll a = st.back(); st.pop_back();
                    ll b = st.back(); st.pop_back();
                    st.push_back(apply(a, b, tok[i][0]));
                } else {
                    st.push_back(stoll(tok[i]));
                }
            }
        } else {
            // hau to: duyet trai -> phai
            for (int i = 0; i < n; i++) {
                if (isOp(tok[i])) {
                    ll b = st.back(); st.pop_back();
                    ll a = st.back(); st.pop_back();
                    st.push_back(apply(a, b, tok[i][0]));
                } else {
                    st.push_back(stoll(tok[i]));
                }
            }
        }
        cout << st.back() << '\n';
    }
    return 0;
}
