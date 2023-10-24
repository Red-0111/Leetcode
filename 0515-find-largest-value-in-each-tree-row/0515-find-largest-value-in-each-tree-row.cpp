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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int> res;
        q.push(root);
        if(!root) return res;
        while(!q.empty())
        {
            int lev=q.size();
            int maxl=INT_MIN;
            for(int i=0;i<lev;i++)
            {
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                maxl=max(maxl,tmp->val);
            }
            res.push_back(maxl);
        }
        return res;
    }
};