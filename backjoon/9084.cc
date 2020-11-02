#include <iostream>

int cache[20][10001];
int coins[20];
int n, m;

int find_cases(int k, int goal)
{
    if (goal == 0) return 1;
    if (k == n || coins[k] > goal) return 0;

    int &ret = cache[k][goal];
    if (ret != -1) return ret;

    return ret = find_cases(k, goal-coins[k]) + find_cases(k+1, goal);
}

void init_cache()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j)
            cache[i][j] = -1;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    do {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
            std::cin >> coins[i];
        std::cin >> m;
        init_cache();
        std::cout << find_cases(0, m) << "\n";
    } while (--t);

    std::cout << std::flush;
    return 0;
}
