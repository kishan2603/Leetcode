class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int i,int canbuy,vector<int>& prices,int trs){
        if(i>=prices.size()) return 0;
        if(trs==0) return 0;
        if(dp[i][canbuy][trs]!=-1) return dp[i][canbuy][trs];
        if(canbuy==0) return dp[i][canbuy][trs] = max(f(i+1,canbuy,prices,trs),f(i+1,1,prices,trs)-prices[i]);
        return dp[i][canbuy][trs] = max(f(i+1,canbuy,prices,trs),f(i+1,0,prices,trs-1)+prices[i]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,0,prices,2);
    }
};