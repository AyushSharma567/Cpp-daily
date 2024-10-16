//question:- https://leetcode.com/problems/longest-happy-string

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string result = "";
        while (!pq.empty()) {
            auto [count1, char1] = pq.top();
            pq.pop();
            if (!result.empty() && result.back() == char1) {
                if (pq.empty())
                    break;
                auto [count2, char2] = pq.top();
                pq.pop();
                result += char2;
                if (--count2 > 0)
                    pq.push({count2, char2});
                pq.push({count1, char1});
            } else {
                int limit = min(2, count1);
                result += string(limit, char1);
                if (count1 > limit)
                    pq.push({count1 - limit, char1});
            }
        }
        return result;
    }
};