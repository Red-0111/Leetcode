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

    void um(TreeNode* root,unordered_map<int,int> &m)
    {
        m[root->val]++;
        if(root->left) um(root->left,m);
        if(root->right) um(root->right,m);
        return;
    }

    void umf(unordered_map<int,int>&m,vector<int>&v)
    {
        int mf=0;
        for(auto &p:m) if(mf<p.second) mf=p.second;
        for(auto &p:m) if(p.second==mf) v.emplace_back(p.first);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        vector<int> v;
        if(root) um(root,m);
        umf(m,v);
        return v;
    }
};