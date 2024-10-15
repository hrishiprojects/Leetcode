class Solution {
public:
    long long minimumSteps(string s) {
       long long ans = 0;  
        int zero_cnt = 0;

        // Traverse the string in reverse
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                zero_cnt++;  
            } else if (s[i] == '1') {
                ans += zero_cnt;  
            }
        }

        return ans;   
    }
};