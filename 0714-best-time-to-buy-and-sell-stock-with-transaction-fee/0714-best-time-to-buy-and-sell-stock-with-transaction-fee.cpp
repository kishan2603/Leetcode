class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int j,int fee,vector<int>& prices){
        if(i>=prices.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==0) return dp[i][j] = max(f(i+1,j,fee,prices),f(i+1,1,fee,prices)-prices[i]);
        return dp[i][j] = max(f(i+1,j,fee,prices),f(i+1,0,fee,prices)+prices[i]-fee);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.resize(n,vector<int>(2,-1));
        return f(0,0,fee,prices);
    }
};