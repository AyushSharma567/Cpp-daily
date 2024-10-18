//question:- https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0, count = 0;
        
        for (int num : nums) 
            maxOr |= num;
        
        function<void(int, int)> dfs = [&](int i, int currOr) {
            if (i == nums.size()) {
                if (currOr == maxOr) 
                    count++;
                return;
            }
            
            dfs(i + 1, currOr | nums[i]);
            
            dfs(i + 1, currOr);
        };
        
        dfs(0, 0);
        
        return count;
    }
};
