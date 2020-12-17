#include <iostream>
#include <queue>

struct Crd {
    int y, x;
    Crd(int y, int x) : y(y), x(x) {}
};

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

char map[51][51];
bool visited[51][51];
int r, c;

inline bool out_of_range(int y, int x)
{
    if (y < 0 || y >= r || x < 0 || x >= c) return true;
    return false;
}

void init_visited()
{
    for (auto &row : visited)
        for (auto &e : row)
            e = false;
}

int find_dist(int y, int x)
{
    std::queue<Crd> q;
    q.push(Crd(y,x));
    visited[y][x] = true;
    int dist = -1;
    do {
        int size = q.size();
        if (size == 0) 
            break;
        dist++;
        for (int i = 0; i < size; ++i) {
            Crd &crd = q.front();
            int curr_y = crd.y;
            int curr_x = crd.x;
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int next_y = curr_y + dy[d];
                int next_x = curr_x + dx[d];
                if (out_of_range(next_y, next_x)) continue;
                if (map[next_y][next_x] == 'W') continue;
                if (visited[next_y][next_x]) continue;
                visited[next_y][next_x] = true;
                q.push(Crd(next_y, next_x));
            }
        }
    } while (true);
    return dist;
}

int find_treasure()
{
    int max = 0;
    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x) {
            if (map[y][x] == 'W') continue;
            init_visited();
            int temp = find_dist(y, x);
            if (max < temp)
                max = temp;
        }
    }
    return max;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> r >> c;
    for (int y = 0; y < r; ++y)
        for (int x = 0; x < c; ++x)
            std::cin >> map[y][x];

    std::cout << find_treasure() << std::endl;
    return 0;
}
