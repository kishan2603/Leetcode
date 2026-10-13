class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int ele : nums) pq.push(abs(ele));
        int d = (n+1)/2;
        long long ans = 0;
        while(d--){
            int t = pq.top();
            pq.pop();
            ans += (1LL*t*t);
        }
        while(!pq.empty()){
            int t = pq.top();
            pq.pop();
            ans -= (1LL*t*t);
        }
        return ans; 
    }
};