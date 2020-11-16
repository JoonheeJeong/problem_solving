// slow: 4232ms
#include <iostream>
#include <vector>
#include <algorithm> // abs

using namespace std;

struct N_queen {
    N_queen(int n, istream &is = cin) 
        : n(n), cols(n) {}
    int solve(int r);
private:
    bool set(int r, int c);
    int n;
    vector<int> cols;
};

int N_queen::solve(int r)
{
    if (r == n) return 1;

    int ret = 0;
    for (int c = 0; c < n; ++c) {
        if (set(r, c))
            ret += solve(r+1);
    }
    return ret;
}

bool N_queen::set(int r, int c)
{

    cols[r] = c;

    for (int i = 0; i < r; ++i) {
        int ic = cols[i];
        if (ic == c || r-i == abs(c-ic)) return false;
    }
    return true;
}

int main()
{
    int n;
    istream &is = cin;
    is >> n;
    N_queen nq(n);
    cout << nq.solve(0) << endl;
    return 0;
}
