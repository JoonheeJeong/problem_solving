#include <iostream>
#include <deque>

const int di[] { -1, 0, 1, 0 };
const int dj[] { 0, 1, 0, -1 };
const char water = '*';
const char hh = 'S';
const char goal = 'D';

char map[50][50];
int m, n;
struct pos {
    int i;
    int j;
    pos(int i, int j) : i(i), j(j) {}
};
std::deque<pos> q_water;
std::deque<pos> q_hh;

inline bool out_of_range(int i, int j)
{
    if (i < 0 || j < 0 || i >= m || j >= n) return true;
    else                                    return false;
}

bool move(pos &p, char src)
{
    int i, j;
    for (int d = 0; d < 4; ++d) {
        i = p.i + di[d];
        j = p.j + dj[d];
        if (out_of_range(i, j)) continue;
        if (src == hh && map[i][j] == goal) return true;
        if (map[i][j] != '.') continue;
        map[i][j] = src;
        if (src == hh) 
            q_hh.push_back(pos(i,j));
        else
            q_water.push_back(pos(i,j));
    }
    return false;
}

void solve()
{
    int count = 0;
    while (!q_hh.empty()) {
        count++;
        int size = q_water.size();
        for (int i = 0; i < size; ++i) {
            pos &p = q_water.front();
            q_water.pop_front();
            move(p, water); 
        }
        size = q_hh.size();
        for (int i = 0; i < size; ++i) {
            pos &p = q_hh.front();
            q_hh.pop_front();
            bool goal_in = move(p, hh);
            if(goal_in) {
                std::cout << count << std::endl;
                return;
            }
        }
    }
    std::cout << "KAKTUS" << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> m >> n;
    char c;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> c;
            map[i][j] = c;
            if (c == water)
                q_water.push_back(pos(i,j));
            else if (c == hh)
                q_hh.push_back(pos(i,j));
        }
    }

    solve();
    return 0;
}
