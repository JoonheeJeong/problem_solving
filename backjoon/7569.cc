#include <iostream>
#include <vector>
#include <deque>
#include <utility>

struct Position {
    int h, r, c;
    Position(int h, int r, int c) : h(h), r(r), c(c) {}
};

struct Tomato {
    using Row = std::vector<int>;
    using Box = std::vector<Row>;
    const int dh[6] {  0, 0, 0,  0, 1, -1 };
    const int dr[6] { -1, 0, 1,  0, 0,  0 };
    const int dc[6] {  0, 1, 0, -1, 0,  0 };

    Tomato(int h, int r, int c, std::istream &is);
    int solve();
private:
    inline bool out_of_range(const int &nh, const int &nr, const int &nc) 
    {
        if (nh < 0 or nh >= h
         or nr < 0 or nr >= r
         or nc < 0 or nc >= c)
            return true;
        else
            return false;
    }

    int h, r, c;
    std::vector<Box> storage;
};

Tomato::Tomato(int h, int r, int c, std::istream &is)
    : h(h), r(r), c(c), storage(h, Box(r, Row(c)))
{

    for (auto &box : storage)
        for (auto &row : box)
            for (auto &cell : row)
                is >> cell;
}

int Tomato::solve()
{
    std::deque<Position> buf;
    for (int i = 0; i < h; ++i) {
        const auto &box = storage[i];
        for (int j = 0; j < r; ++j) {
            const auto &row = box[j];
            for (int k = 0; k < c; ++k) {
                if (row[k] == 1) {
                    buf.push_back(std::move(Position(i, j, k)));
                }
            }
        }
    }

    int day = 0;
    int buf_size = buf.size();
    do {
        for (int i = 0; i < buf_size; ++i) {
            Position p = std::move(buf.front());
            for (int d = 0; d < 6; d++) {
                int nh = p.h + dh[d];
                int nr = p.r + dr[d];
                int nc = p.c + dc[d];
                if (out_of_range(nh, nr, nc)) continue;
                if (storage[nh][nr][nc] != 0) continue;
                storage[nh][nr][nc] = 1;
                buf.push_back(std::move(Position(nh, nr, nc)));
            }
            buf.pop_front();
        }
        buf_size = buf.size();
        if (buf_size == 0)
            break;
        day++;
    } while (true);

    for (const auto &box : storage)
        for (const auto &row : box)
            for (const auto &cell : row)
                if (cell == 0)
                    return -1;
    return day;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int h, r, c;
    std::istream &is = std::cin;
    is >> c >> r >> h;
    Tomato tomato(h, r, c, is);
    std::cout << tomato.solve() << std::endl;
    return 0;
}
