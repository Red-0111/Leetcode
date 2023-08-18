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

    vector<int> in;

    void intr(TreeNode* root)
    {
        if(root){intr(root->left);
        in.push_back(root->val);
        intr(root->right);}
    }

    bool isUnivalTree(TreeNode* root) {
        intr(root);
        for(int i=1;i<in.size();i++) if(in[i]!=in[i-1]) return false;
        return true;
    }
};