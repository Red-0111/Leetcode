/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    void pre(TreeNode* cloned, TreeNode* tar, TreeNode* &node)
    {
        if(!cloned) return;
        if(cloned->val==tar->val) node=cloned;
        pre(cloned->left,tar,node);
        pre(cloned->right,tar,node);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* tar) {
        if(!tar||!cloned) return nullptr;
        TreeNode* node=new TreeNode;
        pre(cloned,tar, node);
        return node;
    }
};