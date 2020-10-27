#include <iostream>
#include <algorithm>

enum event { UNION = 1, WAR };

int n, m;
int troops[100001], root[100001];

int find_root(int v)
{
    if (root[v] == 0) return v;
    return root[v] = find_root(root[v]);
}

void uni(int &lhs, int &rhs)
{
    int rhs_root = find_root(rhs);
    int lhs_root = find_root(lhs);
    root[rhs_root] = lhs_root;
    troops[lhs_root] += troops[rhs_root];
    troops[rhs_root] = 0;
}

void war(int &lhs, int &rhs)
{
    int big_root = find_root(rhs);
    int les_root = find_root(lhs);

    if (troops[les_root] > troops[big_root]){
        int temp = big_root;
        big_root = les_root;
        les_root = temp;
    }

    troops[big_root] -= troops[les_root];
    troops[les_root] = 0;
    root[les_root] = big_root;
}

void print_result()
{
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (troops[i] != 0 && root[i] == 0)
            count++;
    }
    std::cout << count << "\n";

    int *beg = troops + 1;
    int *end = beg + n;
    std::sort(beg, end);
    std::for_each(end - count, end, 
            [](const int& t) { std::cout << t << " "; });
    std::cout << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
        std::cin >> troops[i];

    event e;
    int temp, u, v;
    for (int i = 0; i < m; ++i) {
        std::cin >> temp >> u >> v;
        e = static_cast<event>(temp);
        if (e == UNION) uni(u, v);
        else            war(u, v);
    }

    print_result();
    return 0;
}
