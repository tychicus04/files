#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<string> names(N);
    for (int i = 0; i < N; i++) cin >> names[i];

    // Loại tên trùng, sắp xếp theo thứ tự từ điển
    sort(names.begin(), names.end());
    names.erase(unique(names.begin(), names.end()), names.end());
    int M = names.size();

    vector<int> comb(K);
    function<void(int,int)> gen = [&](int start, int chosen) {
        if (chosen == K) {
            for (int i = 0; i < K; i++) {
                if (i > 0) cout << " ";
                cout << names[comb[i]];
            }
            cout << "\n";
            return;
        }
        for (int i = start; i < M; i++) {
            comb[chosen] = i;
            gen(i + 1, chosen + 1);
        }
    };
    gen(0, 0);

    return 0;
}
