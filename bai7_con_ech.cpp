// BAI 7 - CON ECH
// Ech nhay buoc 1, 2 hoac 3 de len dinh cao n bac. Dem so cach nhay.
// So cach: f(n) = f(n-1) + f(n-2) + f(n-3) (Tribonacci), f(0)=1, f(1)=1, f(2)=2.
// n toi 50 -> gia tri lon (~3.5e13) nen dung long long.
// Input: T (1<=T<=100), moi test 1 so n (1<=n<=50). Output: so cach cho moi test.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long f[51];
    f[0] = 1; f[1] = 1; f[2] = 2;
    for (int i = 3; i <= 50; i++)
        f[i] = f[i-1] + f[i-2] + f[i-3];

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        cout << f[n] << "\n";
    }
    return 0;
}
