// bottom-up
#include <iostream>

int cache[31] {1};

int main()
{
    int n;
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    for (int i = 2; i <= n; i += 2) {
        int cache_i = cache[i-2] * 3;
        for (int j = 4; j <= i; j += 2) {
            cache_i += cache[i-j] * 2;
        }
        cache[i] = cache_i;
    }

    std::cout << cache[n] << std::endl;
    return 0;
}
