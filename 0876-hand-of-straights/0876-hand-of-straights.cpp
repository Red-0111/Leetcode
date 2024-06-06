class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if (hand.size() % gs != 0) return false;

        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        for (auto it = count.begin(); it != count.end(); ++it) {
            int start = it->first;
            int freq = it->second;

            if (freq > 0) {
                for (int i = 0; i < gs; i++) {
                    if (count[start + i] < freq) {
                        return false;
                    }
                    count[start + i] -= freq;
                }
            }
        }

        return true;
    }
};