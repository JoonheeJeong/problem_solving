#include <iostream>
#include <vector>
#include <algorithm> // sort

inline int cv(const int &a, const int &b)
{
    int ret = a + b;
    return ret < 0 ? -ret : ret;
}

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
    int min = 2000000000;
    for (int i = 0; i < n-1 && min != 0; ++i) {
        int vi = v[i];
        int lo = i+1;
        if (vi + v[lo] >= 0) {
            if (vi + v[lo] < min) {
                min = cv(vi, v[lo]);
                ret[0] = vi;
                ret[1] = v[lo];
            }
            continue;
        }

        int hi = n-1;
        if (vi + v[hi] < 0) {
            if (vi + v[hi] < min) {
                min = cv(vi, v[hi]);
                ret[0] = vi; 
                ret[1] = v[hi];
            }
            continue;
        }

        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (vi +  v[mid] < 0) lo = mid;
            else                  hi = mid;
        }

        int temp_min, temp_ret;
        int cv_hi = cv(vi, v[hi]);
        int cv_lo = cv(vi, v[lo]);
        if (cv_hi <= cv_lo) {
            temp_min = cv_hi;
            temp_ret = hi;
        } else {
            temp_min = cv_lo;
            temp_ret = lo;
        }
        if (temp_min < min) {
            min = temp_min;
            ret[0] = vi;
            ret[1] = v[temp_ret];
        }
    }

    std::cout << ret[0] << " " << ret[1] << std::endl;
    return 0;
}
