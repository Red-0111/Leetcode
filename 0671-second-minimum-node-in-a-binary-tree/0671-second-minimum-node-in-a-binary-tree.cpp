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

    void inor(TreeNode* root, vector<int> & v)
    {
        if(!root) return;
        inor(root->left,v);
        v.push_back(root->val);
        inor(root->right,v);
    }

    int findSecondMinimumValue(TreeNode* root) {
        vector<int> ans;
        inor(root,ans);
        sort(ans.begin(),ans.end());
        int mini=ans[0];
        int n=ans.size();
        if(ans[0]==ans[n-1]) return -1;
        for(int i=0;i<n;i++)
        {
            if(mini<ans[i])
            {
                mini=ans[i];
                break;
            }
        }
        return mini;
    }
};