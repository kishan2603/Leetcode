class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s;
        string temp = "";
        for(int i=0;i<n/2;i++) temp+=s[i];
        sort(temp.begin(),temp.end());
        string temp2 = temp;
        if(n%2!=0) temp+=s[n/2];
        reverse(temp2.begin(),temp2.end());
        string result = temp + temp2;
        return result;
    }
};