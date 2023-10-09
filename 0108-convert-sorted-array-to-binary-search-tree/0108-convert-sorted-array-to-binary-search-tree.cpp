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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        if(nums.size()==1) return new TreeNode(nums[0]);
        int m=nums.size()/2;
        TreeNode* r=new TreeNode(nums[m]);
        vector<int> ls(nums.begin(),nums.begin()+m);
        vector<int> rs(nums.begin()+m+1,nums.end());
        r->left=sortedArrayToBST(ls);
        r->right=sortedArrayToBST(rs);
        return r;
    }
};