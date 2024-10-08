//question :- https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0, swaps = 0;
        for (char c : s) {
            if (c == '[') {
                imbalance++;
            } else {
                if (imbalance > 0) {
                    imbalance--;
                } else {
                    swaps++;
                    imbalance++;
                }
            }
        }
        return swaps;
    }
};