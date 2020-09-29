#include <iostream>
#include <array>

struct Count_islands {
	Count_islands(int w, int h);
	int operator()();
private:
	static constexpr int di[8] { -1, -1, 0, 1, 1, 1, 0, -1 };
	static constexpr int dj[8] { 0, 1, 1, 1, 0, -1, -1, -1 };
	std::array<std::array<bool, 50>, 50> board;
	std::array<std::array<bool, 50>, 50> chk;
	int w, h, count;

	inline bool out_of_range(int i, int j);
	void dfs(int i, int j);
};

constexpr int Count_islands::di[8];
constexpr int Count_islands::dj[8];

bool Count_islands::out_of_range(int i, int j)
{
	if (i < 0 || j < 0 || i >= h || j >= w) return true;
	return false;
}

Count_islands::Count_islands(int w, int h) : w(w), h(h), count(0) 
{	
	for (int i = 0; i < h; i++) {
		chk[i].fill(false);
		for (int j = 0; j < w; j++)
			std::cin >> board[i][j];
	}
}

void Count_islands::dfs(int i, int j)
{
	int next_i, next_j;
	for (int d = 0; d < 8; ++d) {
		next_i = i + di[d];
		next_j = j + dj[d];
		if (out_of_range(next_i, next_j) 
		 || !board[next_i][next_j]
		 || chk[next_i][next_j])
			continue;
		chk[next_i][next_j] = true;
		dfs(next_i, next_j);
	} 
}

int Count_islands::operator()()
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!board[i][j] || chk[i][j])
				continue;
			dfs(i, j);
			count++;
		}
	}
	return count;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int w, h;
	while (std::cin >> w >> h) {
		if (w == 0 && h == 0)
			break;
		Count_islands count_islands(w, h);
		std::cout << count_islands() << "\n";
	}

	std::cout << std::endl;

	return 0;
}
