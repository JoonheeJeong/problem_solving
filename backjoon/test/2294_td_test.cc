#include <iostream>

// for test
#include <fstream>

const int MAX_SIZE = 100, INF = 10001;
int values[MAX_SIZE], cache[MAX_SIZE][INF];
int n, k;

inline const int min(const int &a, const int &b) { return a < b ? a : b; }

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

    std::ifstream ifs("./testcase/2294_tc.txt", std::ios::in);
    do {
        ifs >> n >> k;
        if (ifs.eof()) break;
        for (int i = 0; i < n; ++i)
            ifs >> values[i];

        int ans = solve();
        std::cout << ans << "\n";
        int crt;
        ifs >> crt;
        if (crt != ans) {
            std::cerr << "expected answer: " << crt << std::endl;
            break;
        }
    } while (true);

    return 0;
}
