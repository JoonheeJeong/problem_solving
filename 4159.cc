#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, k;
	std::vector<int> v;

	do {
		v.clear();
		std::cin >> n;

		if (n == 0)
			break;

		if (n < 8) {
			while (--n >= 0)
				std::cin >> k;
IMPOSSIBLE:
			std::cout << "IMPOSSIBLE" << std::endl;
			continue;
		}

		while (--n >= 0) {
			std::cin >> k;
			v.push_back(k);
		}
		auto beg = v.begin();
		auto end = v.end();
		std::sort(beg, end);
		for (auto it = beg + 1; it != end; it++) {
			if (*it - *(it - 1) > 200)
				goto IMPOSSIBLE;
		}

		if ((1422 - v.back()) * 2 > 200)
			goto IMPOSSIBLE;
		std::cout << "POSSIBLE" << std::endl;
	} while (true);

	std::cout << std::endl;
	return 0;
}
