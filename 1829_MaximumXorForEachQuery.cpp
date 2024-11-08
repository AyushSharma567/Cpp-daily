//question : https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res(nums.size());
        int val = (1 << maximumBit) - 1;
        for (int i = 0; i < nums.size(); ++i)
            res[nums.size() - i - 1] = val ^= nums[i];
        return res;
    }
};