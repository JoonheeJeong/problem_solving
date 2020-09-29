/*
   132ms
   다소 느려서 좀 아쉬운데..
   나중에 다시 풀어봐야겠다.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath> // pow

struct Star_Recursive {
	const int base = 3;
	int exp;
	int n;
	std::vector<int> pows;
	std::vector<std::string> chk;

	Star_Recursive(int n) : exp(-1), chk(n, std::string(n, ' ')) 
	{
		std::vector<int> s;
		int tmp = n;
		do {
			s.push_back(tmp);
			exp++;
		} while ((tmp /= base) != 0);
		auto beg = s.crbegin();
		auto end = s.crend();
		for (auto it = beg; it != end; it++) pows.push_back(*it);
	};

	void operator()();

private:
	void solve(int vi, int vj, int i, int j, int k);
};

void Star_Recursive::operator()()
{
	solve(0, 0, 0, 0, exp+1);

	for (auto row : chk)
		std::cout << row << "\n";
	std::cout << std::endl;
}

void Star_Recursive::solve(int vi, int vj, int i, int j, int k)
{
	if (vi == 1 && vj == 1)
		return;
	if (k == 1) {
		chk[i][j] = '*';
		return;
	}

	for (int m = 0; m < base; ++m)
		for (int n = 0; n < base; ++n)
			solve(m, n, i + m*pows[k-2], j + n*pows[k-2], k-1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	Star_Recursive sr(n);
	sr();
	return 0;
}
