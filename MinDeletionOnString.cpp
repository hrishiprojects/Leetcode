class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count=0;

        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c == 'a'){
                if(!st.empty()){
                    st.pop();
                    count++;
                }
            }
            else{
               st.push(c);
            }
        }

        return count;
    }
};