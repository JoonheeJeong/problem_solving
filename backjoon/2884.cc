#include <iostream>

int main()
{
	int h, m;
	std::cin >> h >> m;
	if (m-45 >= 0)
		std::cout << h << " " << m-45;
	else if (h != 0) {
		std::cout << h-1 << " " << m-45 + 60;
	} else {
		std::cout << h-1 + 24 << " " << m-45 + 60;
	}
	return 0;
}
