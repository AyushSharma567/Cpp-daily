//question: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;
        for (auto& row : matrix) {
            string pattern;
            for (int j = 0; j < row.size(); ++j) 
                pattern += (row[j] == row[0]) ? '1' : '0';
            patternCount[pattern]++;
        }
        int maxRows = 0;
        for (auto& p : patternCount) 
            maxRows = max(maxRows, p.second);
        return maxRows;
    }
};