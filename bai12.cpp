// BAI 12: Mot vua va vai quan ma, moi buoc TAT CA quan phai di chuyen (dung luat, khong vao o cam).
// Tim so buoc it nhat de tat ca gap nhau tai cung 1 o.
// Voi moi quan, tinh tap o "den duoc dung sau đung t buoc" (khong phai "trong pham vi t buoc"),
// bang cach mo rong lop theo lop (BFS theo lop, khong tich luy). Dap an = t nho nhat ma
// giao cua cac tap nay (cua moi quan) khac rong.
#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> grid;

inline bool inb(int r, int c) { return r >= 0 && r < N && c >= 0 && c < N; }
inline int idx(int r, int c) { return r * N + c; }

// dx,dy cho vua (8 huong) va quan ma (8 nuoc di)
int kdr[8] = {-1,-1,-1,0,0,1,1,1};
int kdc[8] = {-1,0,1,-1,1,-1,0,1};
int ndr[8] = {1,1,-1,-1,2,2,-2,-2};
int ndc[8] = {2,-2,2,-2,1,-1,1,-1};

vector<vector<char>> computeLayers(int startIdx, bool isKnight, int cap) {
    int total = N * N;
    int *dr = isKnight ? ndr : kdr;
    int *dc = isKnight ? ndc : kdc;

    vector<vector<char>> layers(cap + 1, vector<char>(total, 0));
    layers[0][startIdx] = 1;
    for (int t = 1; t <= cap; t++) {
        vector<char> &cur = layers[t - 1];
        vector<char> &nxt = layers[t];
        for (int i = 0; i < total; i++) {
            if (!cur[i]) continue;
            int r = i / N, c = i % N;
            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (inb(nr, nc) && grid[nr][nc] != '#') nxt[idx(nr, nc)] = 1;
            }
        }
    }
    return layers;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N)) return 0;
    grid.resize(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    int kingIdx = -1;
    vector<int> knights;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            if (grid[r][c] == 'T') kingIdx = idx(r, c);
            else if (grid[r][c] == 'M') knights.push_back(idx(r, c));
        }

    int cap = max(4, 2 * N);
    vector<vector<vector<char>>> allLayers;
    allLayers.push_back(computeLayers(kingIdx, false, cap));
    for (int k : knights) allLayers.push_back(computeLayers(k, true, cap));

    int total = N * N;
    int ans = -1;
    for (int t = 0; t <= cap && ans == -1; t++) {
        for (int i = 0; i < total; i++) {
            bool all = true;
            for (auto &L : allLayers) if (!L[t][i]) { all = false; break; }
            if (all) { ans = t; break; }
        }
    }
    cout << ans << '\n';
    return 0;
}
