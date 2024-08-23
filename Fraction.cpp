class Solution {
public:
    string fractionAddition(string expression) {
      const int lcm = 2520;
        int sign = 1, curNum = 1, curDen = 1, len = expression.length(), sumNum = 0;

        for (auto i = 0; i < len; i++){
            if (expression[i] == '+' || expression[i] == '-') expression[i] == '+'? sign = 1 : sign = -1;
            else if (expression[i] == '/') continue;
            else if (i > 0 && expression[i - 1] == '/') {
                if (expression[i] == '1' && i < len - 1 && expression[i + 1] == '0') {
                    curDen = 10;
                    i++;
                }
                else curDen = expression[i] - '0';
                sumNum += sign * lcm / curDen * curNum;
            }
            else {
                if (expression[i] == '1' && expression[i + 1] == '0') {
                    curNum = 10;
                    i++;
                }
                else curNum = expression[i] - '0';
            }
        }

        curDen = lcm;
        if (sumNum == 0) return "0/1";
        else {
            for (auto i = 9; i > 1; i--){
                while (sumNum % i == 0 && curDen % i == 0){
                    sumNum /= i;
                    curDen /= i;
                }
            }

            return to_string(sumNum) + "/" + to_string(curDen);
        }  
    }
};