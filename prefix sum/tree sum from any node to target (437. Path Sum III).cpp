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
 */class Solution {
public:
    unordered_map<long long, int> mp;

    int dfs(TreeNode* node, long long currSum, int targetSum) {
        if (!node) return 0;

        currSum += node->val;

        int count = 0;

        // Check if there exists a prefix sum = currSum - target
        if (mp.count(currSum - targetSum)) {
            count += mp[currSum - targetSum];
        }

        // Add current prefix sum
        mp[currSum]++;

        // Recurse left & right
        count += dfs(node->left, currSum, targetSum);
        count += dfs(node->right, currSum, targetSum);

        // 🔥 Backtrack (remove current path contribution)
        mp[currSum]--;

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1; 
        return dfs(root, 0, targetSum);
    }
};
