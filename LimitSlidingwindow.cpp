class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
         deque<int> minDeque;
        deque<int> maxDeque;
        int left = 0, right = 0;
        int maxLength = 0;

        while (right < nums.size()) {
           
           
            while (!minDeque.empty() && minDeque.back() > nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[right]);

           
            while (!maxDeque.empty() && maxDeque.back() < nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);

            
            while (maxDeque.front() - minDeque.front() > limit) {
                if (nums[left] == minDeque.front()) minDeque.pop_front();
                if (nums[left] == maxDeque.front()) maxDeque.pop_front();
                left++;
            }

            
            maxLength = max(maxLength, right - left + 1);

            
            right++;
        }

        return maxLength;
    }
};