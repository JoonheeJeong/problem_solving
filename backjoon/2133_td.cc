// top-down
#include <iostream>
#include <algorithm>

int n;
int cache[31] { 1, 0, 3 };

int f(int n)
{
    if (n % 2 != 0) return 0;
    int &ret = cache[n];
    if (ret != -1) return ret;
    ret = 0;
    int i = n - 2;
    if (i >= 0) {
        ret += f(i) * 3;
        for (i -= 2; i >= 0; i -= 2)
            ret += f(i) * 2;
    }
    return ret;
}

int main()
{
    std::cin >> n;
    if (n > 2)
        std::fill(cache+3, cache+n+1, -1);
    std::cout << f(n) << std::endl;
    return 0;
}
