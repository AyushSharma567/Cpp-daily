//question: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCombinationSize = 0;
        for (int bit = 0; bit < 24; ++bit) {
            int count = 0;
            for (int num : candidates) 
                if (num & (1 << bit)) 
                    ++count;
            maxCombinationSize = max(maxCombinationSize, count);
        }
        return maxCombinationSize;
    }
};