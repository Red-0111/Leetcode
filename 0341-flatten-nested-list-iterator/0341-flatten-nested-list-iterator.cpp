/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> f;
    int idx;
    vector<int> fl(const vector<NestedInteger>&nstd)
    {
        vector<int> res;
        for(const auto& ni:nstd)
        {
            if(ni.isInteger()) res.push_back(ni.getInteger());
            else
            {
                auto sl=fl(ni.getList());
                res.insert(res.end(),sl.begin(),sl.end());
            }
        }
        return res;
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        f=fl(nestedList);
        idx=0;
    }
    
    int next() {
        return f[idx++];
    }
    
    bool hasNext() {
        return idx<f.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */