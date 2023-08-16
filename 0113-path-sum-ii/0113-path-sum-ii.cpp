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
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*, pair<int, vector<int>>>> q;
        q.push({root,{root->val,{root->val}}});
        while(!q.empty())
        {
            auto ele=q.front();
            q.pop();
            auto node=ele.first;
            auto [sum,path]=ele.second;
            if(!node->left&&!node->right&&sum==tar) ans.push_back(path);
            if(node->left)
            {
                vector<int> lp=path;
                lp.push_back(node->left->val);
                q.push({node->left,{sum+node->left->val, lp}});
            }
            if(node->right)
            {
                vector<int> rp=path;
                rp.push_back(node->right->val);
                q.push({node->right,{sum+node->right->val,rp}});
            }
        }
        return ans;
    }
};