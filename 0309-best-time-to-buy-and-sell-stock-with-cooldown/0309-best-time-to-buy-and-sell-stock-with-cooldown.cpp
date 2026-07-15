class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int i, int j, int c,vector<int>& prices){
        if(i>=prices.size()) return 0;
        if(dp[i][j][c]!=-1) return dp[i][j][c];
        if(j==0 && c==1) return dp[i][j][c] = f(i+1,j,0,prices);
        else if(j==0 && c==0) return dp[i][j][c] = max(f(i+1,j,c,prices),f(i+1,1,c,prices)-prices[i]);
        return dp[i][j][c] = max(f(i+1,j,c,prices),f(i+1,0,1,prices)+prices[i]);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,0,0,prices);
    }
};