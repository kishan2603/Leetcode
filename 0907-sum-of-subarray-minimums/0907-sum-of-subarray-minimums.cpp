class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]) s.pop();
            if(s.empty()) pse[i] = -1;
            else pse[i] = s.top();
            s.push(i);
        }
        s = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if(s.empty()) nse[i] = n;
            else nse[i] = s.top();
            s.push(i);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long left = i-pse[i];
            long long right = nse[i]-i;
            long long x = (left*right)%mod;
            long long p = (arr[i]*x)%mod;
            ans = (ans+p)%mod;
        }
        return (int)ans;
    }
};