class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ngi(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && temperatures[s.top()]<=temperatures[i]) s.pop();
            if(s.empty()) ngi[i] = -1;
            else ngi[i] = s.top();
            s.push(i);
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(ngi[i]==-1) ans[i] = 0;
            else{
                ans[i] = ngi[i] - i;
            }
        }
    return ans;
    }
};