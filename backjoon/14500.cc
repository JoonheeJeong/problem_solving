#include <iostream>
#include <vector>

using namespace std;

class Tetromino {
    static constexpr int dr[19][4] { 
        {0,0,0,0}, {0,0,0,1},   {0,0,0,1},  {0,1,1,1},  {0,1,1,1}, 
        {0,0,1,1}, {0,0,1,1},   {0,1,1,1},  {0,0,0,1},  {0,0,1,1}, 
        {0,1,2,2}, {0,1,2,2},   {0,0,1,2},  {0,0,1,2}, 
        {0,1,1,2}, {0,1,1,2},   {0,1,1,2},  {0,1,1,2},  {0,1,2,3}
    };
    static constexpr int dc[19][4] {
        {0,1,2,3}, {0,1,2,2},   {0,1,2,0},  {0,0,1, 2}, {0,-2,-1,0},
        {0,1,1,2}, {0,1,-1,0},  {0,-1,0,1}, {0,1,2,1},  {0, 1,0,1},
        {0,0,0,1}, {0,0,0,-1},  {0,1,1,1},  {0,1,0,0},  
        {0,0,1,1}, {0,-1,0,-1}, {0,0,1,0},  {0,-1,0,0}, {0,0,0,0}
    };
    int n, m;
    vector<vector<int>>board;
    int get_max(int r, int c);
    bool out_of_range(int r, int c)
    {
        if (r<0 or r>=n or c<0 or c>=m) return true;
        return false;
    }
public:
    Tetromino(int n, int c);
    int solve();
};

Tetromino::Tetromino(int n, int m) : n(n), m(m), board(n, vector<int>(m)) 
{
    for (auto &row : board)
        for (auto &e : row)
            cin >> e;
}

int Tetromino::get_max(int r, int c)
{
    int max = 0;
    for (int i = 0; i < 19; ++i) {
        int temp = 0;
        int j = 0;
        for (; j < 4; ++j) {
            int nr = r + dr[i][j];
            int nc = c + dc[i][j];
            if (out_of_range(nr, nc)) break;
            temp += board[nr][nc];
        }
        if (j != 4) continue;
        if (max < temp)
            max = temp;
    }
    return max;
}

int Tetromino::solve()
{
    int ret = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int temp_max = get_max(r, c);
            if (ret < temp_max)
                ret = temp_max;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Tetromino tetromino(n, m);

    cout << tetromino.solve() << endl;
    return 0;
}
