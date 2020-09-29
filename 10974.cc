#include <iostream>
#include <string>

struct Permutation {
	static constexpr int MAX_CAP = 8;
	int chk[MAX_CAP+1] {};
	int n;

	Permutation(int n) : n(n) {}

	void operator()();

private:
	void run(int count, std::string s);
};

void Permutation::run(int count = 0, std::string s = "")
{
	if (count == n) {
		std::cout << s << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (chk[i]) continue;
		chk[i] = true;
		run(count+1, s + std::to_string(i) + " ");
		chk[i] = false;
	}
}

void Permutation::operator()()
{
	run();
	std::cout << std::flush;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	Permutation p(n);
	p();
	return 0;
}
