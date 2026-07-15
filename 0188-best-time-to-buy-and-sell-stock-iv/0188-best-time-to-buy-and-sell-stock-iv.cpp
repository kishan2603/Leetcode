class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int i,int j,int k,vector<int>& prices){
        if(i>=prices.size()) return 0;
        if(k==0) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(j==0) return dp[i][j][k] = max(f(i+1,j,k,prices),f(i+1,1,k,prices)-prices[i]);
        return dp[i][j][k] = max(f(i+1,j,k,prices),f(i+1,0,k-1,prices)+prices[i]);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,0,k,prices);
    }
};