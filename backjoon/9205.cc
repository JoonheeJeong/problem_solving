#include <iostream>
#include <vector>
#include <utility>

struct crd { int x, y; crd(int x, int y) : x(x), y(y){} };

inline int dist(const crd &lhs, const crd &rhs)
{
    int diff_x = rhs.x - lhs.x;
    if (diff_x < 0) diff_x = -diff_x;
    int diff_y = rhs.y - lhs.y;
    if (diff_y < 0) diff_y = -diff_y;
    return diff_x + diff_y;
}

std::vector<crd> crds;
bool adj[102][102];
int tc, n;

void reset()
{
    for (int i = 0; i < n+2; i++)
        for (int j = i+1; j < n+2; j++)
            adj[i][j] = adj[j][i] = false;

    crds.clear();
}

void init()
{
    for (int i = 0; i < n+2; i++)
        for (int j = i+1; j < n+2; j++)
            if (dist(crds[i], crds[j]) <= 1000)
                adj[i][j] = adj[j][i] = true;
}

bool warshall()
{
    init();

    for (int jc = 0; jc < n+2; jc++) {
        for (int src = 0; src < n+2; src++) {
            if (jc == src) continue;
            for (int dst = 0; dst < n+2; dst++) {
                if (dst == src || dst == jc) continue;
                if (adj[src][jc] && adj[jc][dst])
                    adj[src][dst] = true;
            }
        }
    }

    return adj[0][n+1];
}

int main()
{
    std::cin >> tc;

    while (tc--) {
        int x, y;
        std::cin >> n;
        for (int i = -2; i < n; ++i) {
            std::cin >> x >> y;
            crd c(x,y);
            crds.push_back(std::move(c));
        }

        std::cout << (warshall() ? "happy\n" : "sad\n");

        reset();
    }
    std::cout << std::flush;

    return 0;
}
