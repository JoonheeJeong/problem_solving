#include <iostream>
#include <algorithm>

struct Rope {
	static constexpr int MAX_CAP = 100000;

	Rope(int n) : n(n) {
		for (int i = 0; i < n; ++i) {
			std::cin >> weights[i];
		}
		solve();
	}

private:
	int n;
	int weights[MAX_CAP] {};

	void solve();
};

void Rope::solve()
{
	std::sort(weights, weights + n);

	int max = 0;
	for (int i = 0; i < n; ++i) {
		int temp = weights[i] * (n - i);
		if (temp > max)
			max = temp;
	}
	std::cout << max << std::endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	Rope rope(n);
	return 0;
}
