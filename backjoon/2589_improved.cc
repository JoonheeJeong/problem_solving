#include <iostream>
#include <queue>
#include <cstring> // memcpy
#include <algorithm> // max

struct Crd {
    int y, x;
    Crd(int y, int x) : y(y), x(x) {}
};

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
 
bool map[50][50];
int r, c;

int find_dist(int y_init, int x_init)
{
    bool chk[50][50];
    std::memcpy(chk, map, sizeof(map));
    chk[y_init][x_init] = false;

    std::queue<Crd> q;
    q.push({y_init, x_init});
    int dist = -1;
    while (!q.empty()) {
        dist++;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Crd &crd = q.front();
            int y_pop = crd.y;
            int x_pop = crd.x;
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int y = y_pop + dy[d];
                int x = x_pop + dx[d];
                if (y < 0 || y >= r || x < 0 || x >= c) continue;
                if (!chk[y][x]) continue;
                chk[y][x] = false;
                q.push({y, x});
            }
        }
    }
    return dist;
}

int find_treasure()
{
    int ret = 0;
    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x) {
            if (!map[y][x]) continue;
            /////////// Hidden pruning !!! //////////
            if (map[y-1][x] && map[y+1][x]) continue;
            if (map[y][x-1] && map[y][x+1]) continue;
            /////////////////////////////////////////
            ret = std::max(ret, find_dist(y, x));
        }
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> r >> c;
    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x) {
            char ch;
            std::cin >> ch;
            if (ch == 'L')
                map[y][x] = true;
        }
    }

    std::cout << find_treasure() << std::endl;
    return 0;
}
