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
    pair<int,int> trav(TreeNode* node, int&res)
    {
        if(!node) return {0,0};
        auto[ls,lc]=trav(node->left, res);
        auto[rs,rc]=trav(node->right,res);
        int curs=node->val+ls+rs;
        int curc=1+lc+rc;
        if(curs/curc==node->val) res++;
        return {curs,curc};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int res=0;
        trav(root,res);
        return res;
    }
};