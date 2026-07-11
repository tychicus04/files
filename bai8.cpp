#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 0;
    const int N = 1000000;
    static int s[N + 1];                       // s[x] = sum of proper divisors of x
    for (int i = 1; i <= N; i++)
        for (int j = 2 * i; j <= N; j += i)
            s[j] += i;
    int cnt = 0;
    for (int x = a; x <= b; x++) if (s[x] > x) cnt++;   // abundant number
    printf("%d\n", cnt);
    return 0;
}
