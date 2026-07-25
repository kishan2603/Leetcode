class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = 0;
        for(int ele : s){
            if(s.find(ele-1)==s.end()){
                int curr = ele;
                int len = 1;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    len++;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};