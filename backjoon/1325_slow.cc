// slow 3412ms
#include <iostream>
#include <vector>
#include <algorithm>

struct Hacking {
    int v, e;
    std::vector<int> cnts;
    std::vector<bool> visited;
    std::vector<std::vector<int>> g;

    Hacking(int v, int e, std::istream &is);
    int dfs(int n);
    void solve();
    
};

Hacking::Hacking(int v, int e, std::istream &is)
    : v(v), e(e), cnts(v+1), visited(v+1), g(v+1, std::vector<int>())
{
    int org, dst;
    for (int i = 0; i < e; i++) {
        is >> dst >> org;
        g[org].push_back(dst);
    }
}

int Hacking::dfs(int n)
{
    visited[n] = true;
    int cnt = 1;
    for (int &dst : g[n]) {
        if (visited[dst]) continue;
         cnt += dfs(dst);
    }
    return cnt;
}

void Hacking::solve()
{
    int max_cnt = 0;
    for (int i = 1; i <= v; ++i) {
        std::fill(visited.begin(), visited.end(), false);
        int cnt = cnts[i] = dfs(i);
        if (cnt > max_cnt)
            max_cnt = cnt;
    }

    for (int i = 1; i <= v; ++i)
        if (cnts[i] == max_cnt)
            std::cout << i << " ";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int v, e;
    std::istream &is = std::cin;
    is >> v >> e;
    Hacking h(v, e, is);
    h.solve();
    std::cout << std::endl;
    return 0;
}
