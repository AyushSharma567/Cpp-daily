//question: https://leetcode.com/problems/string-matching-in-an-array/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> str;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j) {
                    size_t found = words[j].find(words[i]);
                    if (found != string::npos) {
                        str.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return str;
    }
};