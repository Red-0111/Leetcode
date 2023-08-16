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
    void f(TreeNode* root,bool il)
    {
        if(!root) return;
        if(!root->left&&!root->right)
        {
            if(il) s+=root->val;
        }
        f(root->left,true);
        f(root->right,false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        f(root,false);
        return s;
    }
};