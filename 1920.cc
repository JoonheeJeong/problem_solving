#include <iostream>
#include <algorithm> // sort

struct Find_nums {
	static constexpr int MAX_CAP = 100000;
	Find_nums(int n) : n(n) {
		for (int i = 0; i < n; ++i) {
			std::cin >> arr[i];
		}
		std::sort(arr, arr+n);
	}

	void solve(int s);

private:
	int n;
	int arr[MAX_CAP];

	bool binary_search(int lo, int hi, int s);
};

bool Find_nums::binary_search(int lo, int hi, int s)
{
	if (lo > hi) 
		return false;

	int mid = (lo + hi) / 2;
	if (arr[mid] < s)
		return binary_search(mid+1, hi, s);
	else if (arr[mid] > s)
		return binary_search(lo, mid-1, s);
	else
		return true;
}

void Find_nums::solve(int s)
{
	int res = binary_search(0, n-1, s) ? 1 : 0;
	std::cout << res << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m, s;
	std::cin >> n;
	Find_nums fn(n);
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		std::cin >> s;
		fn.solve(s);
	}
	std::cout << std::flush;
	return 0;
}
