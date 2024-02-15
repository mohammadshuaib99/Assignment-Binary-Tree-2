#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class HeightDiameter
{
public:
    int height;
    int diameter;
    HeightDiameter(int height, int diameter) : height(height), diameter(diameter) {}
};

HeightDiameter helper(Node *root)
{
    if (root == nullptr)
        return HeightDiameter(0, 0);

    HeightDiameter left = helper(root->left);
    HeightDiameter right = helper(root->right);

    int height = max(left.height, right.height) + 1;
    int diameter = max({left.diameter, right.diameter, left.height + right.height});

    return HeightDiameter(height, diameter);
}

int diameterOfBinaryTree(Node *root)
{
    return helper(root).diameter;
}

int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *f = new Node(60);
    Node *g = new Node(70);
    Node *h = new Node(80);
    Node *i = new Node(90);

    // Building the tree structure
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    d->left = h;
    d->right = i;

    cout << "Diameter of the binary tree: " << diameterOfBinaryTree(a) << endl;

    return 0;
}
