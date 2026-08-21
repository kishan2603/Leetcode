class Solution {
public:
    void f(int i,string& s, string result,vector<string>& ans){
        if(i>=s.size()){
            ans.push_back(result);
            return;
        }
        if(isdigit(s[i])){
            f(i+1,s,result+string(1,s[i]),ans);
        }
        else{
            char c = s[i];
            f(i+1,s,result+string(1,tolower(c)),ans);
            f(i+1,s,result+string(1,toupper(c)),ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        f(0,s,"",ans);
        return ans;
    }
};