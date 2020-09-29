#include <iostream>
#include <vector>
#include <algorithm> // sort

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<long long> cl;
    int n;
    long long k;
    std::cin >> n;
    while (n--) {
        std::cin >> k;
        cl.push_back(k);
    }
    cl.push_back(INT64_MAX);

    auto beg = cl.begin();
    auto end = cl.end();
    std::sort(beg, end);

    int c = 0;
    int temp = 1;
    long long e = *beg;
    long long res = e;
    for (auto it = beg+1; it != end; it++) {
        if (*it != e) {
            if (c < temp) {
                c = temp; 
                res = e;
            }
            temp = 1;
            e = *it;
        }
        else
            temp++;
    }
    std::cout << res << std::endl;
    return 0;
}
