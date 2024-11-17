//question: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

#define ll long long
class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();
        ll len = INT_MAX, sum = 0;
        deque<pair<ll, ll>> mq;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum >= k)
                len = min(len, i * 1LL + 1);
            while (!mq.empty() && sum <= mq.front().first)
                mq.clear();
            while (!mq.empty() && sum <= mq.back().first)
                mq.pop_back();
            while (!mq.empty() && sum - mq.front().first >= k) {
                len = min(len, i - mq.front().second);
                mq.pop_front();
            }
            mq.push_back({sum, i * 1LL});
        }
        return (len != INT_MAX) ? len : -1;
    }
};
