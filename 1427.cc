#include <iostream>
#include <string>

int cnt[10];

int main()
{
	int n;
	std::cin >> n;
	while (n != 0) {
		cnt[n % 10]++;
		n /= 10;
	}
	
	for (int i = 9; i >= 0; --i) {
		std::string s(cnt[i], i+'0');
		std::cout << s;
	}
	std::cout << std::endl;
	return 0;	
}
