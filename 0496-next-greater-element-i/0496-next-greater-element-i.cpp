class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ng(n,0);
        ng[n-1] = -1;
        stack<int> s;
        s.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]) s.pop();
            if(s.empty()) ng[i] = -1;
            else ng[i] = s.top();
            s.push(nums2[i]);
        }
        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            int j;
            for(j=0;j<n;j++) if(nums1[i]==nums2[j]) break;
            result.push_back(ng[j]);
        }
        return result;
    }
};