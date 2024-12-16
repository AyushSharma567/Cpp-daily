//question:https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
         for (int i = 0; i < k; i++) {
        auto minElement = min_element(nums.begin(), nums.end());
        *minElement *= multiplier;
    }
    return nums;
    }
};