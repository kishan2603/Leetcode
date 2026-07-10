class Solution {
public:
    vector<int> nums;
    int n;
    int f(int i,int target){
        if(i>=n) return target==0;
        return f(i+1,target+nums[i]) + f(i+1,target-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        n = nums.size();
        return f(0,target);
    }
};