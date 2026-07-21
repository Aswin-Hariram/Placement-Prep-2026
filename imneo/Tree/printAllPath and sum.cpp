// You are using GCC
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(){}
    Node(int val){
        this->val = val;
        left=nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root,int val){
    if(root==nullptr) return new Node(val);
    
    if(val<root->val){
        root->left = insert(root->left,val);
        
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}

vector<int> temp;

void displayPath(Node* root, int sum) {
    if (!root) {
        return;
    }

    temp.push_back(root->val);
    sum += root->val;


    if (!root->left && !root->right) {
        for (int v : temp)
            cout << v << " ";
        cout << "= " << sum << endl;
    }


    displayPath(root->left, sum); 
    displayPath(root->right, sum);
    temp.pop_back();
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

   displayPath(root,0);
    
}
