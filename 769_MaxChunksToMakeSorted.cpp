//question : https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), chunks = 0, prefixSum = 0, sortedPrefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            sortedPrefixSum += i;
            if (prefixSum == sortedPrefixSum) {
                chunks++;
            }
        }
        return chunks;
    }
};