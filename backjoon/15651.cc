#include <iostream>
#include <vector>
#include <string>

int n, m;

void n_and_m(int cnt, std::string s)
{
    if (cnt == m) {
        std::cout << s << "\n";
        return;
    }

    for (int i = 1; i <= n; ++i)
        n_and_m(cnt+1, s + std::to_string(i) + " ");
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m;

    n_and_m(0, "");

    return 0;
}
