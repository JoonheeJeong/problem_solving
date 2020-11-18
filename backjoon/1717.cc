#include <iostream>
#include <vector>

using namespace std;

struct Disjoint_set {
    Disjoint_set(int n): v(n+1, -1) {}
    void solve(int mode, int a, int b);
private:
    int find(int a);
    void merge(int a, int b);
    vector<int> v;
};

int Disjoint_set::find(int a)
{
    if (v[a] == -1) return a;
    else return v[a] = find(v[a]);
}

void Disjoint_set::merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
        v[b] = a;
}

void Disjoint_set::solve(int mode, int a, int b)
{
    if (mode == 0)
        merge(a, b);
    else {
        if (find(a) == find(b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Disjoint_set disjoint_set(n);
    while (m--) {
        int mode, a, b;
        cin >> mode >> a >> b;
        disjoint_set.solve(mode, a, b);
    }
}
