#include <iostream>
#include <vector>
#include <utility> // move

int N, M;
std::vector<std::vector<bool>> g;
std::vector<bool> chk;
int count = 0;
int rem = N;

void dfs(int u)
{
	int n = 0;
	for (int v = 1; v <= N; ++u) {
		if (!chk[v] && g[u][v]) {
			chk[v] = true;
			n++;
			dfs(v);
		}
	}
	if (n != 0)
		count++;
}

int count_conn_components()
{
	int count = 0;

	for (int i = 1; i <= N; ++i) {
		if (!chk[i]) {
			dfs(i);
			count++;
		}
	}

	return count;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N >> M;

	g.resize(N+1);
	for (int i = 1; i <= N; ++i) {
		std::vector<bool> e(N+1);
		g[i] = std::move(e);
	}

	int u, v;
	for (int i = 0; i < M; ++i) {
		std::cin >> u >> v;
		g[u][v] = g[v][u] = true;
	}

	chk.resize(N+1);
	std::cout << count_conn_components() << std::endl;
	
	return 0;
}
