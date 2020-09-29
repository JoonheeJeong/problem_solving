#include <iostream>

int main()
{
	int x;
	std::cin >> x;

	int count = 0;
	int len = 64;
	do {
		if (x == len) { 
			count++; 
			break; 
		}
		if (x > len) { 
			count++; 
			x -= len;
		}
		len /= 2;
	} while(len > 0);
	std::cout << count << std::endl;
	return 0;
}
