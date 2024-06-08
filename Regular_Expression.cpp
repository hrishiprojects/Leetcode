class Solution {
public:
//T.C : O(m*n)
//S.C : O(m*n)

int t[21][21];

    bool solve(int i, int j, string& text, string& pattern) {
        if (j == pattern.length())
            return i == text.length();
            
        if (t[i][j] != -1) {
            return t[i][j];
        }
        
        bool ans = false;
        //first character match ho gya or . h to continue searching othe relement
        bool first_match = (i < text.length() &&
                            (pattern[j] == text[i] || pattern[j] == '.'));
          //* ka special case h ki pattern ko similar rkhe search kre or * ko full use krke ab bakio k
          //normal char leke matching kre
        if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
            ans = (solve(i, j + 2, text, pattern) ||
                   (first_match && solve(i + 1, j, text, pattern)));
        } else {
            ans = first_match && solve(i + 1, j + 1, text, pattern);
        }

        return t[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {
          memset(t, -1, sizeof(t));
        return solve(0, 0, s, p);
    }
};