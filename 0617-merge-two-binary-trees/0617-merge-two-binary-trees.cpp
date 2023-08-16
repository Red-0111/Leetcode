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

    void trav(TreeNode* &r1, TreeNode* &r2)
    {
        if(r1==NULL||r2==NULL) return;
        if(r1->left&&r2->left) r1->left->val=r1->left->val+r2->left->val;
        if(r1->right&&r2->right) r1->right->val=r1->right->val+r2->right->val;
        if(r1->left&&!r2->left) r1->left->val=r1->left->val+0;
        if(!r1->left&&r2->left)
        {
            TreeNode* lnode=new TreeNode(r2->left->val);
            r1->left=lnode;
        }
        if(r1->right&&!r2->right) r1->right->val=r1->right->val+0;
        if(!r1->right&&r2->right)
        {
            TreeNode* rnode=new TreeNode(r2->right->val);
            r1->right=rnode;
        }
        trav(r1->left,r2->left);
        trav(r1->right,r2->right);
    }

    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(r1&&r2) r1->val=r1->val+r2->val;
        if(r1&&!r2) r1->val=r1->val+0;
        if(!r1&&r2)
        {
            TreeNode* node=new TreeNode(r2->val);
            r1=node;
        } 
        trav(r1,r2);
        return r1;
    }
};