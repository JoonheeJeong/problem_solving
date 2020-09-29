#include <iostream>
#include <algorithm>

const int MAX_CAP = 1000001;
int dp[MAX_CAP] { 0, 0, 1, 1 };

int make_one(int n)
{
	if (n == 1) return 0;
	if (dp[n] != 0) return dp[n];

	int min = make_one(n-1);
	if (n % 2 == 0) min = std::min(min, make_one(n / 2));
	if (n % 3 == 0) min = std::min(min, make_one(n / 3));
	return dp[n] = min + 1;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << make_one(n) << std::endl;
	return 0;
}
