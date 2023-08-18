/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int l=0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            size_t s=q.size();
            l++;
            for(int i=0;i<s;i++)
            {
                Node* cur=q.front();
                q.pop();
                for(Node* &c:cur->children) q.push(c);
            }
        }
        return l;
    }
};