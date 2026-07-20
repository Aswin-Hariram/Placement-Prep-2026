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

Node* findLCA(Node* root,int p,int q){
    if(!root||p==root->val||q==root->val){
        return root;
    }
    
    Node* left = findLCA(root->left, p, q);
    Node* right = findLCA(root->right, p, q);
    
    
    if (left && right)
        return root;
    
    return (left != nullptr) ? left : right;
    
}
int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p,q;
    Node* root = insert(arr, 0);
    cin>>p>>q;
   Node* lca = findLCA(root,p,q);
   cout<<lca->val;
    return 0;
}
