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

    bool iss(TreeNode* root, TreeNode* subr)
    {
        if(!root&&!subr) return true;
        if(!root||!subr) return false;
        if(root->val!=subr->val) return false;
        return iss(root->left, subr->left)&&iss(root->right,subr->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subr) {
        if(!root) return false;
        if(iss(root,subr)) return true;
        return isSubtree(root->left,subr)||isSubtree(root->right,subr);
    }
};