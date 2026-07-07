#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> digits; // các chữ số khác nhau, đã sắp xếp tăng dần
int a[15];

void tryPos(int i) {
    for (int v = 0; v < (int)digits.size(); v++) {
        a[i] = v;
        if (i == N - 1) {
            for (int j = 0; j < N; j++) cout << digits[a[j]];
            cout << "\n";
        } else {
            tryPos(i + 1);
        }
    }
}

int main(){
    cin >> N;
    set<int> s;
    for (int i = 0; i < 3; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    digits.assign(s.begin(), s.end()); // set tự động sắp xếp tăng dần
    tryPos(0);
    return 0;
}
