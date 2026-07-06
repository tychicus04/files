// BAI 6 - SAP XEP CONG VIEC (Job Sequencing)
// Moi viec (JobId, Deadline, Profit) ton 1 don vi thoi gian, phai xong <= Deadline.
// Chon lich lam viec de TONG LOI NHUAN lon nhat.
// Tham lam: sap xep theo Profit giam dan, moi viec dat vao slot rong MUON NHAT <= Deadline.
// Input: T (<=100). Moi test: N (<=1000), roi N dong "JobId Deadline Profit"
//        (1<=JobId,Deadline,Profit<=1000). Output moi test: "so_luong_viec  loi_nhuan_lon_nhat".
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<array<long long, 3>> jobs(N); // {id, deadline, profit}
        long long maxD = 0;
        for (int i = 0; i < N; i++) {
            cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];
            maxD = max(maxD, jobs[i][1]);
        }

        sort(jobs.begin(), jobs.end(),
             [](const array<long long,3>& a, const array<long long,3>& b) {
                 return a[2] > b[2]; // profit giam dan
             });

        vector<char> used(maxD + 1, 0); // slot thoi gian 1..maxD
        long long cnt = 0, profit = 0;
        for (auto& j : jobs) {
            for (long long t = j[1]; t >= 1; t--) { // tim slot rong muon nhat
                if (!used[t]) {
                    used[t] = 1;
                    cnt++;
                    profit += j[2];
                    break;
                }
            }
        }
        cout << cnt << " " << profit << "\n";
    }
    return 0;
}
