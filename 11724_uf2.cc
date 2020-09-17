#include <iostream>
#include <vector>

struct UF {
	std::vector<int> id;
	std::vector<int> sz;
	int count;

	UF(int n) : id(n+1), sz(n+1, 1), count(n)
	{
		auto beg = id.begin();
		auto end = id.end();
		for (auto it = beg + 1; it != end; ++it)
			*it = it - beg;
	}

	int root_find_pc(int v)
	{
		if (id[v] == v) return v;
		return id[v] = root_find_pc(id[v]);
	}

	void wq_union_pc(int u, int v)
	{	
		int i = root_find_pc(u);
		int j = root_find_pc(v);
		
		if (i == j) return;
		if (sz[i] > sz[j]) { id[i] = j; sz[i] += sz[j]; }
		else			   { id[j] = i; sz[j] += sz[i]; }
		count--;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;
	UF uf(N);

	if (M > N*(N-1)/2) {
		std::cout << 1 << std::endl;
		return 0;
	}

	int u, v;
	for (int i = 0; i < M; ++i) {
		std::cin >> u >> v;
		uf.wq_union_pc(u,v);
	}

	std::cout << uf.count << std::endl;

	return 0;
}
