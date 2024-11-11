//question: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int maxFrequency = 1;
        for (int i = 0; i < n; i++) {
            int target = nums[i],operations = numOperations, frequency = 1;  
            for (int j = i - 1; j >= 0 && operations > 0; j--) {
                if (abs(target - nums[j]) <= k) {
                    frequency++;
                    operations--;
                }
            }
            for (int j = i + 1; j < n && operations > 0; j++) {
                if (abs(nums[j] - target) <= k) {
                    frequency++;
                    operations--;
                }
            }
            
            maxFrequency = max(maxFrequency, frequency);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= 2 * k && numOperations >= 2) {
                    maxFrequency = max(maxFrequency, 2);
                }
            }
        }
        
        return maxFrequency;
    }
};