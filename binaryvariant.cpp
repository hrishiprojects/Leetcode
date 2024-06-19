class Solution {
public:
 bool isValid(vector<int>& bloomDay, int m, int k, int bloom){
        int subarray = 0;
        int bouq_cnt = 0;
        
        for(auto x: bloomDay){
            if(x <= bloom){
                subarray++;
                if(subarray == k)
                    bouq_cnt++, subarray = 0;
            }
            else
                subarray = 0;
        }
        
        return bouq_cnt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
         int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int res = -1;
        
        while(start <= end){
            int mid = start+(end-start)/2;
            if(isValid(bloomDay, m, k, mid)){
                res = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        
        return res;
    }
};