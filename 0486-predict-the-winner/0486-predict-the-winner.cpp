class Solution {
public:
    int f(vector<int>& nums, int i, int j, bool one){
        if(i==j){
            if(one) return nums[i];
            return 0; 
        }
        if(one) return max(f(nums,i+1,j,!one)+nums[i],f(nums,i,j-1,!one)+nums[j]);
        else return min(f(nums,i+1,j,!one),f(nums,i,j-1,!one));
    }
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size()==1) return true;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int sum1 = f(nums,0,nums.size()-1,true);
        int sum2 = sum - sum1;
        if(sum1>=sum2) return true;
        return false;
    }
};