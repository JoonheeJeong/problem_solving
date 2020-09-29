#include <iostream>
#include <queue>
#include <algorithm> // fill

struct Find_path_count {
	static constexpr int di[] { -2, -1, 1, 2, 2, 1, -1, -2 };
	static constexpr int dj[] { 1, 2, 2, 1, -1, -2, -2, -1 };
	static constexpr int MAX_CAP = 300;
	static bool board[MAX_CAP][MAX_CAP];
	static std::queue<int> q;

	Find_path_count(int l, int si, int sj, int gi, int gj);

private:
	int l, si, sj, gi, gj;
	bool out_of_range(int i, int j)
	{
		if (i < 0 || j < 0 || i >= l || j >= l) return true;
		return false;
	}
	void move_next(int i, int j, int d);
	int solve();
};

decltype(Find_path_count::di) Find_path_count::di;
decltype(Find_path_count::dj) Find_path_count::dj;
decltype(Find_path_count::board) Find_path_count::board;
decltype(Find_path_count::q) Find_path_count::q;

void Find_path_count::move_next(int i, int j, int d)
{
	int next_i = i + di[d];
	int next_j = j + dj[d];
	if (out_of_range(next_i, next_j)) return;
	if (board[next_i][next_j]) return;
	board[next_i][next_j] = true;
	q.push(next_i);
	q.push(next_j);
}

int Find_path_count::solve()
{
	board[si][sj] = true;
	q.push(si);
	q.push(sj);
	int count = -1;
	while (!q.empty()) {
		count++;
		int n = q.size() / 2;
		for (int k = 0; k < n; ++k) {
			int i = q.front();
			q.pop();
			int j = q.front();
			q.pop();
			if (i == gi && j == gj) goto END;
			for (int d = 0; d < 8; ++d) move_next(i, j, d);
		}
	} 
END:
	while (!q.empty()) q.pop();
	for (auto row : board) std::fill(row, row + MAX_CAP, false);
	return count;
}

Find_path_count::Find_path_count(int l, int si, int sj, int gi, int gj)
	: l(l), si(si), sj(sj), gi(gi), gj(gj)
{
	std::cout << solve() << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t, l, si, sj, gi, gj;
	std::cin >> t;
	while (t--) {
		std::cin >> l >> si >> sj >> gi >> gj;
		Find_path_count fpc(l, si, sj, gi, gj);
	}
	std::cout << std::flush;
	return 0;
}
