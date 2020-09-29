#include <iostream>
#include <vector>
#include <cmath> // pow

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}

    inline static int dist_square(const Point &a, const Point &b);
};

struct Circle {
    Point center;
    int radius;

    Circle(int x, int y, int r) : center(x, y), radius(r) {}
};

int Point::dist_square(const Point &a, const Point &b)
{
    return std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2);
}

int count_outer_circles(const Point &src, const Point &dst, std::vector<Circle> &cs)
{
    int count = 0;
    for (const Circle &c : cs) {
        int r_square = std::pow(c.radius, 2);
        bool s = Point::dist_square(src, c.center) < r_square;
        bool d = Point::dist_square(dst, c.center) < r_square;
		if (s ^ d) ++count;
    }
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t, n, x, y, r;

    std::cin >> t;
    while (--t >= 0) {
        std::cin >> x >> y;
        Point src(x, y);
        std::cin >> x >> y;
        Point dst(x, y);
        std::cin >> n;
        std::vector<Circle> cs;
		for (int i = 0; i < n; ++i) {
			std::cin >> x >> y >> r;
			cs.push_back(Circle(x, y, r));
		}
		std::cout << count_outer_circles(src, dst, cs) << "\n";
	}

	std::cout << std::flush;
	return 0;
}
