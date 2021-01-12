#include <iostream>
#include <algorithm> // fill

using namespace std;

constexpr int size(int k) { return 4*k-3; }
constexpr int MAX_SIZE = size(100);

char output[MAX_SIZE][MAX_SIZE];
int n;

void f(int k, int bg)
{
    if (k <= 0) return;

    int ed = bg + size(k);
    for (int i = bg; i < ed; ++i) {
        output[bg][i] = '*';
        output[ed-1][i] = '*';
        output[i][bg] = '*';
        output[i][ed-1] = '*';
    }

    f(k-1, bg+2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int ed = size(n);
    for (int i = 0; i < ed; ++i)
        fill(output[i], output[i]+ed, ' ');
    f(n, 0);

    for (int i = 0; i < ed; ++i) {
        for (int j = 0; j < ed; ++j)
            cout << output[i][j];
        cout << '\n';
    }
    return 0;
}

