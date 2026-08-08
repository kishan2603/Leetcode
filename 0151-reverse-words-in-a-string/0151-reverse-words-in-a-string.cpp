class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ') continue;
            else{
                string temp = "";
                while(i>=0 && s[i]!=' '){
                    temp += s[i];
                    i--; 
                }
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += " ";
            }
        }
        ans.pop_back();
        return ans;
    }
};