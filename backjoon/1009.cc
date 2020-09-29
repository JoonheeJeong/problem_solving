#include <iostream>
#include <vector>
#include <array>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::array<std::vector<int>, 10> dp;

	for (int i = 0; i < 10; i++) {
		std::vector<int> &v = dp[i];
		int temp = i % 10;
		do {
			if (temp == 0)
				v.push_back(10);
			else
				v.push_back(temp);
			temp *= i % 10;
			temp %= 10;
		} while(temp != i % 10);
	}

	int t, a, b;
	std::cin >> t;
	while (--t >= 0) {
		std::cin >> a >> b;
		int term = dp[a % 10].size();
		std::cout << dp[a % 10][(b-1) % term] << "\n";
	}
	std::cout << std::flush;
	return 0;
}
