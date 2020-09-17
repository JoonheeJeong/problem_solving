#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // reverse, sort
#include <utility> // move

bool exist_same_start(std::vector<std::string> &nums, int len)
{
	auto beg = nums.cbegin();
	auto end = nums.cend();
	std::string src = (*beg).substr(0, len);
	std::string target;
	for (auto it = beg+1; it != end; it++) {
		target = std::move((*it).substr(0, len));
		if (src == target)
			return true;
		src = std::move(target);
	}
	return false;
}

int solve(std::vector<std::string> &nums, int len)
{
	/* brute force
	for (int i = 1; i <= len; ++i)
		if (!exist_same_start(nums, i))
			return i;
	return -1;
	*/

	/* binary search */
	int lo, hi, mid;
	
	lo = 1;
	hi = len;

	while (hi - lo > 0) {		
		mid = (lo + hi) / 2;
		if (exist_same_start(nums, mid))
			lo = mid + 1;
		else
			hi = mid;
	}
	if(exist_same_start(nums, lo))
		return -1; // error input
	return lo;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::string s;
	std::vector<std::string> nums;

	std::cin >> n;
	while(std::cin >> s) {
		std::reverse(s.begin(), s.end());
		nums.push_back(s);
	}

	int len = s.size();

	std::sort(nums.begin(), nums.end());

	std::cout << solve(nums, len) << std::endl;

	return 0;
}
