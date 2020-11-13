#include <iostream>
#include <vector>
#include <algorithm> // max

using namespace std;

struct Edge;

struct Node {
    std::vector<Edge*> to_children;
};

struct Edge {
    Node *child;
    int weight;
    Edge(Node *child, int weight) : child(child), weight(weight) {}
};


struct Tree {
    Tree (int n, istream &is);
    int diameter();
private:
    int height(Node *root);

    int n;
    int longest_pair;
    std::vector<Node*> nodes;
};

Tree::Tree(int n, istream &is = cin)
    : n(n), longest_pair(0), nodes(n+1, nullptr)
{
    int p, c, w;
    for (int i = 1; i < n; ++i) {
        is >> p >> c >> w;
        Node *parent = nodes[p];
        if (parent == nullptr) {
            nodes[p] = parent = new Node();
        }
        Node *child = nodes[c];
        if (child == nullptr) {
            nodes[c] = child = new Node();
        }
        parent->to_children.push_back(new Edge(child, w));
    }
}

// return local root's longest height
// height: addition of the weight of the edge with a child and its height
int Tree::height(Node *local_root)
{
    std::vector<int> heights;
    for (auto &edge : local_root->to_children)
        heights.push_back(edge->weight + height(edge->child));

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
        // save the longest distance of a pair of leaves
        if (longest_pair < longest_first + longest_second) 
            longest_pair = longest_first + longest_second;
    }

    return longest_first;
}

int Tree::diameter()
{
    if (n == 1) 
        return 0;

    // a tree's diameter is either 
    // case 1: root's height or
    // case 2: the longest distance of a pair of leaves
    int root_height = height(nodes[1]);
    return max(longest_pair, root_height);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    Tree tree(n);
    cout << tree.diameter() << std::endl;
    return 0;
}
