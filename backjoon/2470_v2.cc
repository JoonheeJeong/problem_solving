#include <iostream>
#include <vector>
#include <algorithm> // sort

int main()
{
    std::vector<int> v;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }

    std::sort(v.begin(), v.end());

    int ret[2] {};
    int cv_min = 2000000000;
    int lo = 0;
    int hi = n-1;
    do {
        int cv = std::abs(v[lo] + v[hi]);
        if (cv < cv_min) {
            cv_min = cv;
            ret[0] = v[lo];
            ret[1] = v[hi];
        }
        if (v[lo] + v[hi] > 0)       hi--;
        else if (v[lo] + v[hi] < 0)  lo++;
        else                         break;
    } while (lo < hi);

    std::cout << ret[0] << " " << ret[1] << std::endl;
    return 0;
}
