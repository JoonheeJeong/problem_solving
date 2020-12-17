#include <iostream>
#include <vector>
#include <string>

int n, m;
std::vector<int> v;
std::string ret = "";

void n_and_m(int cnt)
{
    if (cnt == m) {
        for (auto &e : v) {
            ret += (char) e + 48;
            ret += " ";
        }
        ret += "\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        v[cnt] = i;
        n_and_m(cnt+1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m;
    v.resize(m);

    n_and_m(0);
    std::cout << ret;

    return 0;
}
