#include <iostream>

inline long long square(long long n) { return n*n; }
inline int square(int n) { return n*n; }

int find_square_bottom_num(const int &dist)
{
    if (dist == 1) 
        return 1;

    // lo^2 <= val < hi^2
    int lo = 1;
    int hi = dist;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (mid < 0) mid = -mid; // case) dist=2^31-1
        if (dist < square((long long) mid))
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}

int solve(const int &x, const int &y)
{
    int dist = y-x;
    int bot = find_square_bottom_num(dist);
    int rem = dist - square(bot);
    int alpha = 0;
    for (int i = bot; rem != 0; --i) {
        alpha += rem / i;
        rem %= i;
    }
    return 2*bot-1 + alpha;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t, x, y;
    std::cin >> t;
    while (t--) {
        std::cin >> x >> y;
        std::cout << solve(x, y) << "\n";
    }
    std::cout << std::flush;
    return 0;
}
