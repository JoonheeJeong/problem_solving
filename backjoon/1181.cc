#include <iostream>
#include <string>
#include <list>

struct cmp_str {
	bool operator()(const std::string &lhs, const std::string &rhs)
	{
		if (lhs.size() == rhs.size()) {
			auto l_it = lhs.cbegin();
			auto l_end = lhs.cend();
			auto r_it = rhs.cbegin();
			do {
				if (l_it == l_end) return false;
				if (*l_it == *r_it) { l_it++; r_it++; }
				else return *l_it < *r_it;
			} while (true);
		}
		else if (lhs.size() < rhs.size()) return true;
		else							  return false;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::list<std::string> l;
	int n;
	std::cin>> n;

	std::string s;
	while (--n >= 0) {
		std::cin >> s;
		l.push_back(s);
	}

	l.sort(cmp_str());
	l.unique();
	for (auto e : l) std::cout << e << "\n";
	std::cout << std::flush;
	return 0;
}
