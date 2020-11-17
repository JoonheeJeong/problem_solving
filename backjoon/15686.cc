// 1. find all distances from every chicken to every house
// 2. pick M out of K
// 3. for each house, find minimum chicken distance out of the picked M
// 4. add all those minimums
// 5. find a specific combination of M out of K for the result of process 4 to be minimum

#include <iostream>
#include <vector>
#include <algorithm> // abs

using namespace std;

struct Position {
    int r, c;
    Position(int r, int c) : r(r), c(c) {}
};

struct House {
    Position p;
    vector<int> distances;
    House(Position p) : p(p) {}
};

struct Chicken_delivery {
    Chicken_delivery(int n, int m, istream &is);
    int solve();
private:
    void solve(int chicken_i, int to_pick, vector<int> &picked, int &min);
    int n;
    int m;
    vector<House> houses;
    vector<Position> chickens;
};

Chicken_delivery::Chicken_delivery(int n, int m, istream &is = cin)
    : n(n), m(m)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int temp;
            is >> temp;
            if (temp == 1) {
                houses.push_back(House(Position(i, j)));
            } else if (temp == 2) {
                chickens.push_back(Position(i, j));
            }
        }
    }
    // save all the chicken distances
    for (auto &c : chickens) {
        for (auto &h : houses) {
            int chicken_distance = abs(h.p.r - c.r) + abs(h.p.c - c.c);
            h.distances.push_back(chicken_distance);
        }
    }
}

// pick M chiken and save those index
// find the minimum distance from each house to M chickens, and add it all
// find the minimum value from the result of the above process for every case
int Chicken_delivery::solve()
{

    int min = houses.size() * 100;
    vector<int> picked;
    solve(0, m, picked, min);
    return min;
}

// chicken_i: a chicken index
// to_pick  : the number left to pick
// picked   : picked indices of chickens
// min      : the chicken distance of the city
void Chicken_delivery::solve(int chicken_i, 
                             int to_pick, 
                             vector<int> &picked, 
                             int &min)
{
    // update min
    if (to_pick == 0) {
        int sum = 0;
        for (auto &h : houses) {
            int h_min = 100;
            for (auto &i : picked) {
                if (h.distances[i] < h_min)
                    h_min = h.distances[i];
            }
            sum += h_min;
        }
        if (sum < min)
            min = sum;
        return;
    }

    // end recursive tree
    if (chicken_i == int(chickens.size())) return;

    // pruning
    if (int(chickens.size()) - chicken_i < to_pick) return;

    // do pick
    picked.push_back(chicken_i);
    solve(chicken_i+1, to_pick-1, picked, min);
    picked.pop_back();

    // do not pick
    solve(chicken_i+1, to_pick, picked, min);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    istream &is = cin;
    int n, m;
    is >> n >> m;
    Chicken_delivery chicken_delivery(n, m);
    cout << chicken_delivery.solve() << endl;
    return 0;
}
