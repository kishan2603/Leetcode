class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int j,vector<int>& prices){
        if(i>=prices.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==0) return dp[i][j] = max(f(i+1,j,prices),f(i+1,1,prices)-prices[i]);
        return dp[i][j] = max(f(i+1,j,prices),prices[i]+f(i+1,0,prices));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n,vector<int>(2,-1));
        return f(0,0,prices);
    }
};