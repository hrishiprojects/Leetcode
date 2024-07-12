class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int answer = 0;

        if (x >= y) {
            std::stack<char> st1;
            int ans = 0;

            for (int i = 0; i < n; i++) {
                if (!st1.empty() && s[i] == 'b' && st1.top() == 'a') {
                    ans += x;
                    st1.pop();
                } else {
                    st1.push(s[i]);
                }
            }

            std::string t = "";
            while (!st1.empty()) {
                t += st1.top();
                st1.pop();
            }
            std::reverse(t.begin(), t.end());

            for (int i = 0; i < t.size(); i++) {
                if (!st1.empty() && t[i] == 'a' && st1.top() == 'b') {
                    st1.pop();
                    ans += y;
                } else {
                    st1.push(t[i]);
                }
            }
            answer = ans;

        } else {
            int ans1 = 0;
            std::stack<char> st;

            for (int i = 0; i < n; i++) {
                if (!st.empty() && s[i] == 'a' && st.top() == 'b') {
                    ans1 += y;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }

            std::string t = "";
            while (!st.empty()) {
                t += st.top();
                st.pop();
            }
            std::reverse(t.begin(), t.end());

            for (int i = 0; i < t.size(); i++) {
                if (!st.empty() && t[i] == 'b' && st.top() == 'a') {
                    st.pop();
                    ans1 += x;
                } else {
                    st.push(t[i]);
                }
            }
            answer = ans1;
        }

        return answer;   
    
    }
};