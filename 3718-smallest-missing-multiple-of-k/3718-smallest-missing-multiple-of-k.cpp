class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = k;
        while(1){
            if(s.find(ans)!=s.end()) ans += k;
            else break;
        }
        return ans;
    }
};