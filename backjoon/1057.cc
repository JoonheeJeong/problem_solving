#include <iostream>

int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;

    int res = 1;
    while (true) {
        a = (a+1)/2;
        b = (b+1)/2;
        if (a == b) {
            std::cout << res << std::endl;
            return 0;
        }
        res++;
    }

    return 0;
}
