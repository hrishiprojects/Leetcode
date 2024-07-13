class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size(),i=0;
        map<int,pair<int,char>>mp;
        stack<int>st;        

        for(i=0;i<n;i++)mp[positions[i]]={healths[i],directions[i]};
        auto it=mp.begin();
        
        while(it!=mp.end()){
            if(st.empty() || ((it->second).second == mp[st.top()].second) || ((it->second).second == 'R' && mp[st.top()].second == 'L')){st.push(it->first);it++;}
            else{
                if((it->second).first == mp[st.top()].first){
                        mp[st.top()].first = (it->second).first =0;
                        st.pop();it++;
                    }
                    else if((it->second).first > mp[st.top()].first){
                        mp[st.top()].first=0;
                        st.pop();
                        (it->second).first--;
                    }
                    else if((it->second).first < mp[st.top()].first){
                        (it->second).first=0;
                        mp[st.top()].first--;
                        it++;
                }
            }
        }
        vector<int>ans;
        
        for(i=0;i<n;i++){
            if(mp[positions[i]].first)ans.push_back(mp[positions[i]].first);
        }
        
        return ans;
    }
};