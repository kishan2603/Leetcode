class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        /*vector<int> pref(n,0);
        pref[0] = nums[0];
        for(int i=1;i<n;i++) pref[i] = pref[i-1] + nums[i];*/
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n && j-i+1<=r;j++){
                sum += nums[j];
                if(j-i+1>=l && sum>0) mini = min(mini,sum);
            }
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};