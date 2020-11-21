#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue> // priority_queue
#include <functional> // greater

using namespace std;

struct Node {
    int id;
    unordered_set<Node*> predecessors;
    unordered_set<Node*> successors;
    Node(int id) : id(id) {}
};

// correct to compare pointers of node
struct Compare_node_pointers {
    bool operator()(Node* lhs, Node* rhs) { return lhs->id > rhs->id; }
};

// ineffective
// bool operator>(const Node &lhs, const Node &rhs) { return lhs.id > rhs.id; }

// error
// bool operator>(const Node* lhs, const Node* rhs) { return lhs->id > rhs->id; }

class Workbook {
    unordered_map<int, Node*> nodes;
    priority_queue<Node*, vector<Node*>, Compare_node_pointers > no_pred;
public:
    Workbook(int n, int m);
    void solve();
};

Workbook::Workbook(int n, int m)
{
    do
        nodes.insert({n, new Node(n)});
    while (--n);

    while (m--) {
        int p_id, s_id;
        cin >> p_id >> s_id;
        
        Node *pred = nodes.find(p_id)->second;
        Node *suc = nodes.find(s_id)->second;

        pred->successors.insert(suc);
        suc->predecessors.insert(pred);
    }
}

void Workbook::solve()
{
    for (auto &pair : nodes) {
        Node *node = pair.second;
        if (node->predecessors.empty())
            no_pred.push(node);
    }

    while (!no_pred.empty()) {
        Node *node = no_pred.top();
        cout << node->id << " ";
        no_pred.pop();
        for (auto &suc : node->successors) {
            suc->predecessors.erase(node);
            if (suc->predecessors.empty())
                no_pred.push(suc);
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
