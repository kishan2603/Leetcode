class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int j,string& s, string& t){
        if(j>=t.size()) return s.size()-i;
        if(i>=s.size()) return t.size()-j;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = f(i+1,j+1,s,t);
        return dp[i][j] = 1 + min({f(i,j+1,s,t),f(i+1,j,s,t),f(i+1,j+1,s,t)});
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        dp.resize(m,vector<int>(n,-1));
        return f(0,0,word1,word2);
    }
};