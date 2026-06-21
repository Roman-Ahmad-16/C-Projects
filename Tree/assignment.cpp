#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }

    return root;
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
}
int main()
{

    Node *root = NULL;

    int arr[] = {3, 3 , 5, 11, 15, 6, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {

        root = insert(root, arr[i]);
    }

    cout << "LevelOrder = ";
    levelOrder(root);
    cout << endl;
}