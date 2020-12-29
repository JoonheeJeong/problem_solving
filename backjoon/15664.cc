#include <iostream>
#include <vector>
#include <algorithm> // find, sort, min

struct option {
    int id;
    int size;
    option(int id) : id(id), size(1) {}
};

bool operator<(const option &lhs, const option &rhs)
{
    return lhs.id < rhs.id;
}

bool operator==(const option &lhs, const option &rhs)
{
    return lhs.id == rhs.id;
}

int n, m;
std::vector<option> input;
std::vector<int> output;

void n_and_m(int pos, int rem)
{
    if (rem == 0) {
        for (auto &e : output)
            std::cout << e << ' ';
        std::cout << '\n';
        return;
    }
    if (pos == (int) input.size()) return;

    option &opt = input[pos];
    int &id = opt.id;
    for (int i = std::min(opt.size, rem); i >= 0; i--) {
        for (int j = 0; j < i; j++)
            output.push_back(id);
        n_and_m(pos+1, rem-i);
        for (int j = 0; j < i; j++)
            output.pop_back();
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::istream &is = std::cin;

    is >> n >> m;

    for (int temp; is >> temp; ) {
        auto it = std::find(input.begin(), input.end(), temp);
        if (it != input.end())
            it->size++;
        else
            input.push_back({temp});
    }

    std::sort(input.begin(), input.end());
    n_and_m(0, m);

    return 0;
}
