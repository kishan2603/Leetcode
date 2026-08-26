class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ones = 0;
        int ai = 0;
        int aj = 0;
        int length = INT_MAX;
        while(j<n){
            if(s[j]=='1') ones++;
            while(ones>=k){
                int currLength = j - i + 1;
                if(currLength < length ||
                    (currLength == length &&
                     s.substr(i, currLength) < s.substr(ai, length))){
                ai = i;
                aj = j;
                length = currLength;
                }
                if(s[i]=='1') ones--;
                i++;
            }
            j++;
        }
        if(length==INT_MAX) return "";
        return s.substr(ai,aj-ai+1);
    }
};