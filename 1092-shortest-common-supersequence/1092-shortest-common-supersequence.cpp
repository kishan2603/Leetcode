class Solution {
public:
vector<vector<int>> dp;
    int f(int i,int j,string& str1, string& str2){
        if(i>=str1.size() || j>=str2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i]==str2[j]) return dp[i][j] = 1 + f(i+1,j+1,str1,str2);
        return dp[i][j] = max(f(i+1,j,str1,str2),f(i,j+1,str1,str2));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        dp.resize(m+1,vector<int>(n+1,-1));
        int x = f(0,0,str1,str2);
        for(int i=0;i<=m;i++) dp[i][n]=0;
        for(int i=0;i<=n;i++) dp[m][i]=0;
        string ans = "";
        int i = 0;
        int j = 0;
        while(i<m && j<n){
            if(str1[i]==str2[j]){
                ans += str1[i];
                i++;
                j++;
            }
            else{
                if(dp[i+1][j]>dp[i][j+1]){
                    ans+=str1[i];
                    i++;
                }
                else{
                    ans+=str2[j];
                    j++;
                }
            }
        }
        while(i<m){
            ans+=str1[i];
            i++;
        }
        while(j<n){
            ans+=str2[j];
            j++;
        }
        return ans;
    }
};