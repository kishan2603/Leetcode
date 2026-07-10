class Solution {
public:
    int n;
    vector<vector<int>> dp; 
    int f(vector<int>& coins,int target,int i){
        if(target==0) return 1;
        if(i>=n || target<0) return 0;
        if(dp[i][target]!=-1) return dp[i][target]; 
        return dp[i][target] = f(coins,target,i+1) + f(coins,target-coins[i],i);
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return f(coins,amount,0);
    }
};