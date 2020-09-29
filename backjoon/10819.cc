#include <iostream>
#include <vector>

std::vector<int> v;
std::vector<int> s;
bool chk[8];
int n;

int solve(int pos)
{
	if (pos == n) {
		auto beg = s.begin();
		auto end = s.end();
		int res = 0;
		for (auto it = beg + 1; it != end; ++it) {
			int temp = *it - *(it - 1);
			res += (temp >= 0) ? temp : -temp;
		}
		return res;
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (chk[i]) continue;
		chk[i] = true;
		s.push_back(v[i]);
		int temp = solve(pos + 1);
		if (res < temp)
			res = temp;
		s.pop_back();
		chk[i] = false;
	}
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int k;
	std::cin >> n;
	int temp = n;
	while (temp--) {
		std::cin >> k;
		v.push_back(k);
	}

	std::cout << solve(0) << std::endl;
	return 0;
}
