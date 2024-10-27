//question: https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), total = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) +  1;
                    total += dp[i][j];
                }
            }
        }
        return total;
    }
};
