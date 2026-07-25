class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int start = nums[0][0];
        int end = nums[0][1];
        for(int i=1;i<n;i++){
            if(nums[i][0]>end){
                result.push_back({start,end});
                start = nums[i][0];
                end = nums[i][1];
            }
            else{
                end = max(end,nums[i][1]);
            }
        }
        result.push_back({start,end});
        return result;
    }
};