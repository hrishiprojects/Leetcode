int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       set<string>st;
        for(int i=0;i<wordList.size();i++){
            st.insert(wordList[i]);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        st.erase(beginWord);
        while(!q.empty()){
            auto curr=q.front();
            string str=curr.first;
            int d=curr.second;
            q.pop();
            if(str==endWord) return d+1;
            for(int i=0;i<str.length();i++){
                string t =str;
                for(char it='a';it<='z';it++){
                    t[i]=it;
                    if(st.count(t)){
                        st.erase(t);
                        q.push({t,d+1});
                        
                    }
                }
            }
        }
        return 0;     
    }
};