#include <iostream>
#include <vector>
#include <algorithm> // sort

const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
bool chk[100][100];
int m, n, k;

inline bool out_of_range(int i, int j)
{
    if(i < 0 || j < 0 || i >= n || j >= m) return true;
    else                                   return false;
}

int dfs(int i, int j)
{
    chk[i][j] = true;
    int count = 1;
    for (int d = 0; d < 4; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if (out_of_range(ni, nj)) continue;
        if (chk[ni][nj]) continue;
        count += dfs(ni, nj);
    } 
    return count;
}

void solve()
{
    int count = 0;
    std::vector<int> areas;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (chk[i][j]) continue;
            areas.push_back(dfs(i, j));
            count++;
        }
    }
    std::sort(areas.begin(), areas.end());
    std::cout << count << "\n";
    for (auto area : areas)
        std::cout << area << " ";
}

inline void check_box(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++)
            chk[i][j] = true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> m >> n >> k;

    int x1, y1, x2, y2;
    while (k--) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        check_box(x1, y1, x2, y2);
    }

    solve();
    std::cout << std::endl;
    return 0;
}
