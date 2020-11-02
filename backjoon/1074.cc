#include <iostream>

int two_squares[15];

int z_search(int n, int r, int c)
{
    int tn = two_squares[n-1];
    int k = (r / tn) * 2 + (c / tn);
    if (n == 1) return k;
    return tn*tn*k + z_search(n-1, r % tn, c % tn);
}

int main()
{
    int n, r, c;
    std::cin >> n >> r >> c;

    int temp = 1;
    for (int i = 0; i < n; ++i) {
        two_squares[i] = temp;
        temp *= 2;
    }

    std::cout << z_search(n, r, c) << std::endl;
    return 0;
}
