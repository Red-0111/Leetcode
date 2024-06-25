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

    int s=0;
    void in(TreeNode* root)
    {
        if(root)
        {
            in(root->right);
            s+=root->val;
            root->val=s;
            in(root->left);
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        in(root);
        return root;
    }
};