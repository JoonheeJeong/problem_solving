#include <iostream>
#include <string>
#include <algorithm> // sort
#include <functional> // greater

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end(), std::greater<>());
    bool res = true;
    if (s.back() != '0')
        res = false;
    int temp = 0;
    for (auto e : s)
        temp += e;
    temp -= s.size() * '0';
    if (temp % 3 != 0)
        res = false;

    std::cout << (res ? s : std::to_string(-1)) << std::endl;
    return 0;
}
