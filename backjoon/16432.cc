#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::vector<int> dducks;
std::vector<dducks> v;
dducks picked;
enum cache_state { INIT, POSSIBLE, IMPOSSIBLE };
cache_state cache[1001][10];
int days;

void print()
{
    std::for_each(picked.crbegin(), picked.crend(), 
            [] (const int &e) { std::cout << e << "\n"; });
    std::cout << std::flush;
}

cache_state solve(int day, int prev_dduck_type)
{
    if (day > days) return POSSIBLE;
    
    cache_state &ret = cache[day][prev_dduck_type];
    if (ret != INIT)
        return ret;

    cache_state temp_ret = INIT;
    for (int &e : v[day]) {
       if (e != prev_dduck_type) {
           temp_ret = solve(day+1, e);
           if (temp_ret == POSSIBLE) {
               picked.push_back(e);
               break;
           }
       }
    }
    ret = (temp_ret == INIT) ? IMPOSSIBLE : temp_ret;
    return ret;
}

int main()
{
    std::cin >> days;

    dducks dummy;
    v.push_back(std::move(dummy));

    for (int i = 0; i < days; ++i) {
        int m, t;
        dducks chk;
        std::cin >> m;
        while (m--) {
            std::cin >> t;
            chk.push_back(t);
        }
        v.push_back(std::move(chk));
    }

    cache_state res = solve(1, 0);

    if (res == IMPOSSIBLE)
        std::cout << -1 << std::endl;
    else
        print();
    return 0;
}
