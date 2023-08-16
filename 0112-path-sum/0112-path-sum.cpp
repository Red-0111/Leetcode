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
public:
    bool hasPathSum(TreeNode* root, int tar) {
        if(!root) return false;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            auto [node,sum]=q.front();
            q.pop();
            if(!node->left&&!node->right&&(sum+node->val)==tar) return true;
            if(node->left) q.push({node->left,sum+node->val});
            if(node->right) q.push({node->right,sum+node->val});
        }
        return false;
    }
};