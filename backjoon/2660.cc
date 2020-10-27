#include <iostream>

int dist[51][51];
int n;

void floyd_warshall()
{
    for (int jc = 1; jc <= n; ++jc) {
        for (int src = 1; src <= n; ++src) {
            if (src == jc) continue;
            for (int dst = 1; dst <= n; ++dst) {
                if (dst == src || dst == jc) continue;
                if (dist[src][dst] > dist[src][jc] + dist[jc][dst])
                    dist[src][dst] = dist[src][jc] + dist[jc][dst];
            }
        }
    }
}

void print_result()
{
    int (&maxs)[51] = dist[0];
    for (int i = 1; i <= n; ++i) {
        int max = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (dist[i][j] > max)
                max = dist[i][j];
        }
        maxs[i] = max;
    }

    int candidate_score = 51;
    for (int i = 1; i <= n; ++i) {
        if (maxs[i] < candidate_score)
            candidate_score = maxs[i];
    }
    std::cout << candidate_score << " ";

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (maxs[i] == candidate_score)
            count++;
    }
    std::cout << count << "\n";

    for (int i = 1; i <= n; ++i) {
        if (maxs[i] == candidate_score)
            std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = 51;

    int u, v;
    do {
        std::cin >> u >> v;
        if (u == -1) break;
        dist[u][v] = dist[v][u] = 1;
    } while(true);

    floyd_warshall();

    print_result();

    return 0;
}
