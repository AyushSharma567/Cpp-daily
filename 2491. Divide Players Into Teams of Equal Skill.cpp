//question :- https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int target = skill[0] + skill[n - 1]; 

        long long chemistry = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (skill[i] + skill[n - 1 - i] != target) {
                return -1;
            }
            chemistry += 1LL * skill[i] * skill[n - 1 - i];
        }

        return chemistry; 
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter the number of players (even number): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Invalid input. The number of players must be even." << endl;
        return 1; 
    }

    vector<int> skill(n);
    cout << "Enter the skill levels of the players: ";
    for (int i = 0; i < n; ++i) {
        cin >> skill[i];
    }

    long long result = sol.dividePlayers(skill);
    if (result == -1) {
        cout << "It is not possible to divide the players into teams with equal skill sum." << endl;
    } else {
        cout << "The sum of the chemistry of all teams is: " << result << endl;
    }

    return 0;
}
