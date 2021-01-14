#include <iostream>

using namespace std;

char output[399][398];
int n;

void f(int k, int bg)
{
    int ed = bg + 4*k-3;
    for (int i = bg; i < ed; ++i) { 
        output[bg][i] = '*';
        output[i+1][bg] = '*';
        output[ed+1][i] = '*';
        output[i+2][ed-1] = '*';
    }
    if (k > 1) {
        output[bg+2][ed-2] = '*';
        f(k-1, bg+2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    if (n == 1) {
        cout << "*\n";
        return 0;
    }

    int row = 4*n-1;
    for (int i = 0; i < row; ++i)
        fill(output[i], output[i]+row-2, ' ');

    f(n, 0);
    output[1][1] = '\0';

    for (int i = 0; i < row; ++i)
        cout << output[i] << '\n';
    return 0;
}
