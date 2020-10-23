#include <iostream>
#include <algorithm>

// for test
#include <fstream>

const int MAX_SIZE = 100, INF = 10001;
int values[MAX_SIZE], cache[INF];
int size, goal;

int solve()
{
    std::fill(cache+1, cache+INF, INF);

    std::sort(values, values+size);
    auto last = std::unique(values, values+size);
    int end = last - values;

    for (int i = 0; i < end; ++i) {
        int j = 0;
        int k = values[i];
        while (k <= goal) {
            if (cache[k] > cache[j] + 1)
                cache[k] = cache[j] + 1;
            j++;
            k++;
        }
    }

    int ret = cache[goal];
    if (ret == INF) ret = -1;
    return ret;
}

int main()
{
    std::ifstream ifs("./testcase/2294_tc.txt", std::ios::in);
    do {
        ifs >> size >> goal;
        if (ifs.eof()) break;
        for (int i = 0; i < size; ++i)
            ifs >> values[i];

        int ans = solve();
        std::cout << ans << "\n";
        int crt;
        ifs >> crt;
        if (crt != ans) {
            std::cerr << "expected answer: " << crt << std::endl;
            break;
        }
    } while (true);

    return 0;
}
