//question:- https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> arrivals(n);
        for (int i = 0; i < n; ++i) {
            arrivals[i] = {times[i][0], i};
        }
        sort(arrivals.begin(), arrivals.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaveQueue;
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i);
        }
        
        vector<int> chairs(n);
        for (int i = 0; i < n; ++i) {
            int arrivalTime = arrivals[i].first, friendIdx = arrivals[i].second;
            
            while (!leaveQueue.empty() && leaveQueue.top().first <= arrivalTime) {
                availableChairs.push(leaveQueue.top().second);
                leaveQueue.pop();
            }
            
            int assignedChair = availableChairs.top();
            availableChairs.pop();
            chairs[friendIdx] = assignedChair;
            leaveQueue.push({times[friendIdx][1], assignedChair});
            
            if (friendIdx == targetFriend) {
                return assignedChair;
            }
        }
        
        return -1;
    }
};
