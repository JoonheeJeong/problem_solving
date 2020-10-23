#include <iostream>

const int MAX_SIZE = 100, INF = 10001;
int values[MAX_SIZE], cache[MAX_SIZE][INF];
int n, k;

inline int min(int a, int b) { return a < b ? a : b; }

int solve(int pos, int goal)
{
    if (pos == n) return (goal == 0) ? 0 : INF;

    int &ret = cache[pos][goal];
    if (ret != -1) return ret;

    ret = solve(pos+1, goal);
    if (values[pos] <= goal)
        ret = min(ret, 1+solve(pos, goal-values[pos]));
    return ret;
}

int solve()
{
    for (int i = 0; i < n; i++) {
        int (&row)[INF] = cache[i];
        std::fill(row, row+k+1, -1);
    }
    int ret = solve(0, k);
    if (ret == INF)
        ret = -1;
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
        std::cin >> values[i];

    int ans = solve();
    std::cout << ans << std::endl;

    return 0;
}
