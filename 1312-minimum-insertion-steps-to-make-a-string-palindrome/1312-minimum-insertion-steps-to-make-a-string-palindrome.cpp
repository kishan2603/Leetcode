class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int j,string& s,string& t){
        if(i>=s.size() || j>=t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = 1+f(i+1,j+1,s,t);
        return dp[i][j] = max(f(i+1,j,s,t),f(i,j+1,s,t));
    }
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(s.begin(),s.end());
        dp.resize(n,vector<int>(n,-1));
        int x = f(0,0,s,t);
        return n-x;
    }
};