#include <iostream>
//#include <map> 

//static std::map<int, int> cnt; // timeover..
static constexpr const int OFFSET = 10000000;
static int cnt[2*OFFSET + 1];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, temp;
    std::cin >> n;
    while (n--) {
        std::cin >> temp;
        cnt[temp+OFFSET]++;
    }

    std::cin >> m;
    while (m--) {
        std::cin >> temp;
        std::cout << cnt[temp+OFFSET] << " ";
    }
    std::cout << std::endl;
    return 0;
}
