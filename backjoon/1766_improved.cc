#include <iostream>
#include <vector>
#include <queue> // priority_queue
#include <functional> // greater

using namespace std;

class Workbook {
    int n;
    vector<vector<int>> successors;
    vector<int> predecessor_count;
    priority_queue<int, vector<int>, greater<int>> no_pred;
public:
    Workbook(int n, int m);
    void solve();
};

Workbook::Workbook(int n, int m)
    : n(n), successors(n+1), predecessor_count(n+1)
{
    do {
        int p_id, s_id;
        cin >> p_id >> s_id;

        successors[p_id].push_back(s_id);
        predecessor_count[s_id]++;
    } while (--m);
}

void Workbook::solve()
{
    for (int i = 1; i <= n; ++i) {
        if (predecessor_count[i] == 0)
            no_pred.push(i);
    }

    while (!no_pred.empty()) {
        int id = no_pred.top();
        cout << id << " ";
        no_pred.pop();
        for (auto &suc_id : successors[id]) {
            if (--predecessor_count[suc_id] == 0)
                no_pred.push(suc_id);
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Workbook workbook(n, m);
    workbook.solve();
    return 0;
}
