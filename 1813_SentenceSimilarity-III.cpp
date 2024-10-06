//question :-https://leetcode.com/problems/sentence-similarity-iii/

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.length() < sentence2.length())
            swap(sentence1, sentence2);
        vector<string> s1, s2;
        stringstream ss1(sentence1), ss2(sentence2);
        string word;

        while (ss1 >> word)
            s1.push_back(word);
        while (ss2 >> word)
            s2.push_back(word);

        int left = 0, right = 0;
        while (left < s2.size() && s1[left] == s2[left])
            left++;
        while (right < s2.size() &&
               s1[s1.size() - right - 1] == s2[s2.size() - right - 1])
            right++;

        return left + right >= s2.size();
    }
};
