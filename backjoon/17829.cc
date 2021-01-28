#include <iostream>
#include <algorithm>

using namespace std;

int board[1024][1024];

inline int second_largest(int arr[4])
{
    sort(arr, arr+4);
    return arr[2];
}

int solve(int r0, int c0, int n)
{
    if (n == 2) {
        int arr[4] { board[r0][c0],   board[r0][c0+1], 
                     board[r0+1][c0], board[r0+1][c0+1] };
        return second_largest(arr);
    }
    int mid = n/2;
    int arr[4] { solve(r0, c0, mid),     solve(r0, c0+mid, mid),
                 solve(r0+mid, c0, mid), solve(r0+mid, c0+mid, mid) };
    return second_largest(arr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
            cin >> board[i][j];

    cout << solve(0, 0, N) << endl;
    return 0;
}
