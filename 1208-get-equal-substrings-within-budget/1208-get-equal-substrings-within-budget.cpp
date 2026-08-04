class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int cost = 0;
        int i = 0;
        int j = 0;
        int length = 0;
        while(j<n){
            cost += abs(s[j]-t[j]);
            while(cost>maxCost){
                cost -= abs(s[i]-t[i]);
                i++;
            }
            length = max(length,j-i+1);
            j++;
        }
        length = max(length,j-i);
        return length;
    }
};