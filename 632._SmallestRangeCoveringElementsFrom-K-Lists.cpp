//question:- https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(), minRange = INT_MAX, minVal = INT_MAX, maxVal = INT_MIN;
        vector<int> result(2);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        vector<int> idx(k, 0);

        for (int i = 0; i < k; ++i) {
            minHeap.push({nums[i][0], i});
            maxVal = max(maxVal, nums[i][0]);
        }

        while (true) {
            auto [minVal, listIdx] = minHeap.top();
            minHeap.pop();

            if (maxVal - minVal < minRange) {
                minRange = maxVal - minVal;
                result[0] = minVal;
                result[1] = maxVal;
            }

            if (++idx[listIdx] == nums[listIdx].size())
                break;

            minHeap.push({nums[listIdx][idx[listIdx]], listIdx});
            maxVal = max(maxVal, nums[listIdx][idx[listIdx]]);
        }

        return result;
    }
};