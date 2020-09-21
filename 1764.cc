#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::set<std::string> bodo;
	std::vector<std::string> v;
	std::string s;
	int n, m;

	std::cin >> n >> m;
	while (n--) {
		std::cin >> s;
		bodo.insert(s);
	}
	while (m--) {
		std::cin >> s;
		auto search = bodo.find(s);
		if (search == bodo.end()) continue;
		v.push_back(s);
	}
	std::sort(v.begin(), v.end());
	std::cout << v.size() << "\n";
	std::for_each(v.begin(), v.end(), [](std::string s) { std::cout << s << "\n"; });
	std::cout << std::flush;
	return 0;
}
