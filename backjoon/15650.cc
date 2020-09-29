#include <iostream>
#include <string>

void comb(std::string out, int pos, int n, int m)
{
	if (m == 0) {
		std::cout << out << "\n";
		return;
	}
	if (n - pos + 1 < m)
		return;
	comb(out+std::to_string(pos)+" ", pos+1, n, m-1);
	comb(out, pos+1, n, m);
}

void comb(int n, int m)
{
	comb("", 1, n, m);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	comb(n, m);
	return 0;
}
