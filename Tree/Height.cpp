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

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt, rightHt) + 1;
}

int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount + 1;
}

int sumOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return leftSum + rightSum + root->data;
}

int main()
{

    Node *root = NULL;

    int arr[] = {3, 3, 2, 2, 5, 11, 15, 6, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {

        root = insert(root, arr[i]);
    }

    cout << "InOrder = ";
    inOrder(root);
    cout << endl;

    cout << endl;

    cout << "Height : " << height(root) << endl;
    cout << "Count  : " << count(root) << endl;
    cout << "Sum    : " << sumOfNodes(root) << endl;
}