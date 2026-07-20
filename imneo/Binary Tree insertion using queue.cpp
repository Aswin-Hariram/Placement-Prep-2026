// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
    }
};

Node* insert(Node* root, vector<int> &arr) {
    if (arr.empty()) return NULL;

    root = new Node(arr[0]);

    queue<Node*> q;
    q.push(root);

    int ind = 1;

    while (!q.empty() && ind < arr.size()) {
        Node* node = q.front();
        q.pop();

      
        if (ind < arr.size()) {
            if (arr[ind] != -1) {
                node->left = new Node(arr[ind]);
                q.push(node->left);
            }
            ind++;
        }

        // Right child
        if (ind < arr.size()) {
            if (arr[ind] != -1) {
                node->right = new Node(arr[ind]);
                q.push(node->right);
            }
            ind++;
        }
    }

    return root;
}
void preOrder(Node* root){
    if(!root) return;
    
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root){
    if(!root) return;
    
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}
void PostOrder(Node* root){
    if(!root) return;
    
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->val<<" ";
}
void levelOrder(Node* root){
    
    if(!root) return;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int s = q.size();
        
        for(int i=0;i<s;i++){
            Node* node = q.front();
            q.pop();
            cout<<node->val<<" ";
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}


int main(){
    
    int n;
    cin>>n;
    
    Node* root = nullptr;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    root = insert(root,arr);
    cout<<"preOrder: \n";
    preOrder(root);
    cout<<endl;
    cout<<"Inorder: \n";
    inOrder(root);
    cout<<endl;
    cout<<"PostOrder: \n";
    PostOrder(root);
    cout<<endl;
    cout<<"Level Order: \n";
    levelOrder(root);
    cout<<endl;
    
    
    
}
