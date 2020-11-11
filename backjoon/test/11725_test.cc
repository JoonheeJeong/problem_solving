#include <iostream>
#include <vector>

#include <fstream>

struct Find_parent {
    Find_parent(int n, std::istream &is);
    void solve();
private:
    void dfs(int v);

    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> parent;
};

Find_parent::Find_parent(int n, std::istream &is)
    : n(n), adj(n+1, std::vector<int>()), parent(n+1)
{
    int u, v;
    for (int i = 1; i < n; ++i) {
        is >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void Find_parent::solve()
{
    parent[1] = 1;
    dfs(1);

    for (int i = 2; i <= n; ++i)
        std::cout << parent[i] << "\n";
    std::cout << std::endl;
}

void Find_parent::dfs(int v)
{
    for (int &u: adj[v]) {
        if (parent[u] != 0) continue;
        parent[u] = v;
        dfs(u);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ifstream ifs("./testcase/11725_tc.txt");
    std::istream &is = ifs;
    int n;
    is >> n;
    Find_parent fp(n, is);
    fp.solve();
    return 0;
}
