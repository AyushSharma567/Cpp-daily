//question: https://leetcode.com/problems/best-sightseeing-pair/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), maxLeftScore = values[0], maxScore = 0;
        for (int i = 1; i < n; i++) {
            int currentRightScore = values[i] - i;
            maxScore = max(maxScore, maxLeftScore + currentRightScore);
            int currentLeftScore = values[i] + i;
            maxLeftScore = max(maxLeftScore, currentLeftScore);
        }
        return maxScore;
    }
};