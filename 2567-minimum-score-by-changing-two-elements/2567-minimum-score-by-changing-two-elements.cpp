class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res1 = nums[n-1]-nums[2];
        int res2 = nums[n-3]-nums[0];
        int res3 = nums[n-2]-nums[1];
        return min({res1,res2,res3});
    }
};