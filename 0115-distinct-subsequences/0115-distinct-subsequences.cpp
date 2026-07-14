class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int j,string& s, string& t){
        if(j>=t.size()) return 1;
        if(i>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = f(i+1,j+1,s,t)+f(i+1,j,s,t);
        return dp[i][j] = f(i+1,j,s,t);
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        dp.resize(m,vector<int>(n,-1));
        return f(0,0,s,t);
    }
};