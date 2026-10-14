class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(num*9 < sum) return "";
        int nines = sum/9;
        int rem = sum%9;
        ans += string(nines, '9');
        num -= nines;
        if(num>0){
            ans += to_string(rem);
            num--;
        }
        if(num>0) ans += string(num, '0');
        return ans;
    }
};