using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int, int> freq;

        // Count frequencies of each element in arr1
        for (int i : arr1) {
            freq[i]++;
        }

        // Add elements from arr2 to the answer in the order they appear in arr2
        for (int i = 0; i < arr2.size(); i++) {
            if (freq.find(arr2[i]) != freq.end()) {
                while (freq[arr2[i]]-- > 0) {
                    ans.push_back(arr2[i]);
                }
                // Erase the element from the frequency map once added
                freq.erase(arr2[i]);
            }
        }

        // Add remaining elements from arr1 that are not in arr2
        vector<int> remaining;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            while (it->second-- > 0) {
                remaining.push_back(it->first);
            }
        }
        // Sort the remaining elements in ascending order
        sort(remaining.begin(), remaining.end());
        // Append the sorted remaining elements to the answer
        ans.insert(ans.end(), remaining.begin(), remaining.end());

        return ans;
    }
};
