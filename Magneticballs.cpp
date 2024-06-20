class Solution {
public:
   bool ispossible(vector<int>& position, int n,int m,int mid)
    {
        int ballcount=1;
        int lastposition=position[0];
       
       for(int i=0;i<n;i++){
           if(position[i]-lastposition>=mid)
        {
            ballcount++;
            if(ballcount==m)
            {
                return true;
            }
            lastposition=position[i];
        }
       } 
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start=0;
        int ans=-1;
        int end=position[position.size()-1]-position[0];
       
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if((ispossible(position,position.size(), m, mid)))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
};