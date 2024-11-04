//question: https://leetcode.com/problems/string-compression-iii/

class Solution {
public:
    string compressedString(string word) {
        string comp;
        int i = 0, n = word.size();
        while (i < n) {
            char c = word[i];
            int count = 0;
            while (i < n && word[i] == c && count < 9) {
                count++;
                i++;
            }
            comp += to_string(count) + c;
        }
        return comp;
    }
};