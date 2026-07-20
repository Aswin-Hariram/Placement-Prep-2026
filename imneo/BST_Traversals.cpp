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
    
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        root = insert(root,v);
    }
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
