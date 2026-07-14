class Solution {
public:
    vector<vector<int>> dp;
    bool check(int i, string& s){
        for(int j=i;j<s.size();j++) if(s[j]!='*') return false;
        return true;
    }
    bool f(int i,int j,string& s,string& p){
        if(i>=s.size() && j>=p.size()) return true;
        if(i<s.size() && j>=p.size()) return false;
        if(i>=s.size() && j<p.size()) return check(j,p);
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j]) return dp[i][j] = f(i+1,j+1,s,p);
        else if(p[j]=='?') return dp[i][j] = f(i+1,j+1,s,p);
        else if(p[j]=='*') return dp[i][j] = f(i,j+1,s,p) || f(i+1,j,s,p);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        dp.resize(m,vector<int>(n,-1));
        return f(0,0,s,p);
    }
};