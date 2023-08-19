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

    void post(TreeNode* root,vector<int>& v)
    {
        if(!root) return;
        if(!root->left&&!root->right) v.push_back(root->val);
        post(root->left,v);
        post(root->right,v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> f,s;
        post(root1,f);
        post(root2,s);
        if(f.size()!=s.size()) return false;
        for(int i=0;i<f.size();i++) if(f[i]!=s[i]) return false;
        return true;
    }
    
};