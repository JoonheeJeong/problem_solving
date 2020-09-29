#include <iostream>

int dp[15];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t, k, n;
	std::cin >> t;
	while(t--) {
		std::cin >> k >> n;
		for (int i = 1; i <= n; ++i) {
			dp[i] = i;
		}
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[j] += dp[j-1];
			}
		}
		std::cout << dp[n] << "\n";
	}
	std::cout << std::flush;
	return 0;
}
