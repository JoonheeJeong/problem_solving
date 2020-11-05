#include <iostream>
// #include <fstream> // for test
#include <vector>

const int INF = 2'000'000'000;

struct Min_Cycle {
    int V, E;
    std::vector<std::vector<int>> edges;
    Min_Cycle(int V, int E, std::istream &is);
    int solve();
};

Min_Cycle::Min_Cycle(int V, int E, std::istream &is)
    : V(V), E(E), edges(V, std::vector<int>(V, INF))
{
    int org, dst;
    for (int i = 0; i < E; ++i) {
        is >> org >> dst;
        is >> edges[org-1][dst-1];
    }
}

int Min_Cycle::solve()
{
    for (int bridge = 0; bridge < V; ++bridge) {
        for (int org = 0; org < V; ++org) {
            if (bridge == org) continue;
            if (edges[org][bridge] == INF) continue;
            for (int dst = 0; dst < V; ++dst) {
                if (bridge == dst) continue;
                if (edges[org][dst] > edges[org][bridge] + edges[bridge][dst])
                    edges[org][dst] = edges[org][bridge] + edges[bridge][dst];
            }
        }
    }

    int min = INF;
    for (int i = 0; i < V; ++i)
        if (edges[i][i] < min)
            min = edges[i][i];
    return (min != INF) ? min : -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int V, E;
    std::istream &is = std::cin;
    // std::istream &is = std::ifstream; // for test
    is >> V >> E;
    Min_Cycle mc(V, E, is);
    std::cout << mc.solve() << std::endl;
    return 0;
}
