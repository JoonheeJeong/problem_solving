#include <iostream>
#include <string>
#include <vector>

std::vector<char> v;

void solve(std::string &line)
{
    bool res = true;

    for (auto e : line) {
        if (e == '[' || e == '(') {
            v.push_back(e);
            continue;
        }
        
        if (e == ']') {
            if (!v.empty() && v.back() == '[') {
                v.pop_back();
            } else { 
                res = false;
                break;
            }
        }
        else if (e == ')') {
            if (!v.empty() && v.back() == '(') {
                v.pop_back();
            } else {
                res = false;
                break;
            }
        }
    }
    if (!v.empty()) {
        res = false;
        v.clear();
    }
    if (res) std::cout << "yes\n";
    else     std::cout << "no\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.size() == 1 && line.back() == '.')
            break;
        solve(line);
    }
    return 0;
}
