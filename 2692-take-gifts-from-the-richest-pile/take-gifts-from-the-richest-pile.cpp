class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;

        priority_queue<int> pq;

        for (auto it : gifts) {
            pq.push(it);
        }

        while (k) {
            int top = pq.top();
            pq.pop();
            int nw = sqrt(top);
            pq.push(nw);
            k--;
        }

        while (!pq.empty()) {
            int el = pq.top();
            pq.pop();
            ans += el;
        }

        return ans;
    }
};