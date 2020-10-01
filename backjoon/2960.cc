#include <iostream>

bool chk[1001];
int n, k;

int main()
{
    std::cin >> n >> k;
    int count = 0;
    int p = 2;
    while (p <= n) {
        int mul = p;
        while (mul <= n) {
            if (!chk[mul]) {
                chk[mul] = true;
                count++;
                if (count == k) {
                    std::cout << mul << std::endl;
                    return 0;
                }

            }
            mul += p;
        }
        for (p = p + 1; p <= n; ++p)
            if (!chk[p])
                break;
    }

    return 0;
}
