#include <iostream>
#include <vector>

int r, c, t;
std::vector<std::vector<int>> pixels;

int avg_brightness(int r1, int c1, int r2, int c2)
{
    int cnt = (r2-r1+1)*(c2-c1+1);
    int sum = pixels[r2][c2] - pixels[r2][c1-1] - pixels[r1-1][c2] + pixels[r1-1][c1-1];
    return sum / cnt;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::istream &is = std::cin;
    is >> r >> c >> t;

    pixels.push_back(std::vector<int>(c+1));
    int temp;
    for (int i = 1; i <= r; ++i) {
        int sum = 0;
        std::vector<int> row(1);
        for (int j = 1; j <= c; ++j) {
            is >> temp;
            sum += temp;
            row.push_back(sum + pixels[i-1][j]);
        }
        pixels.push_back(row);
    }

    int r1, c1, r2, c2;
    for (int i = 0; i < t; ++i) {
        is >> r1 >> c1 >> r2 >> c2;
        std::cout << avg_brightness(r1, c1, r2, c2) << '\n';
    }
    return 0;
}
