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
    void trav(TreeNode* root,int l,int r)
    {
        if(root)
        {
            trav(root->left,l,r);
            if(root->val<=r&&root->val>=l) s+=root->val;
            trav(root->right,l,r);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        trav(root,low,high);
        return s;
    }
};