#include <iostream>

int main()
{
	auto count_changes = [] (int &k, const int &div) {
		int quot = k / div;
		k -= div * quot;
		return quot;
	};
	
	int k, result = 0;
	
	std::cin >> k;
	
	k = 1000 - k;
	result += count_changes(k, 500);
	result += count_changes(k, 100);
	result += count_changes(k, 50);
	result += count_changes(k, 10);
	result += count_changes(k, 5);
	result += count_changes(k, 1);

	std::cout << result << std::endl;

	return 0;
}
