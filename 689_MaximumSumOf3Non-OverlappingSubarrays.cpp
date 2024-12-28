//question: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int bestSingleStart = 0;
        vector<int> bestDoubleStart = {0, k};
        vector<int> bestTripleStart = {0, k, k * 2};
        int currentWindowSumSingle = 0;
        for (int i = 0; i < k; i++) 
            currentWindowSumSingle += nums[i];
        int currentWindowSumDouble = 0;
        for (int i = k; i < k * 2; i++) 
            currentWindowSumDouble += nums[i];
        int currentWindowSumTriple = 0;
        for (int i = k * 2; i < k * 3; i++) 
            currentWindowSumTriple += nums[i];
        int bestSingleSum = currentWindowSumSingle, bestDoubleSum = currentWindowSumSingle + currentWindowSumDouble, bestTripleSum = currentWindowSumSingle + currentWindowSumDouble + currentWindowSumTriple, singleStartIndex = 1, doubleStartIndex = k + 1, tripleStartIndex = k * 2 + 1;
        while (tripleStartIndex <= nums.size() - k) {
            currentWindowSumSingle = currentWindowSumSingle - nums[singleStartIndex - 1] + nums[singleStartIndex + k - 1];
            currentWindowSumDouble = currentWindowSumDouble - nums[doubleStartIndex - 1] + nums[doubleStartIndex + k - 1];
            currentWindowSumTriple = currentWindowSumTriple - nums[tripleStartIndex - 1] + nums[tripleStartIndex + k - 1];
            if (currentWindowSumSingle > bestSingleSum) {
                bestSingleStart = singleStartIndex;
                bestSingleSum = currentWindowSumSingle;
            }
            if (currentWindowSumDouble + bestSingleSum > bestDoubleSum) {
                bestDoubleStart[0] = bestSingleStart;
                bestDoubleStart[1] = doubleStartIndex;
                bestDoubleSum = currentWindowSumDouble + bestSingleSum;
            }
            if (currentWindowSumTriple + bestDoubleSum > bestTripleSum) {
                bestTripleStart[0] = bestDoubleStart[0];
                bestTripleStart[1] = bestDoubleStart[1];
                bestTripleStart[2] = tripleStartIndex;
                bestTripleSum = currentWindowSumTriple + bestDoubleSum;
            }
            singleStartIndex += 1;
            doubleStartIndex += 1;
            tripleStartIndex += 1;
        }
        return bestTripleStart;
    }
};