#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// Build Binary Tree using 2*i+1 and 2*i+2 logic
Node* insert(vector<int> &arr, int i) {
    if (i >= arr.size() || arr[i] == -1)
        return NULL;

    Node* root = new Node(arr[i]);

    root->left = insert(arr, 2 * i + 1);
    root->right = insert(arr, 2 * i + 2);

    return root;
}

// Preorder Traversal
void preOrder(Node* root) {
    if (!root)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder Traversal
void inOrder(Node* root) {
    if (!root)
        return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// Postorder Traversal
void postOrder(Node* root) {
    if (!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

// Level Order Traversal
void levelOrder(Node* root) {
    if (!root)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left)
            q.push(node->left);

        if (node->right)
            q.push(node->right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node* root = insert(arr, 0);

    cout << "PreOrder:\n";
    preOrder(root);
    cout << endl;

    cout << "InOrder:\n";
    inOrder(root);
    cout << endl;

    cout << "PostOrder:\n";
    postOrder(root);
    cout << endl;

    cout << "LevelOrder:\n";
    levelOrder(root);
    cout << endl;

    return 0;
}
