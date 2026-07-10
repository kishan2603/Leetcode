class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> dp;
    int sum;
    int target;
    int f(int i,int curr){
        if(i>=n) return target==curr;
        if(dp[i][sum+curr]!=-1) return dp[i][sum+curr];
        return dp[i][sum+curr] = f(i+1,curr+nums[i]) + f(i+1,curr-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        n = nums.size();
        sum = 0;
        for(int a : nums) sum+=a;
        dp.resize(n,vector<int>(2*sum+1,-1));
        return f(0,0);
    }
};