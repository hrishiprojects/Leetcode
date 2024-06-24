class Solution {
public:
 int finalbit(int bit, int flips)
    {
        if (flips % 2 == 0)
            return bit;
        return !bit;
    }
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n + 1);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i)
                pref[i] += pref[i - 1];

            if (i < n - k + 1)
            {
                int flips = pref[i];
                int bit = finalbit(nums[i], flips);

                if (bit == 1)
                    continue;

                ans++;
                pref[i]++;
                pref[i + k]--;
            }
        }

        int cnt = 0;
        vector<int> after(n);
        for (int i = 0; i < n; i++)
        {
            after[i] = finalbit(nums[i], pref[i]);
            cnt += (after[i] == 1);
        }
        
        return cnt == n ? ans : -1;
    }
};