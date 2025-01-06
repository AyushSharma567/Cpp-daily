//question: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(),  ballsToLeft = 0, movesToLeft = 0, ballsToRight = 0, movesToRight = 0;
        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++) {
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;
            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }
        return answer;
    }
};