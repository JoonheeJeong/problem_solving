#include <iostream>

bool g[101][101];
int n;

void find_connection() noexcept
{
    for (int k = 1; k <= n; ++k) {
        for (int u = 1; u <= n; ++u) {
            if (!g[u][k]) continue;
            for (int v = 1; v <= n; ++v) {
                if (!g[k][v]) continue;
                g[u][v] = true;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> g[i][j];

    find_connection();

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            std::cout << g[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << std::flush;
    return 0;
}
