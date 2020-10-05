#include <iostream>

bool qt[64][64];

bool compressable(int i, int j, int n)
{
    int temp = qt[i][j];
    int end_k = i+n;
    int end_l = j+n;
    for (int k = i; k < end_k; k++) {
        for (int l = j; l < end_l; l++) {
            if(qt[k][l] != temp)
                return false;
        }
    }
    return true;
}

void solve(int i, int j, int n)
{
    if (n == 1) {
        std::cout << qt[i][j];
        return;
    }

    n /= 2;
    bool comp[4] {
        compressable(i, j, n),
        compressable(i, j+n, n),
        compressable(i+n, j, n),
        compressable(i+n, j+n, n)
    };
    bool res[4] {
        qt[i][j],
        qt[i][j+n],
        qt[i+n][j],
        qt[i+n][j+n]
    };
    if (comp[0] && comp[1] && comp[2] && comp[3]
            && res[0] == res[1]
            && res[0] == res[2]
            && res[0] == res[3]) {
        std::cout << res[0];
        return;
    }

    std::cout << "(";
    if(comp[0]) std::cout << res[0];
    else        solve(i, j, n);

    if(comp[1]) std::cout << res[1];
    else        solve(i, j+n, n);

    if(comp[2]) std::cout << res[2];
    else        solve(i+n, j, n);

    if(comp[3]) std::cout << res[3];
    else        solve(i+n, j+n, n);
    std::cout << ")";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> c;
            qt[i][j] = c - '0';
        }
    }

    solve(0, 0, n);
    std::cout << std::endl;
    return 0;
}
