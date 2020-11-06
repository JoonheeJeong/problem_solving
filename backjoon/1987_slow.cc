// slow: 516ms
#include <iostream>
#include <vector>
#include <string>
#include <utility>

const int dr[] = { 0, 1, 0, -1 };
const int dc[] = { 1, 0, -1, 0 };
const int offset = -'A';

struct Alphabet_board {
    int r, c;
    std::vector<std::string> board;
    bool visited[20][20] {};
    bool chk[26] {};
    int size = 1;
    Alphabet_board(int r, int c, std::istream &is);
    inline bool out_of_range(int i, int j)
    {
        if (i < 0 || i >= r || j < 0 || j >= c) return true;
        else                                    return false;
    }
    int solve(int i, int j);
};

Alphabet_board::Alphabet_board(int r, int c, std::istream &is)
    :r(r), c(c)
{
    std::string s;
    for (int i = 0; i < r; ++i) {
        is >> s;
        board.push_back(std::move(s));
    }
    visited[0][0] = true;
    chk[board[0][0]+offset] = true;
}

int Alphabet_board::solve(int i, int j)
{
    int ret = size;
    for (int d = 0; d < 4; ++d) {
        int next_i = i + dr[d];
        int next_j = j + dc[d];
        if (out_of_range(next_i, next_j)) continue;
        bool &is_visited = visited[next_i][next_j];
        if (is_visited) continue;
        bool &does_exist = chk[board[next_i][next_j]+offset];
        if (does_exist) continue;
        is_visited = true;
        does_exist = true;
        size++;
        int count = solve(next_i, next_j);
        if (count > ret)
            ret = count;
        size--;
        does_exist = false; 
        is_visited = false;
    }
    return ret;
}

int main()
{
    int r, c;
    std::istream &is = std::cin;

    is >> r >> c;
    Alphabet_board ab(r, c, is);
    std::cout << ab.solve(0, 0) << std::endl;
    return 0;
}

