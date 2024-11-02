//question: https://leetcode.com/problems/circular-sentence

class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) 
            words.push_back(word);
        for (int i = 0; i < words.size() - 1; ++i) {
            if (words[i].back() != words[i + 1].front()) 
                return false;
        }
        if (words.back().back() != words[0].front()) 
            return false;
        return true;
    }
};