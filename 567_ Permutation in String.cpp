// question :- https://leetcode.com/problems/permutation-in-string/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> s1Count(26, 0), s2Count(26, 0);
        
        for (int i = 0; i < s1.size(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        
        int matches = 0;
        for (int i = 0; i < 26; ++i)
            if (s1Count[i] == s2Count[i])
                matches++;
        
        for (int i = s1.size(); i < s2.size(); ++i) {
            if (matches == 26) return true;
            
            int r = s2[i] - 'a', l = s2[i - s1.size()] - 'a';
            s2Count[r]++;
            if (s2Count[r] == s1Count[r])
                matches++;
            else if (s2Count[r] == s1Count[r] + 1)
                matches--;
            
            s2Count[l]--;
            if (s2Count[l] == s1Count[l])
                matches++;
            else if (s2Count[l] == s1Count[l] - 1)
                matches--;
        }
        
        return matches == 26;
    }
};

int main() {
    string s1, s2;
    
    //cout << "Enter the first string (s1): ";
    cin >> s1;
    
    //cout << "Enter the second string (s2): ";
    cin >> s2;

    Solution S;
    
    cout << (S.checkInclusion(s1, s2) ? "true" : "false") << endl;
    
    return 0;
}