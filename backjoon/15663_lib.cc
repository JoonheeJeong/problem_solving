#include <iostream>
#include <vector>
#include <algorithm> // sort, reverse, next_permutation

void n_and_m(int n, int m, std::vector<int> &input)
{
    auto first = input.begin();
    auto limit = first + m;
    auto end = input.end();
    std::sort(first, end);
    do {
        for (auto it = first; it < limit; ++it)
            std::cout << *it << ' ';
        std::cout << '\n';
        std::reverse(limit, end);
    } while (next_permutation(first, end)); 
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::istream &is = std::cin;

    int n, m;
    std::vector<int> input;
    is >> n >> m;
    for (int temp; is >> temp; )
        input.push_back(temp);

    n_and_m(n, m, input);
    return 0;
}
