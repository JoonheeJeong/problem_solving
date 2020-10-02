#include <iostream>
#include <string>
#include <utility> // swap

int p[101];
int n, a, b;

struct Root_relation {
    int root;
    std::string path;
    Root_relation(int v)
    {
        path = char(v + '0');
        while (p[v] != 0) {
            v = p[v];
            path += char(v + '0'); 
        }
        root = v;
    }
};

int chonsu(const Root_relation &lhs, const Root_relation &rhs) noexcept
{
    std::string ls = lhs.path;
    std::string rs = rhs.path;
    int llen = ls.size();
    int rlen = rs.size();
    if (llen > rlen) {
        std::swap(ls, rs);
        std::swap(llen, rlen);
    }

    // k < lo, rs[k] is not a common parent
    // k > hi, rs[k] is a common parent
    int lo = 0;
    int hi = rs.size() - 2;
    int mid;
    while (hi >= lo) {
        mid = (lo + hi) / 2;
        const char &c = rs[mid];
        int pos = ls.find(c); 
        if (pos != -1)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    // lo is a distance from rv to the nearest common parent
    return lo + ls.find(rs[lo]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> a >> b;

    if (a == b) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int m, u, v;
    std::cin >> m;
    while (m--) {
        std::cin >> u >> v;
        p[v] = u;
    }

    Root_relation rra(a);
    Root_relation rrb(b);
    int res = (rra.root != rrb.root) ? -1 : chonsu(rra, rrb);
    std::cout << res << std::endl;
    return 0;
}
