#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

struct Stuff {
    int w, v;
    Stuff(int w, int v) : w(w), v(v) {}
};

inline int max(int a, int b) { return a >= b ? a : b; }

struct Knapsack {
    int n, k;
    std::vector<Stuff> stuffs;
    std::vector<std::vector<int>> cache;
    Knapsack(int n, int k, std::ifstream &ifs);
    int solve(int i, int cap);
    int solve();
};

Knapsack::Knapsack(int n, int k, std::ifstream &ifs) : n(n), k(k)
{
    int w, v;
    int temp = n;
    while (temp--) {
        ifs >> w >> v;
        stuffs.push_back(std::move(Stuff(w,v)));
        cache.push_back(std::move(std::vector<int>(k+1, -1)));
    }
}

int Knapsack::solve(int i, int cap)
{
    if (i == n) return 0;
    int &ret = cache[i][cap];
    if (ret != -1) return ret;
    ret = solve(i+1, cap);
    const int &w = stuffs[i].w;
    const int &v = stuffs[i].v;
    if (w <= cap && v != 0)
        ret = max(ret, v + solve(i+1, cap-w));
    return ret;
}

int Knapsack::solve()
{
    return solve(0, k);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ifstream ifs("./testcase/12865_tc.txt", std::ios::in);
    int n, k;
    do {
        ifs >> n >> k;
        if (ifs.eof()) 
            break;
        Knapsack knapsack(n, k, ifs);
        std::cout << knapsack.solve() << std::endl;
    } while (true);
    return 0;
}
