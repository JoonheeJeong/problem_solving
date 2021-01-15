#include <iostream>

using namespace std;

int offset[12];
char board[3072][6144];

void f(int k, int r, int c)
{
    if (k == 0) {
        board[r][c] = board[r+1][c-1] = board[r+1][c+1] = '*';
        for (int j = c-2; j < c+3; ++j)
            board[r+2][j] = '*';
        return;
    }
    k--;
    int temp = offset[k];
    f(k, r, c);
    f(k, r+temp, c-temp);
    f(k, r+temp, c+temp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int bg;
    for (int t = 3, i = 0; ; ++i) {
        offset[i] = t;
        if (t > n) {
            bg = i-1;
            break;
        }
        t *= 2;
    }

    for (int i = 0; i < offset[bg]; ++i)
        fill(board[i], board[i]+offset[bg+1]-1, ' ');

    f(bg, 0, offset[bg]-1);

    for (int i = 0; i < offset[bg]; ++i)
        cout << board[i] << '\n';

    return 0;
}
