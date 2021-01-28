#include <iostream>

using namespace std;

const int MAX = 1 << 7;
int board[MAX][MAX];
int ans[2];

int solve(int r0, int c0, int n)
{
    if (n == 1) {
        int ret = board[r0][c0];
        ans[ret]++;
        return ret; 
    }

    int next = n/2;
    int quater1 = solve(r0, c0+next, next);
    int quater2 = solve(r0, c0, next);
    int quater3 = solve(r0+next, c0, next);
    int quater4 = solve(r0+next, c0+next, next);

    if (quater1 == quater2 and quater2 == quater3 and quater3 == quater4) {
        ans[quater1] -= 3;
        return quater1;
    } else {
        return -1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    solve(0, 0, N);
    cout << ans[0] << '\n' << ans[1] << endl;
    return 0;
}
