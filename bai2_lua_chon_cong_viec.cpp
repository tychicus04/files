// BAI 2 - LUA CHON CONG VIEC
// Moi viec ton 1 don vi thoi gian, han chot Sk, loi nhuan Pk neu xong dung han.
// Chon tap viec sao cho tong loi nhuan lon nhat.
// Vi han chot toi 1e9 nhung chi quan tam SO LUONG viec da chon:
//   - Sap xep theo han chot tang dan.
//   - Dung min-heap giu cac loi nhuan da chon; neu so viec > han chot hien tai,
//     bo di viec co loi nhuan nho nhat.
// Input: N (1<=N<=1e5), N dong (Sk Pk), 1<=Sk,Pk<=1e9. Output: tong loi nhuan lon nhat.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<pair<long long, long long>> jobs(N); // {deadline, profit}
    for (int i = 0; i < N; i++)
        cin >> jobs[i].first >> jobs[i].second;

    sort(jobs.begin(), jobs.end()); // theo deadline tang dan

    priority_queue<long long, vector<long long>, greater<long long>> pq; // min-heap loi nhuan
    for (auto &j : jobs) {
        long long d = j.first, p = j.second;
        pq.push(p);
        if ((long long)pq.size() > d) pq.pop(); // vuot so slot cho phep -> bo cai nho nhat
    }

    long long total = 0;
    while (!pq.empty()) { total += pq.top(); pq.pop(); }
    cout << total << "\n";
    return 0;
}
