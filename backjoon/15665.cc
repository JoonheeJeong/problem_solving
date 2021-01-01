#include <iostream>
#include <vector>
#include <algorithm> // sort, unique
#include <string>

int n, m, len;
std::vector<int> input;

void solve(int cnt, std::string output)
{
    if (cnt == m) {
        std::cout << output << '\n';
        return;
    }
    
    for (int i = 0; i < len; ++i)
        solve(cnt+1, output + std::to_string(input[i]) + ' ');
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::istream &is = std::cin;
    is >> n >> m;

    for (int temp; n > 0; n--) {
        is >> temp;
        input.push_back(temp);
    }
    std::sort(input.begin(), input.end());
    auto last = std::unique(input.begin(), input.end());
    input.erase(last, input.end());
    len = input.size();

    solve(0, "");
    return 0;
}
