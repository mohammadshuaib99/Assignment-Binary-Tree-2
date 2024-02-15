#include <iostream>
#include <queue>
#include <stack>
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

void zigzagLevelOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    stack<Node *> s;
    bool reverseLevel = false;

    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i)
        {
            Node *current = q.front();
            q.pop();

            if (reverseLevel)
                s.push(current);
            else
                cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }

        if (reverseLevel)
        {
            while (!s.empty())
            {
                Node *node = s.top();
                s.pop();
                cout << node->data << " ";
            }
        }

        reverseLevel = !reverseLevel;
    }
}

int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);

    // Building the tree structure
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    cout << "Zigzag Level Order Traversal: ";
    zigzagLevelOrderTraversal(a);
    cout << endl;

    return 0;
}
