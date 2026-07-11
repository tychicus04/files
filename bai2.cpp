#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> digs;
string cur;

void gen(int pos) {
    if (pos == N) { cout << cur << "\n"; return; }
    for (int d : digs) { cur.push_back(char('0' + d)); gen(pos + 1); cur.pop_back(); }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    set<int> s;                       // dedupe the 3 digits, keep sorted (ascending)
    for (int i = 0; i < 3; i++) { int x; cin >> x; s.insert(x); }
    for (int x : s) digs.push_back(x);
    gen(0);                           // ascending digits -> increasing numbers
    return 0;
}
