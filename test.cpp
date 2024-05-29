class Solution {
public:
    int specialArray(vector<int>& nums) {
         int n = nums.size();

        /*
            Every number larger than N is useless for our purpose,
            and we can treat those numbers as N. 
            then we are just checking x=n-index
        */
       \\testing the atomic_commit
       \\second line
        vector<int> freq(n+1);
        vector<int>freq2(26,0);

        for(int i = 0; i < n; i++) {
            freq[min(n, nums[i])]++;
        }
        for(int i = 0; i < n; i++) {
            freq[min(n, nums[i])]++;
        }
        for(int i = 0; i < n; i++) {
            freq[min(n, nums[i])]++;
        }

        int c_sum = 0;
        for(int i = n; i >= 0; i--) {
            c_sum += freq[i];
            if(i == c_sum) {
                return i;
            }
        }
        
        return -1;
    }
};