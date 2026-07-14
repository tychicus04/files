// BAI 7: KY TU A - B - C
// Liet ke moi xau do dai <= N tren bang chu {A,B,C} sao cho:
//   - co du ca 3 ky tu A, B, C
//   - soA <= soB <= soC
// Sap xep: do dai tang dan, cung do dai thi theo thu tu tu dien.
// N <= 12 nen sinh de quy (quay lui) theo dung thu tu tu dien la du nhanh.
#include <bits/stdc++.h>
using namespace std;

int N;
string cur;
string out;
int cnt[3];                       // so luong A, B, C hien tai

void backtrack(int len) {
    if ((int)cur.size() == len) {
        if (cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 1 &&
            cnt[0] <= cnt[1] && cnt[1] <= cnt[2]) {
            out += cur;
            out += '\n';
        }
        return;
    }
    for (int c = 0; c < 3; c++) {          // 'A' < 'B' < 'C' -> thu tu tu dien
        cur += char('A' + c);
        cnt[c]++;
        backtrack(len);
        cnt[c]--;
        cur.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N)) return 0;
    for (int len = 3; len <= N; len++) backtrack(len);   // xau ngan nhat co du 3 ky tu la 3
    cout << out;
    return 0;
}
