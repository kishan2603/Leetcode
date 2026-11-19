class Solution {
public:
    string sum (string t){
        int s = 0;
        for(char c : t) s += c-'0';
        return to_string(s);
    }
    string digitSum(string s, int k) {
        int n = s.size();
        if(n<=k) return s;
        int i = 0;
        string temp = "";
        while(s.size()>k){
            if(i+k<n){
                temp += sum(s.substr(i,k));
                i+=k;
            }
            else{
                temp += sum(s.substr(i));
                s = temp;
                i = 0;
                n = s.size();
                temp = "";
            }
        }
        return s;
    }
};