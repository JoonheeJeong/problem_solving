#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

struct Install_routers {
    Install_routers(int n_house, int n_router, istream &is);
    int solve();
private:
    int n_house, n_router;
    vector<int> locations;
};

Install_routers::Install_routers(int n_house, int n_router, istream &is = cin)
    : n_house(n_house), n_router(n_router), locations(n_house)
{
    for (int i = 0; i < n_house; ++i)
        is >> locations[i];
    sort(locations.begin(), locations.end());
}

int Install_routers::solve()
{
    int hi = locations.back() - locations.front();
    if (n_router == 2)
        return hi;
    int lo = 2;
    int res = 1;
    while (lo <= hi) {
        // dist < lo : installable
        // dist > hi : not installable
        int dist = (lo + hi) / 2;
        int cnt = 1;
        int src = locations.front();
        for (int i = 1; i < n_house; ++i) {
           if (locations[i] - src >= dist) {
               cnt++;
               src = locations[i];
           }
        }

        if (cnt >= n_router) {
           res = dist;
           lo = dist + 1;
        } else {
           hi = dist - 1;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    istream &is = cin;
    int n_house, n_router;
    is >> n_house >> n_router;
    Install_routers install_routers(n_house, n_router);
    cout << install_routers.solve() << endl;
    return 0;
}
