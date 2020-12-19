#include <iostream>
#include <vector>
#include <algorithm> // sort, unique

int n, m, len;
std::vector<int> input, remains, output;

void n_and_m(int cnt)
{
    if (cnt == m) {
        for (auto &e : output)
            std::cout << e << " ";
        std::cout << "\n";
        return;
    }

    for (int i = 0; i < len; ++i) {
        if (remains[i] != 0) {
            remains[i]--;
            output.push_back(input[i]);
            n_and_m(cnt+1);
            output.pop_back();
            remains[i]++;
        }
    }
}

void set_remains()
{
    auto i = input.begin();
    auto j = i;
    auto end = input.end();
    while (++j != end) {
        if (*i != *j) {
            remains.push_back(j-i);
            i = j;
        }
    }
    remains.push_back(j-i);
    len = remains.size();
}

void n_and_m()
{
    auto beg = input.begin();
    auto end = input.end();
    std::sort(beg, end);
    set_remains();
    auto last = std::unique(beg, end);
    input.erase(last, end);
    n_and_m(0);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::istream &is = std::cin;
    is >> n >> m;

    for (int temp; is >> temp; )
        input.push_back(temp);

    n_and_m();
    return 0;
}
