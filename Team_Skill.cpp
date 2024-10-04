class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
      int  n = skill.size();
      sort(skill.begin(),skill.end());
        int i=0;
        int j = n-1;
        int sum = skill[i] +skill[j];
        long long ans=0;

        while(i<j){
            int chem = skill[i] +skill[j];
            if(chem != sum){
                return -1;
            }
            ans += (long long)(skill[i]) * (long long)(skill[j]);

            i++;
            j--;

      }

      return ans ;
    }
};