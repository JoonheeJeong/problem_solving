#include <iostream>
#include <vector>

struct UF {
	std::vector<int> id;
	std::vector<int> sz;
	int count;

	UF(int n) : sz(n+1, 1), count(n)
	{
		for (int i = 0; i <= n; ++i)
			id.push_back(i);
	}

	int quick_find(int v)
	{
		return id[v];
	}

	int root_find(int v)
	{
		int v_id = id[v];
		while (v != v_id) {
			v = v_id;
			v_id = id[v];
		}
		return v;
	}	
	
	int root_find_pc(int v)
	{
		int r = v;
		int r_id = id[r];
		while (r != r_id) {
			r = r_id;
			r_id = id[r];
		}

		int v_id = id[v];
		while (v_id != r) {
			id[v] = r;
			v = v_id;
			v_id = id[v];
		}

		return r;
	}

	void for_each_union(int u, int v)
	{
		int u_id = quick_find(u);
		int v_id = quick_find(v);
		if (u_id == v_id)
			return;
		int n = id.size();
		for (int i = 1; i < n; ++i)
			if (id[i] == u_id)
				id[i] = v_id;
		count--;
	}

	void quick_union(int u, int v)
	{
		int i = root_find(u);
		int j = root_find(v);
		if (i == j)
			return;
		id[i] = j;
		count--;
	}

	void weighted_quick_union(int u, int v)
	{
		int i = root_find(u);
		int j = root_find(v);
		if (i == j)
			return;

		if (sz[i] > sz[j]) {
			id[i] = j;
			sz[i] += sz[j];
		}
		else {
			id[j] = i;
			sz[j] += sz[i];
		}
		count--;
	}

	void wq_union_pc(int u, int v)
	{	
		int i = root_find_pc(u);
		int j = root_find_pc(v);
		if (i == j)
			return;

		if (sz[i] > sz[j]) {
			id[i] = j;
			sz[i] += sz[j];
		}
		else {
			id[j] = i;
			sz[j] += sz[i];
		}
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

	int u, v;
	for (int i = 0; i < M; ++i) {
		std::cin >> u >> v;
		uf.wq_union_pc(u,v);
	}
	std::cout << uf.count << std::endl;
	return 0;
}
