// slow: 780ms
#include <iostream>
#include <vector>

std::istream &is = std::cin;
std::ostream &os = std::cout;

struct Node;

struct Edge {
    Node *parent;
    Node *child;
    int weight;
    Edge(Node *parent, Node *child, int weight) 
        : parent(parent), child(child), weight(weight) {}
    Node *target(Node *node) {
        if (node == parent)
            return child;
        else if (node == child)
            return parent;
        else
            return nullptr;
    }
};

struct Node {
    int id;
    // parent: edges[0]->parent
    // children: edges[1:]->child
    std::vector<Edge*> edges;
    Node(int id) : id(id) {}
};

struct Tree {
    Tree (int n);
    int find_longest_tree_diameter();
private:
    void get_all_leaves(Node *local_root, std::vector<Node*> &leaves);
    void check_global_visited(Node *local_root); // meaningless ... no benefit
    int get_local_max_distance(Node *local_root);

    int n;
    std::vector<Node*> nodes;
    std::vector<bool> local_visited;
    std::vector<bool> global_visited;
};

Tree::Tree(int n)
    : n(n), nodes(n+1, nullptr), local_visited(n+1), global_visited(n+1)
{
    int p, c, weight;
    for (int i = 1; i < n; ++i) {
        is >> p >> c >> weight;
        Node *parent = nodes[p];
        if (parent == nullptr) {
            parent = new Node(p);
            nodes[p] = parent;
        }
        Node *child = nodes[c];
        if (child == nullptr) {
            child = new Node(c);
            nodes[c] = child;
        }
        Edge *edge = new Edge(parent, child, weight);
        parent->edges.push_back(edge); 
        child->edges.push_back(edge);
    }
}

void Tree::get_all_leaves(Node *local_root, std::vector<Node*> &leaves)
{
    local_visited[local_root->id] = true;
    auto &edges = local_root->edges;
    if (edges.size() == 1) { 
        leaves.push_back(local_root);
        if (edges[0]->child == local_root) return;
        else ; // case: root has only one child 
    }

    for (auto &edge : edges) {
        if (local_root != edge->parent) continue; 
        Node *next = edge->child;
        if (local_visited[next->id]) continue;
        get_all_leaves(next, leaves);
    }
}

int Tree::get_local_max_distance(Node *local_root)
{
    local_visited[local_root->id] = true;

    int max = 0;
    for (auto &edge : local_root->edges) {
        Node *next = edge->target(local_root);
        if (local_visited[next->id]) continue;
        int temp_max = edge->weight + get_local_max_distance(next);
        if (temp_max > max)
            max = temp_max;
    }
    return max;
}

void Tree::check_global_visited(Node *local_root)
{
    int unvisited_count = 0;
    Node *next = nullptr;
    for (auto &edge : local_root->edges) {
        next = edge->target(local_root);
        if (!global_visited[next->id]) {
            unvisited_count++;
            if (unvisited_count == 2)
                break;
        }
    }
    if (unvisited_count != 1)
        return;
    else {
        global_visited[local_root->id] = true;
        check_global_visited(next);
    }
}

int Tree::find_longest_tree_diameter()
{
    if (n == 1) 
        return 0;
    Node *root = nodes[1];

    // 1: get all leaves through dfs
    std::vector<Node*> leaves;
    get_all_leaves(root, leaves);

    int max = 0;
    for (auto &leaf : leaves) {
    // 2: get distances for all pairs of leaves
        local_visited = global_visited;
        int temp_max = get_local_max_distance(leaf);
        if (temp_max > max)
            max = temp_max;
    // 2+: check visited leaf to avoid duplicated tasks
        check_global_visited(leaf);
    }
    // 3: return maximum distance
    return max;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    is >> n;

    Tree tree(n);
    os << tree.find_longest_tree_diameter() << std::endl;
    return 0;
}
