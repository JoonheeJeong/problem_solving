#include <iostream>

int n, arr[200], cache[200];

int main()
{
    std::cin >> n;
    int t;

    int max = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        arr[i] = t;
        int temp = 0;
        for (int j = i-1; j >= 0; --j)
            if (arr[j] < t && temp < cache[j])
                temp = cache[j];
        temp++;
        cache[i] = temp;
        if (temp > max)
            max = temp;
    }

    std::cout << n - max << std::endl;
    return 0;
}
