class Solution {
public:

bool static sorted(vector<int>&v1, vector<int>&v2){
        if(v1[0]==v2[0])
        {
            return v1[1]>v2[1];
        }
        else{
            return v1[0]<v2[0];
        } 
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num: nums){
            mp[num]++;
        }

        vector<vector<int>> tmp;
        for(auto x: mp){
            tmp.push_back({x.second,x.first});
        }

        sort(tmp.begin(),tmp.end(),sorted);
        vector<int> ans;
        for(auto x: tmp){
            for(int i=0;i<x[0];i++){
                ans.push_back(x[1]);
            }
        }
        return ans; 
    }
};