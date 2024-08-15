class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int five_dollar = 0, ten_dollar = 0;
        
        for (int x : bills) {
            if (x == 5) {
                five_dollar++;
            } else if (x == 10) {
                if (five_dollar > 0) {
                    five_dollar--;
                    ten_dollar++;
                } else {
                    return false;
                }
            } else {
                if (five_dollar > 0 && ten_dollar > 0) {
                    five_dollar--;
                    ten_dollar--;
                } else if (five_dollar > 2) {
                    five_dollar -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true; 
    }
};