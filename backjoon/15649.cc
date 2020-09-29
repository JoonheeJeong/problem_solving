#include <iostream>
#include <array>
#include <vector>
#include <string> // to_string
#include <algorithm> // for_each

constexpr const int MAX_SIZE = 8;
std::array<std::string, MAX_SIZE + 1> v;

std::array<bool, MAX_SIZE + 1> chk;
std::vector<std::string> out;

void print()
{
	std::for_each(out.cbegin(), out.cend(), [](const std::string &s) {std::cout << s;});
	std::cout << "\n";
}

void solve(int n, int m)
{
	if (m == 0) {
		print();
		return;
	}

    for (int i = 1; i <= n; ++i) {
		if (chk[i])
			continue;
		chk[i] = true;
		out.push_back(v[i]);
        solve(n, m-1);
		out.pop_back();
		chk[i] = false;
	}
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

	for (int i = 1; i <= MAX_SIZE; ++i)
		v[i] = std::to_string(i).append(" ");

    int n, m;

    std::cin >> n >> m;

    solve(n, m);
	std::cout << std::flush;

    return 0;
}
