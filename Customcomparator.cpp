class Solution {
public:
static bool help(int& a,int& b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1+s2>s2+s1;
}
    string largestNumber(vector<int>& nums) {
        sort(begin(nums),end(nums),help);
        if(nums[0]==0){
            return "0";
        }
        string ans="";
        for(auto i:nums){
             ans+= to_string(i);
        }
        return ans;
    }
};