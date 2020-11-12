#include <iostream>
#include <vector>
#include <deque>
#include <utility>

struct Position {
    int r, c;
    Position() {};
    Position(int r, int c) : r(r), c(c) {}
};

bool operator==(const Position &lhs, const Position &rhs)
{
    return (lhs.r == rhs.r && lhs.c == rhs.c);
}

bool operator!=(const Position &lhs, const Position &rhs)
{
    return !(lhs == rhs);
}

bool operator>(const Position &lhs, const Position &rhs)
{
    if (lhs.r < rhs.r)
        return true;
    else if (lhs.r > rhs.r)
        return false;
    else if (lhs.c < rhs.c)
        return true;
    else
        return false;
}

static const Position npos(-1, -1);

struct Small_shark {
    const int dr[4] = { -1,  0, 0, 1 };
    const int dc[4] = {  0, -1, 1, 0 };

    Small_shark(int n, std::istream &is);
    int solve();
private:
    Position find_eatable(const int &size);
    inline bool out_of_range(const int &r, const int &c)
    {
        if (r < 0 or r >= n
         or c < 0 or c >= n)
            return true;
        else
            return false;
    }
    int n;
    std::vector<std::vector<int>> area;
    Position current_position;
    std::deque<Position> buf; 
    std::vector<std::vector<bool>> visited;
    int move_count = 0;
};

Small_shark::Small_shark(int n, std::istream &is)
    : n(n), area(n, std::vector<int>(n)), visited(n, std::vector<bool>(n))
{
    int i = 0;
    for (auto &row : area) {
        int j = 0;
        for (auto &cell : row) {
            is >> cell;
            if (cell == 9) {
                current_position.r = i;
                current_position.c = j;
            }
            j++;
        }
        i++;
    }
}

int Small_shark::solve()
{
    int size = 2;
    int size_count = 0;
    Position p;
    while ((p = std::move(find_eatable(size))) != npos) {
        area[p.r][p.c] = 9;
        area[current_position.r][current_position.c] = 0;
        current_position = std::move(p);
        size_count++;
        if (size_count == size) {
            size_count = 0;
            size++;
        }
    }
    return move_count;
}

Position Small_shark::find_eatable(const int &size)
{
    buf.push_back(current_position);
    visited[current_position.r][current_position.c] = true;

    int temp_move = 0;
    int buf_size = 1;
    Position ret = npos;
    do {
        temp_move++;
        while (buf_size--) {
            Position &p = buf.front();
            for (int d = 0; d < 4; ++d) {
                int r = p.r + dr[d];
                int c = p.c + dc[d];
                if (out_of_range(r, c)) continue;
                if (visited[r][c]) continue;
                if (area[r][c] > size) continue;
                else if (area[r][c] == 0 || area[r][c] == size) {
                    buf.push_back(Position(r,c));
                    visited[r][c] = true;
                }
                else {
                    Position temp_ret = Position(r,c);
                    if (ret == npos)
                        ret = temp_ret;
                    else if (temp_ret > ret)
                        ret = temp_ret;
                }
            }
            buf.pop_front();
        }
    } while ( ret == npos && (buf_size = buf.size()) != 0);
    if (ret != npos) {
        for (auto &row : visited)
            std::fill(row.begin(), row.end(), false);
        buf.clear();
        move_count += temp_move;
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::istream &is = std::cin;
    is >> n;
    Small_shark small_shark(n, is);
    std::cout << small_shark.solve() << std::endl;
    return 0;
}
