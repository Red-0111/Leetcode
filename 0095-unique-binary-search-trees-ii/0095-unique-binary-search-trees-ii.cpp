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
    vector<TreeNode*> generateTrees(int n,int s=1) {
        vector<TreeNode*> ans;
        if(n<s) return {nullptr};
        for(int i=s;i<=n;i++)
        {
            for(auto l:generateTrees(i-1,s))
            {
                for(auto r:generateTrees(n,i+1)) ans.push_back(new TreeNode(i,l,r));
            }
        }
        return ans;
    }
};