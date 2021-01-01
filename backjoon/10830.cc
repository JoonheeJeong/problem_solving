#include <iostream>
#include <vector>

int n;
long long ex;
using matrix = std::vector<std::vector<int>>;
long long two_squares[41];
std::vector<matrix> mat_squares;

matrix matrix_mul(const matrix& lhs, const matrix& rhs)
{
    matrix mat(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        const std::vector<int> &row = lhs[i];
        for (int j = 0; j < n; ++j) {
            int res = 0;
            for (int k = 0; k < n; ++k) {
                res += row[k] * rhs[k][j];
            }
            mat[i][j] = res % 1000;
        }
    }
    return mat;
}

// 2^t <= ex < 2^(t+1)
// return t
int find_floor(long long ex)
{
    int lo = 0;
    int hi = 40;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (ex < two_squares[mid])
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}


matrix solve(long long ex)
{
    if (ex == 1)
        return mat_squares[0];

    int floor = find_floor(ex);
    if (floor >= (int) mat_squares.size()) {
        auto mat_lower = solve(two_squares[floor-1]);
        auto mat_floor = matrix_mul(mat_lower, mat_lower);
        mat_squares.push_back(mat_floor);
    }
    long long rem = ex - two_squares[floor];
    if (rem > 0)
        return matrix_mul(mat_squares[floor], solve(rem));
    else
        return mat_squares[floor];
}

int main()
{
    std::cin >> n >> ex;
    matrix mat;
    for (int i = 0; i < n; ++i) {
        std::vector<int> row;
        for (int temp, j = 0; j < n; ++j) {
            std::cin >> temp;
            row.push_back(temp % 1000);
        }
        mat.push_back(row);
    }
    mat_squares.push_back(mat);

    // two_squares[t] = 2^t
    long long v = 1;
    for (int t = 0; t <= 40; ++t) {
        two_squares[t] = v;
        v <<= 1;
    }

    mat = solve(ex);
    for (auto &row : mat) {
        for (auto &e : row)
            std::cout << e << ' ';
        std::cout << '\n';
    }
    return 0;
}
