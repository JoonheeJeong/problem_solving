#include <iostream>
#include <vector>

struct UF {
	std::vector<int> id;
	std::vector<int> sz;
	int count;

	UF(int n) : count(n), sz(n+1, 1)
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
	
	void for_each_union(int u, int v)
	{
		int u_id = quick_find(u);
		int v_id = quick_find(v);
		if (u_id == v_id)
			return;
		for (int i = 1; i <= n; ++i)
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

		int i_sz = sz[i];
		int j_sz = sz[j];
		if (i_sz > j_sz) {
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
	int N, M;

	std::cin >> N >> M;
	UF uf(N);
}
