class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();         
        int m = matrix[0].size();      
        
        vector<int> row(n, 1e6);    
        vector<int> col(m, 0);     
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] = min(row[i], matrix[i][j]);   
                col[j] = max(col[j], matrix[i][j]);   
            }
        }

        vector<int> ans;  
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k = row[i];   
                int l = col[j];   
                if (matrix[i][j] == k && k == l) {   
                    ans.push_back(matrix[i][j]);     
                }
            }
        }

        return ans;   
    }
};