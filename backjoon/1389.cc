#include <iostream>
#include <numeric>

int stg[101][101];
int n;

int find_min_kb() noexcept
{
	int min = INT32_MAX;
	int min_i = -1;
	for (int i = 1; i <= n; ++i) {
		int sum = std::accumulate(stg[i] + 1, stg[i] + n + 1, 0);
		if (min > sum) {
			min = sum;
			min_i = i;
		}
	}
	return min_i;
}

void find_shortest_stg() noexcept
{
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			if (k == i) continue;
			if (stg[i][k] == 0) continue;
			for (int j = 1; j <= n; ++j) {
				if (k == j || i == j) continue;
				if (stg[k][j] == 0) continue;
				if (stg[i][j] == 0 || stg[i][j] > stg[i][k] + stg[k][j])
					stg[i][j] = stg[i][k] + stg[k][j];
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int m;
	std::cin >> n >> m;

	int u, v;
	while (m--) {
		std::cin >> u >> v;
		stg[u][v] = stg[v][u] = 1;
	}

	find_shortest_stg();
	std::cout << find_min_kb() << std::endl;
	return 0;
}
