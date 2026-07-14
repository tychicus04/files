// BAI 3: TINH GIA TRI BIEU THUC HAU TO
// Dung stack: gap toan hang -> push; gap toan tu -> lay 2 phan tu tren cung.
// Chu y: "-10" la toan hang am, con "-" (dai dung 1 ky tu) moi la toan tu.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        cin >> n;
        vector<long long> st;
        st.reserve(n);

        for (int i = 0; i < n; i++) {
            string tok;
            cin >> tok;
            bool isOp = (tok.size() == 1 &&
                        (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/'));
            if (isOp) {
                long long b = st.back(); st.pop_back();
                long long a = st.back(); st.pop_back();
                long long r = 0;
                switch (tok[0]) {
                    case '+': r = a + b; break;
                    case '-': r = a - b; break;
                    case '*': r = a * b; break;
                    case '/': r = a / b; break;   // chia nguyen
                }
                st.push_back(r);
            } else {
                st.push_back(stoll(tok));
            }
        }
        cout << st.back() << '\n';
    }
    return 0;
}
