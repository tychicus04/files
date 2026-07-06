// BAI 5 - LUA CHON THAM LAM
// Tao so nho nhat va lon nhat co N chu so, tong chu so = S.
// - Lon nhat: nhoi 9 tu trai sang.
// - Nho nhat: chu so dau tien >= 1, phan con lai nhoi 9 tu phai sang.
// - Khong the: in "-1 -1".
// Input: 1 dong "N S" (0<N<=100, 0<=S<=900). Output: "so_nho_nhat so_lon_nhat".
// Vi du: "3 20"->"299 992" ; "2 90"->"-1 -1" ; "3 0"->"-1 -1".
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long S;
    cin >> N >> S;

    // Truong hop dac biet S == 0
    if (S == 0) {
        if (N == 1) cout << "0 0\n";   // so 0 hop le voi 1 chu so
        else cout << "-1 -1\n";        // N>=2 khong the (khong so dau bang 0)
        return 0;
    }
    // Khong kha thi
    if (S > 9LL * N) { cout << "-1 -1\n"; return 0; }

    // Lon nhat: nhoi 9 tu trai
    string large(N, '0');
    {
        long long rem = S;
        for (int i = 0; i < N; i++) {
            int add = (int)min(9LL, rem);
            large[i] = char('0' + add);
            rem -= add;
        }
    }

    // Nho nhat: chu so dau >=1, con lai nhoi tu phai
    string small(N, '0');
    {
        small[0] = '1';
        long long rem = S - 1;
        int i = N - 1;
        while (rem > 0) {
            int cur = small[i] - '0';
            int add = (int)min((long long)(9 - cur), rem);
            small[i] = char('0' + cur + add);
            rem -= add;
            i--;
        }
    }

    cout << small << " " << large << "\n";
    return 0;
}
