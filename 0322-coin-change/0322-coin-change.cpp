class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> dp;
    int f(int i,int target){
        if(target==0) return 0;
        if(i>=n || target<0) return 1e9;
        if(dp[i][target]!=-1) return dp[i][target];
        return dp[i][target] = min(f(i+1,target),1+f(i,target-nums[i]));
    }
    int coinChange(vector<int>& coins, int amount){
        n = coins.size();
        nums = coins;
        dp.resize(n,vector<int>(amount+1,-1));
        int result = f(0,amount);
        return (result!=1e9) ? result : -1;
    }
};