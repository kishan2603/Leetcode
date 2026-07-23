class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ng(n);
        stack<int> s;
        for(int i=2*n-1;i>=0;i--){
            int idx = i%n;
            while(!s.empty() && s.top()<=nums[idx]) s.pop();
            if(idx<n){
                if(s.empty()) ng[idx] = -1;
                else ng[idx] = s.top();
            }
            s.push(nums[idx]);
        }
        return ng;
    }
};