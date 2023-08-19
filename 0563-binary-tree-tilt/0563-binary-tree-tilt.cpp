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

    int h(TreeNode* root, int& ts)
    {
        if(!root) return 0;
        int ls=h(root->left,ts);
        int rs=h(root->right,ts);
        ts+=abs(ls-rs);
        return (ls+root->val+rs);
    }

    int findTilt(TreeNode* root) {
        int ts {0};
        h(root,ts);
        return ts;
    }
};