// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root,int val){
    if(!root){
        return new Node(val);
    }
    if(val<root->val){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}
Node* findLCA(Node* root, int p, int q) {
    while (root) {

        if (p < root->val && q < root->val)
            root = root->left;

        else if (p > root->val && q > root->val)
            root = root->right;

        else
            return root;
    }

    return nullptr;
}

int main(){
    
    int n;
    cin>>n;
    
    Node* root = nullptr;
    
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        root = insert(root,v);
    }
    int p,q;
    cin>>p>>q;
    
    Node* lca = findLCA(root,p,q);
    cout<<"LCA: ";
    cout<<lca->val;
    
    
    
    
}
