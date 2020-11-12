#include <iostream>
#include <vector>

struct Node {
    char c;
    Node *left_child;
    Node *right_child;
    Node(char c) : c(c) {}
};

struct Tree {
    Tree(int n, std::istream &is);
    Node* search(char c);
    void insert(char p, char lc, char rc);
    void inorder(Node *local_root);
    void preorder(Node *local_root);
    void postorder(Node *local_root);
private:
    std::vector<Node*> v;
};

Tree::Tree(int n, std::istream &is) : v(n)
{
    char p, lc, rc;
    while (n--) {
        is >> p >> lc >> rc;
        insert(p, lc, rc);
    }

    Node *root = v[0];
    preorder(root);
    std::cout << std::endl;
    inorder(root);
    std::cout << std::endl;
    postorder(root);
    std::cout << std::endl;
}

Node* Tree::search(char c)
{
    return v[c - 'A'];
}

void Tree::insert(char p, char lc, char rc)
{
    Node *parent = search(p);
    if (parent == nullptr) {
        parent = new Node(p);
        v[p - 'A'] = parent;
    }
    Node *left_child = nullptr;
    if (lc != '.') {
        left_child = search(lc);
        if (left_child == nullptr) {
            left_child = new Node(lc);
            v[lc - 'A'] = left_child;
        }
    }
    Node *right_child = nullptr;
    if (rc != '.') {
        right_child = search(rc);
        if (right_child == nullptr) {
            right_child = new Node(rc);
            v[rc - 'A'] = right_child;
        }
    }

    parent->left_child = left_child;
    parent->right_child = right_child;
}

void Tree::inorder(Node *local_root)
{
    if (local_root == nullptr) return;
    inorder(local_root->left_child);
    std::cout << local_root->c;
    inorder(local_root->right_child);
}

void Tree::preorder(Node *local_root)
{
    if (local_root == nullptr) return;
    std::cout << local_root->c;
    preorder(local_root->left_child);
    preorder(local_root->right_child);
}

void Tree::postorder(Node *local_root)
{
    if (local_root == nullptr) return;
    postorder(local_root->left_child);
    postorder(local_root->right_child);
    std::cout << local_root->c;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::istream &is = std::cin;
    is >> n;
    Tree tree(n, is);
    return 0;
}
