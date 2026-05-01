/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* prev;
    void flat(TreeNode* root){
        
        if(!root) return;
        flat(root->right);
        flat(root->left);
        root->left = nullptr;
        root->right = prev;
        prev = root;
        
    }
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flat(root);
    }
};
