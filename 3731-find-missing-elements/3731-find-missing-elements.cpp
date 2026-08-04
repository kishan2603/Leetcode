class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++) s.insert(nums[i]);
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> result;
        for(int i=mini;i<=maxi;i++){
            if(s.find(i)==s.end()) result.push_back(i);
        }
        return result;
    }
};