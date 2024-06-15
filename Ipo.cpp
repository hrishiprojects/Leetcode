class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int, int>> vec(n);
        
        for (int i = 0; i < n; i++) {
            vec[i] = {capital[i], profits[i]};
        }

        sort(vec.begin(), vec.end());

        int i = 0;

        priority_queue<int> pq;
         int ans=w;
        while (k--) {
            while (i < n && vec[i].first <= ans) {
                pq.push(vec[i].second);
                i++;
            }
            if (pq.empty())
                break;
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};