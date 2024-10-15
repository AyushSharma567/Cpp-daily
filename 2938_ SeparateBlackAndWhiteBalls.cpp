//question :- https://leetcode.com/problems/separate-black-and-white-balls/

class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0, countOnes = 0;
        for (char c : s) {
            if (c == '1')
                countOnes++;
            else
                steps += countOnes;
        }
        return steps;
    }
};