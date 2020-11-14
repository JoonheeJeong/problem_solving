// slow: 132ms
// input gives many connected pairs of vertices, no parent-child relationship
// so first, we have to make a tree from the given graph through dfs or bfs

#include <iostream>
#include <vector>
#include <algorithm> // max

using namespace std;


struct Edge;

struct Node {
    int id;
    Node *parent;
    vector<Edge*> edges;
    Node (int id) : id(id) {}
};

struct Edge {
    Node *target;
    int dist;
    Edge(Node *target, int dist) : target(target), dist(dist) {}
};

struct Graph {
    Graph(int n, istream &is);
    int diameter();
private:
    void dfs(Node *local_root);
    void make_tree(int root_id);
    int height(Node *local_root);

    int longest_pair;
    vector<bool> visited;
    vector<Node*> nodes;
};

Graph::Graph(int n, istream &is = cin)
    : longest_pair(0), visited(n+1), nodes(n+1)
{
    int u, v, d;
    while (n--) {
        is >> u >> v;
        do {
            is >> d;
            Node *source = nodes[u];
            if (source == nullptr) {
                source = (nodes[u] = new Node(u));
            }
            Node *target = nodes[v];
            if (target == nullptr) {
                target = (nodes[v] = new Node(v));
            }
            source->edges.push_back(new Edge(target, d));

            is >> v;
        } while (v != -1);
    }
}

void Graph::dfs(Node *local_root)
{
    visited[local_root->id] = true;
    for (auto &edge : local_root->edges) {
        auto &next = edge->target;;
        if (visited[next->id]) continue;
        next->parent = local_root;
        dfs(next);
    }
}

// to simplify problem, decided Node(root_id) would be a root of a tree to make
void Graph::make_tree(int root_id)
{
    visited[root_id] = true;
    Node *root = nodes[root_id];
    for (auto &edge : root->edges) {
        edge->target->parent = root;
        dfs(edge->target);
    }
}


// return the longest distance from local_root to one of its leaves
int Graph::height(Node *local_root)
{
    vector<int> heights;
    for (auto &edge : local_root->edges) {
        if (edge->target == local_root->parent) continue;
        heights.push_back(edge->dist + height(edge->target));
    }

    if (heights.empty()) 
        return 0;

    int longest_first = heights[0];

    if (heights.size() >= 2) {
        longest_first = 0;
        int longest_second = 0;
        for (auto &h : heights) {
            if (h > longest_first) {
                longest_second = longest_first;
                longest_first = h;
            } else if (h > longest_second) {
                longest_second = h;
            }
        }

        if (longest_pair < longest_first + longest_second)
            longest_pair = longest_first + longest_second;
    }

    return longest_first;
}

// diameter is either
// tree's height
// or the longest distance among distances of pairs of leaves
int Graph::diameter()
{
    // root is just going to be 1, of coures possible the others
    int root_id = 1;
    Node *root = nodes[root_id];
    make_tree(root_id);
    int tree_height = height(root);
    return max(tree_height, longest_pair);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    istream &is = cin;
    int n;
    is >> n;
    Graph g(n); 
    cout << g.diameter() << endl;
    return 0;
}
