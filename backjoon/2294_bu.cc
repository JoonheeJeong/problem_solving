#include <iostream>
#include <algorithm>

const int MAX_SIZE = 100, INF = 10001;
int values[MAX_SIZE], cache[INF];
int size, goal;

int solve()
{
    std::fill(cache+1, cache+INF, INF);

    std::sort(values, values+size);
    int *last = std::unique(values, values+size);
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
    std::cin >> size >> goal;
    for (int i = 0; i < size; ++i)
        std::cin >> values[i];

    int ans = solve();
    std::cout << ans << std::endl;

    return 0;
}
